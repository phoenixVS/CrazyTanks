/*
	Module:  AbstractTank.cpp
	Purpose: Implementation of the class AbstractTank
*/

#include "Definitions.h"
#include "AbstractTank.h"

// Default constructor
AbstractTank::AbstractTank() : xPos(0), yPos(0), hp(0), color("black")
{
	Setmodel(STOP);
}
// Destructor
AbstractTank::~AbstractTank()
{}

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
char AbstractTank::Getmodel(int i, int j)
{
	return model[i][j];
}
void AbstractTank::Setmodel(direction dir)
{
	char center = 254, high = 219, top = 223, bot = 220;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			model[i][j] = ' ';
	if (dir == STOP || dir == LEFT)
	{
		model[0][1] = bot;
		model[0][2] = bot;
		model[1][0] = top;
		model[1][1] = high;
		model[1][2] = bot;
	}
	else
	{
		if (dir == RIGHT)
		{
			model[0][0] = bot;
			model[0][1] = bot;
			model[1][0] = bot;
			model[1][1] = high;
			model[1][2] = top;
		}	
		else
		{
			if (dir == UP)
			{
				model[0][1] = bot;
				model[1][0] = high;
				model[1][1] = top;
				model[1][2] = high;
			}
			else
			{
				model[0][0] = bot;
				model[0][2] = bot;
				model[1][0] = top;
				model[1][1] = high;
				model[1][2] = top;
			}
		}
	}
}
int AbstractTank::Gethitbox(int i, int j)
{
	return hitbox[i][j];
}
void AbstractTank::Sethitbox(direction dir)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			hitbox[i][j] = 1;
	
}
string AbstractTank::Getcolor()
{
	return color;
}
void AbstractTank::SetColor(string Color)
{
	color = Color;
}
int AbstractTank::Getdir()
{
	return dir;
}
void AbstractTank::Setdir(int Dir)
{
	switch (Dir) 
	{
		case 0: { dir = STOP; break; }
		case 1: { dir = LEFT; break; }
		case 2: { dir = RIGHT; break; }
		case 3: { dir = RIGHT; break; }
		case 4: { dir = DOWN; break; }
	}
}

// Tank's moving implementation
int AbstractTank::Move()
{
	if(xPos < 35 && yPos < 16)
	{
	switch (dir) 
	{
	case UP: yPos++;
		break;
	case DOWN: yPos--;
		break;
	case RIGHT: xPos++;
		break;
	case LEFT: yPos--;
		break;
	}
	}
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