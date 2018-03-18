/*
	Module:  AbstractTank.cpp
	Purpose: Implementation of the class AbstractTank
*/

#include "Definitions.h"
#include "AbstractTank.h"

// Default constructor
AbstractTank::AbstractTank() : xPos(0), yPos(0), hp(0), model(""), hitbox(""), color("")
{

}
// Destructor
AbstractTank::~AbstractTank()
{

}

// Tank's moving implementation
int AbstractTank::Move()
{
	// TODO : implement
	return 0;
}

// Tank's shooting implementation
int AbstractTank::Shoot()
{
	// TODO : implement
	return 0;
}

// Tank is getting damage
int AbstractTank::Hit()
{
	// TODO : implement
	return 0;
}

// Tank missed
int AbstractTank::Miss()
{
	// TODO : implement
	return 0;
}