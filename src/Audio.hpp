#pragma once
#include <SDL_mixer.h>
#include <map>

class Audio {
public:
  enum class AudioTypeEnum {
    AUDIO_DISK = 0,
    AUDIO_JUMP = 1,
    AUDIO_DING = 2,
    AUDIO_CRACK = 3,
    AUDIO_STOMP = 4,
    AUDIO_KILLED = 5,
    AUDIO_GOTPOWERUP = 6,
    AUDIO_PORTAL = 7,
    AUDIO_CLICK = 8,
    AUDIO_SHOOT = 9
  };

  enum class MusicTypeEnum {
    MUSIC_MENU = 0,
    MUSIC_OUTDOORS = 1,
    MUSIC_INDOORS = 2,
    MUSIC_HIGHSCORE = 3
  };

  Audio();
  ~Audio();
  static void initAudioSystem();
  static void playMusic(Audio::MusicTypeEnum type);
  static void playSound(Audio::AudioTypeEnum type);
  static void setMusicVolume(int percentage, bool showVolumeOverlay);
  static void setSoundEffectsVolume(int percentage, bool showVolumeOverlay);
  static int getMusicVolume();
  static int getSoundEffectVolume();

private:
  struct Sound {
    std::string fileName;
    Mix_Chunk *chunk;
  };
  struct Music {
    std::string fileName;
    Mix_Music *music;
  };

  static std::map<Audio::AudioTypeEnum, Audio::Sound> sound_map;
  static std::map<Audio::MusicTypeEnum, Audio::Music> music_map;

  static int music_volume; // extern int VolumePercentage_Music;
  static int sound_volume; // extern int VolumePercentage_Sound;
};

// ##############################################
// ##############################################
// ##############################################
extern int VolumePercentage_Music;
extern int VolumePercentage_Sound;
extern int ShowVolume_Music;
extern int ShowVolume_Sound;
