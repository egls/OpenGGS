#include "globals.h"
#include "spdlog/spdlog.h"
constexpr static int CHANNELS = 8;
constexpr static int INITIAL_VOLUME = 25;

std::map<Audio::AudioTypeEnum, Audio::Sound> Audio::sound_map{};
std::map<Audio::MusicTypeEnum, Audio::Music> Audio::music_map{};
int Audio::music_volume = 0;
int Audio::sound_volume = 0;

//-----------------------------------------------------------------------------
// Audio constructor
//-----------------------------------------------------------------------------
Audio::Audio() { spdlog::trace("Audio::ctor()"); }

Audio::~Audio() {
  spdlog::trace("Audio::dtor()");

  // close the audio mixer
  Mix_CloseAudio();
}
//-----------------------------------------------------------------------------
// Initialize Audio Subsystem
//-----------------------------------------------------------------------------
void Audio::initAudioSystem() {
  spdlog::trace("Audio::initAudioSystem()");
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_DISK,
                    Sound{"base/audio/disk.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_JUMP,
                    Sound{"base/audio/jump.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_STOMP,
                    Sound{"base/audio/stomp.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_KILLED,
                    Sound{"base/audio/died.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_DING,
                    Sound{"base/audio/ding.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_CLICK,
                    Sound{"base/audio/click.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_GOTPOWERUP,
                    Sound{"base/audio/morphing.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_SHOOT,
                    Sound{"base/audio/shoot.wav", nullptr});
  sound_map.emplace(Audio::AudioTypeEnum::AUDIO_CRACK,
                    Sound{"base/audio/crack.wav", nullptr});

  music_map.emplace(Audio::MusicTypeEnum::MUSIC_MENU,
                    Music{"base/music/title.it", nullptr});
  music_map.emplace(Audio::MusicTypeEnum::MUSIC_OUTDOORS,
                    Music{"base/music/outdoors.it", nullptr});
  music_map.emplace(Audio::MusicTypeEnum::MUSIC_INDOORS,
                    Music{"base/music/indoors.it", nullptr});

  // Open mixer with a defined audio format
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  // Allocate number of mixing channels
  Mix_AllocateChannels(CHANNELS);

  // Set initial volume for sound effects and music
  setMusicVolume(INITIAL_VOLUME, false);
  setSoundEffectsVolume(INITIAL_VOLUME, false);

  auto mix_free_chunk = [&](Audio::AudioTypeEnum type) {
    auto &sound = sound_map.at(type);
    Mix_FreeChunk(sound.chunk);
    sound.chunk = nullptr;
    sound.chunk = Mix_LoadWAV(sound.fileName.c_str());
  };

  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_DISK);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_JUMP);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_STOMP);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_KILLED);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_DING);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_CLICK);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_GOTPOWERUP);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_SHOOT);
  mix_free_chunk(Audio::AudioTypeEnum::AUDIO_CRACK);

  auto mix_free_music = [&](Audio::MusicTypeEnum type) {
    auto &music = music_map.at(type);
    Mix_FreeMusic(music.music);
    music.music = nullptr;
    music.music = Mix_LoadMUS(music.fileName.c_str());
  };
  mix_free_music(Audio::MusicTypeEnum::MUSIC_MENU);
  mix_free_music(Audio::MusicTypeEnum::MUSIC_OUTDOORS);
  mix_free_music(Audio::MusicTypeEnum::MUSIC_INDOORS);
}

void Audio::setMusicVolume(int percentage, bool showVolumeOverlay) {
  spdlog::trace(
      "Audio::initAudioSystem(), percentage: {}, showVolumeOverlay: {}",
      percentage, showVolumeOverlay);
  int Value128 = 0;

  // check and set lower bounds
  if (percentage < 1) {
    Value128 = 0;
    percentage = 0;
  }

  // check and set upper bounds
  if (percentage > 99) {
    Value128 = 128;
    percentage = 100;
  }

  if (percentage > 0 && percentage < 100) {
    Value128 = static_cast<int>(128 * percentage / 100);
  }

  VolumePercentage_Music = percentage;
  GV.VolumeMusic = Value128 / 4; // GameVariables.VolumeMusic
  Mix_VolumeMusic(GV.VolumeMusic);

  if (showVolumeOverlay) {
    ShowVolume_Music = 3;
  }
}

/* From Mix_VolumeMusix: Set the volume in the range of 0-128 of a specific
   channel or chunk. If the specified channel is -1, set volume for all
   channels. Returns the original volume. If the specified volume is -1, just
   return the current volume.
*/
void Audio::setSoundEffectsVolume(int percentage, bool showVolumeOverlay) {
  spdlog::trace(
      "Audio::setSoundEffectsVolume(), percentage: {}, showVolumeOverlay: {}",
      percentage, showVolumeOverlay);
  int Value128 = 0;
  // VOLUME OF SAMPLES
  if (percentage < 1) {
    Value128 = 0;
    percentage = 0;
  }

  if (percentage > 99) {
    Value128 = 128;
    percentage = 100;
  }

  if (percentage > 0 && percentage < 100) {
    Value128 = (int)(128 * percentage / 100);
  }

  VolumePercentage_Sound = percentage;
  GV.VolumeSounds = Value128;
  Mix_Volume(-1, GV.VolumeSounds);

  if (showVolumeOverlay) {
    ShowVolume_Sound = 3;
  }
}

void Audio::playSound(Audio::AudioTypeEnum type) {
  spdlog::trace("Audio::playSound(), AudioTypeEnum: {}", type);
  if (GV.VolumeSounds > 0) {
    Mix_PlayChannel(-1, sound_map.at(type).chunk, 0);
  }

  if (type == Audio::AudioTypeEnum::AUDIO_GOTPOWERUP) {
    GV.TempMusicVolume = GV.VolumeMusic;
    GV.VolumeMusic = 0;
    GV.TempMusicOffCounter = 1000;
    Mix_VolumeMusic(GV.VolumeMusic);
  }
}

void Audio::playMusic(Audio::MusicTypeEnum type) {
  spdlog::trace("Audio::playMusic(), AudioTypeEnum: {}", type);
  if (GV.VolumeMusic > 0 && GV.MusicEnabled) {
    Mix_PlayMusic(music_map.at(type).music, -1);
    // if(MusicNumber == MUSIC_HIGHSCORE)
    // {Mix_PlayMusic(BackgroundMusic[MUSIC_HIGHSCORE],-1);}
  }
}

int Audio::getMusicVolume() { return music_volume; }
int Audio::getSoundEffectVolume() { return sound_volume; }

int VolumePercentage_Music;
int VolumePercentage_Sound;
int ShowVolume_Music;
int ShowVolume_Sound;
