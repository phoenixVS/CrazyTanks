/*
	Module:  TankAI.cpp
	Purpose: Implementation of the class TankAI
*/

#include "Definitions.h"
#include "TankAI.h"

// Default constructor
TankAI::TankAI() : AbstractTank()
{
	xPos = rand()%35 + 1;
	yPos = rand()%15 + 1;
	hp = 1;
	color = "red";
}
// Destructor
TankAI::~TankAI()
{

}

// AI behaviour logic implementation
int TankAI::Logic()
{
	// TODO : implement
	return 0;
}