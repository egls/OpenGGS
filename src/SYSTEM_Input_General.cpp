#include "globals.h"

// ##############################################
// ##############################################
// ##############################################

void INPUT_General()
{
  // CLICK ON "X" CLOSES PROGRAM
  if (e.type == SDL_QUIT)
  {
    QuitProgram = true;
  }

  // CHANGE VOLUME OF MUSIC

  if (Key_PAGEUP_pressed)
  {
    Audio::setMusicVolume(VolumePercentage_Music += 10, true); // TODO: Audio::increaseMusicVolume(int val)
    Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
  }
  if (Key_PAGEDOWN_pressed)
  {
    Audio::setMusicVolume(VolumePercentage_Music -= 10, true);
    Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
  }

  if (Key_PLUS_pressed)
  {
    Audio::setSoundEffectsVolume(VolumePercentage_Sound += 10, true);
    Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
  }
  if (Key_MINUS_pressed)
  {
    Audio::setSoundEffectsVolume(VolumePercentage_Sound -= 10, true);
    Audio::playSound(Audio::AudioTypeEnum::AUDIO_CLICK);
  }

  // TOGGLE WINDOWED/FULLSCREEN
  if (Key_LALT && Key_ENTER_pressed)
  {
    toggleScreenmode();
  }
}
