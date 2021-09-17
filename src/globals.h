
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <string.h>
#include <cmath>
#include <stdio.h>      // include ability to read/write files
#include <dirent.h>     // NEEDED TO CHECK EXISTENCE OF DIRECTORIES
#include <iostream>
#include <stdlib.h>     // srand
#include <time.h>

#include "Audio.hpp"
#include "CONTENT_Stages.h"
#include "CONTENT_Player.h"
#include "CONTENT_Tiles_and_Sprites.h"
#include "CONTENT_Enemies.h"
#include "GameEnvironment.hpp" 
#include "INTERFACE.h"
#include "LOOPS.h"
#include "SYSTEM.h"
#include "SYSTEM_SDL.h"
#include "SYSTEM_SDL_Input.h"


void Animation();
void drawGround(int Colour);


// ##############################################
// ##############################################
// ##############################################
