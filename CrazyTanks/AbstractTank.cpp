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

// Accessors
int AbstractTank::GetxPos()
{
	return xPos;
}
void AbstractTank::SetxPos(int XPos)
{
	xPos = XPos;
}
int AbstractTank::GetyPos()
{
	return yPos;
}
void AbstractTank::SetyPos(int YPos)
{
	yPos = YPos;
}
int AbstractTank::Gethp()
{
	return hp;
}
void AbstractTank::Sethp(int Hp)
{
	hp = Hp;
}
string AbstractTank::Getmodel()
{
	return model;
}
void AbstractTank::Setmodel(string Model)
{
	model = Model;
}
string AbstractTank::Gethitbox()
{
	return hitbox;
}
void AbstractTank::Sethitbox(string Hitbox)
{
	hitbox = Hitbox;
}
string AbstractTank::Getcolor()
{
	return color;
}
void AbstractTank::SetColor(string Color)
{
	color = Color;
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