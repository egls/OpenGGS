#include "globals.h"
#include "GameEnvironment.hpp"
// ##############################################
// ##############################################
// ##############################################

void PC_Jump()
{
  // START THE JUMP
  if(PC.JumpOnGoing && (PC.OnGround || PC.OnGroundDelay > 0))
  {
    PC.JumpVelocity = PC.JumpStrength;  // COULD BE MADE DEPENDENT ON WALKINGSPEED
    PC.OnGround = false;
    PC.OnGroundDelay = 0;
    Audio::playSound(Audio::AudioTypeEnum::AUDIO_JUMP);
  }
  // START THE JUMP

}

// ##############################################
// ##############################################
// ##############################################

void PC_Gravity()
{

  // ADD GRAVITY
  PC.JumpVelocity -= GameEnvironment::getWorld().Gravity;
  if(PC.JumpVelocity < -GameEnvironment::getWorld().TerminalVelocity){PC.JumpVelocity = -GameEnvironment::getWorld().TerminalVelocity;}

  //PC.PosY -= int(PC.JumpVelocity/2);
  PC.MovementVertical = int(PC.JumpVelocity/2);

  // FALLING DOWN HAS TO BE PIXEL PERFECT
  if(!PC.Dead && PC.MovementVertical < 0)
  {
    while(PC.MovementVertical != 0)
    {
      PC.MovementVertical++;
      if(!PC.OnGround){PC.PosY++;PC_Check_Tilecollision(); }

    }
  }

  // JUMPING UP
  if(!PC.Dead && PC.MovementVertical > 0)
  {
    PC.PosY  -= int(PC.JumpVelocity/2);
  }

  // WHEN OUTSIDE OF TOP OF SCREEN
  if(PC.PosY < 0)
  {
    PC.PosY  -= int(PC.JumpVelocity/2);
  }

  // WALLGRINDING = SLOWER DESCENDING
  //if(PC.JumpVelocity < -World.WallFriction && PC.WallGrinding){PC.JumpVelocity = -World.WallFriction;}

  // KEY_DOWN = FASTER DESCENDING
  if(Key_DOWN){PC.JumpVelocity = -GameEnvironment::getWorld().TerminalVelocity;}

  // SLOW DOWN UPWARD MOMENTUM IF JUMP BUTTON IS RELEASED
  if(!PC.Dead && !Unified.Jump && PC.JumpVelocity>0){PC.JumpVelocity -= 4 * GameEnvironment::getWorld().Gravity;}

  if(PC.Dead)
  {
    PC.PosY -= int(PC.JumpVelocity/2);
    if(PC.JumpVelocity>0)
    {
      PC.JumpVelocity -= 4 * GameEnvironment::getWorld().Gravity;
    }
  }


}

// ##############################################
// ##############################################
// ##############################################
