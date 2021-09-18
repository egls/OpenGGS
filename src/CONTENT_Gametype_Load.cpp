#include "globals.h"
Def_FileNames FileName;

// ##############################################
// ##############################################
// ##############################################

void GAMETYPE_Load()
{

  // CHECK IF NECESSARY DIRECTORIES EXIST
  DIR  *dip;
  if ((dip = opendir("base/c64")) != NULL){closedir(dip); GV.DirC64Exists = true;}
  if ((dip = opendir("base/default")) != NULL){closedir(dip); GV.DirDefaultExists = true;}
  if ((dip = opendir("base/amiga")) != NULL){closedir(dip); GV.DirAmigaExists = true;}
  // IF DIRECTORIES DON'T EXIST, FALL BACK ONTO DEFAULT LAYOUT
  if(GV.GameType == TYPE_AMIGA && !GV.DirAmigaExists){GV.GameType = TYPE_C64;}
  if(GV.GameType == TYPE_C64 && !GV.DirC64Exists){GV.GameType = TYPE_OPENGGS;}
  if(GV.GameType == TYPE_OPENGGS && !GV.DirDefaultExists){GV.GameType = TYPE_C64;}

  // // egls commented out, not sure it is needed
  // snprintf(FileName.Stage[0], sizeof(char) * 128, "base/stages/classic.lvl");

  // snprintf(FileName.Stage[0], sizeof(char) * 128, FileName.Stage[2]);

  snprintf(FileName.Tiles, sizeof(char) * 128, "base/default/Tiles.png");
  snprintf(FileName.Player, sizeof(char) * 128, "base/default/Player.png");
  snprintf(FileName.PlayerDefinition, sizeof(char) * 128, "base/default/Player.txt");
  snprintf(FileName.Enemies, sizeof(char) * 128, "base/default/Enemies.png");
  snprintf(FileName.EnemiesDefinition, sizeof(char) * 128, "base/default/Enemies.txt");
  snprintf(FileName.PowerUp, sizeof(char) * 128, "base/default/PowerUp.png");
  snprintf(FileName.PowerUpDefinition, sizeof(char) * 128, "base/default/PowerUp.txt");
  snprintf(FileName.Interface, sizeof(char) * 128, "base/Interface.png");
  snprintf(FileName.Font, sizeof(char) * 128, "base/Font.png");

  if(GV.GameType == TYPE_C64 && GV.DirC64Exists)
  {
    snprintf(FileName.Tiles, sizeof(char) * 128, "base/c64/Tiles.png");
    snprintf(FileName.Player, sizeof(char) * 128, "base/c64/Player.png");
    snprintf(FileName.PlayerDefinition, sizeof(char) * 128, "base/c64/Player.txt");
    snprintf(FileName.Enemies, sizeof(char) * 128, "base/c64/Enemies.png");
    snprintf(FileName.EnemiesDefinition, sizeof(char) * 128, "base/c64/Enemies.txt");
    snprintf(FileName.PowerUp, sizeof(char) * 128, "base/c64/PowerUp.png");
    snprintf(FileName.PowerUpDefinition, sizeof(char) * 128, "base/c64/PowerUp.txt");
  }

  if(GV.GameType == TYPE_OPENGGS && GV.DirDefaultExists)
  {
    snprintf(FileName.Tiles, sizeof(char) * 128, "base/default/Tiles.png");
    snprintf(FileName.Player, sizeof(char) * 128, "base/default/Player.png");
    snprintf(FileName.PlayerDefinition, sizeof(char) * 128, "base/default/Player.txt");
    snprintf(FileName.Enemies, sizeof(char) * 128, "base/default/Enemies.png");
    snprintf(FileName.EnemiesDefinition, sizeof(char) * 128, "base/default/Enemies.txt");
    snprintf(FileName.PowerUp, sizeof(char) * 128, "base/default/PowerUp.png");
    snprintf(FileName.PowerUpDefinition, sizeof(char) * 128, "base/default/PowerUp.txt");
  }

  if(GV.GameType == TYPE_AMIGA && GV.DirAmigaExists)
  {
    snprintf(FileName.Tiles, sizeof(char) * 128, "base/amiga/Tiles.png");
    snprintf(FileName.Player, sizeof(char) * 128, "base/amiga/Player.png");
    snprintf(FileName.PlayerDefinition, sizeof(char) * 128, "base/amiga/Player.txt");
    snprintf(FileName.Enemies, sizeof(char) * 128, "base/amiga/Enemies.png");
    snprintf(FileName.EnemiesDefinition, sizeof(char) * 128, "base/amiga/Enemies.txt");
    snprintf(FileName.PowerUp, sizeof(char) * 128, "base/amiga/PowerUp.png");
    snprintf(FileName.PowerUpDefinition, sizeof(char) * 128, "base/amiga/PowerUp.txt");
  }
  Audio::initAudioSystem();
  Options_Load();

  loadTextures();

  TILES_Define();
  ENEMIES_Define();
  SPRITES_Define();
  PC_Define();
  TileSheet_Load();



  STAGES_Import_RANDOM_Modules();
  STAGES_Import();
}

// ##############################################
// ##############################################
// ##############################################
