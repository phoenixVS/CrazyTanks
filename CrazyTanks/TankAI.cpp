/*
	Module:  TankAI.cpp
	Purpose: Implementation of the class TankAI
*/

#include "Definitions.h"
#include "TankAI.h"

// Default constructor
TankAI::TankAI() : AbstractTank()
{
	xPos = rand()%36;
	yPos = rand()%16;
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