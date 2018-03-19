/*
	Module:  AbstractTank.cpp
	Purpose: Implementation of the class AbstractTank
*/

#include "Definitions.h"
#include "AbstractTank.h"
#include "Setup.h"

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
void AbstractTank::Setmodel(int d)
{
	char center = 254, high = 219, top = 223, bot = 220;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			model[i][j] = ' ';
	if (d == 0 || d == 4)
	{
		model[0][1] = bot;
		model[0][2] = bot;
		model[1][0] = top;
		model[1][1] = high;
		model[1][2] = bot;
	}
	else
	{
		if (d == 3)
		{
			model[0][0] = bot;
			model[0][1] = bot;
			model[1][0] = bot;
			model[1][1] = high;
			model[1][2] = top;
		}	
		else
		{
			if (d == 2)
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
		case 1: { dir = DOWN; break; }
		case 2: { dir = UP; break; }
		case 3: { dir = LEFT; break; }
		case 4: { dir = RIGHT; break; }
		default: break;
	}
}

// Tank's moving implementation
int AbstractTank::Move()
{
	if(xPos < 35 && xPos > 0 && yPos < 16 && yPos > 0)
	{
		using namespace std::this_thread; // sleep_for, sleep_until
		using namespace std::chrono; // nanoseconds, system_clock, seconds

		switch (dir) 
		{
			case UP: yPos++;
				sleep_for(nanoseconds(500000000));
				break;
			case DOWN: yPos--;
				sleep_for(nanoseconds(500000000));
				break;
			case RIGHT: xPos++;
				sleep_for(nanoseconds(250000000));
				break;
			case LEFT: xPos--;
				sleep_for(nanoseconds(250000000));
				break;
			default: break;
		}
	}
	else
	{
		Setup& s = Setup::SetupInstance();
		if (!(xPos < 35))
		{
			s.Setmap(186, xPos + 3, yPos + 0);
			s.Setmap(186, xPos + 3, yPos + 1);
			xPos--;
			Setdir(0);
		}
		if (!(xPos > 0))
		{
			s.Setmap(186, xPos - 1, yPos);
			s.Setmap(186, xPos - 1, yPos + 1);
			xPos++;
			Setdir(0);
		}
		if (!(yPos < 16))
		{
			s.Setmap(205, xPos, yPos + 2);
			s.Setmap(205, xPos + 1, yPos + 2);
			s.Setmap(205, xPos + 2, yPos + 2);
			yPos--;
			Setdir(0);
		}
		if (!(yPos > 0))
		{
			s.Setmap(205, xPos, yPos - 1);
			s.Setmap(205, xPos + 1, yPos - 1);
			s.Setmap(205, xPos + 2, yPos - 1);
			yPos++;
			Setdir(0);
		}
		Setdir(0);
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