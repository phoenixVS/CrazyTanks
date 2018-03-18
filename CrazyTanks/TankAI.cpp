/*
	Module:  TankAI.cpp
	Purpose: Implementation of the class TankAI
*/

#include "Definitions.h"
#include "TankAI.h"

// Default constructor
TankAI::TankAI() : AbstractTank()
{
	xPos = 20;
	yPos = 10;
	hp = 1;
	model = "";
	hitbox = "";
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