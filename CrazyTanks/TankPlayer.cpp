#include "Definitions.h"
#include "Setup.h"
#include "AbstractTank.h"
#include "TankPlayer.h"

// Default constructor
TankPlayer::TankPlayer() : AbstractTank()
{
	Setup& s = Setup::SetupInstance();
	xPos = s.GetmapWidth() / 2;
	yPos = s.GetmapHeight() / 2;
	hp = 3;
	color = "white";
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