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
	score = 0;
}
// Destructor
TankPlayer::~TankPlayer()
{}

// Accessors
int TankPlayer::Getscore()
{
	return score;
}
void TankPlayer::Setscore(int Score)
{
	score = Score;
}