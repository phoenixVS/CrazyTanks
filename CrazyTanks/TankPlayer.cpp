#include "Definitions.h"
#include "AbstractTank.h"
#include "TankPlayer.h"

// Default constructor
TankPlayer::TankPlayer() : AbstractTank()
{
	xPos = 20;
	yPos = 10;
	hp = 3;
	model = ""; 
	hitbox = "";
	color = "blue";
}
// Destructor
TankPlayer::~TankPlayer()
{

}