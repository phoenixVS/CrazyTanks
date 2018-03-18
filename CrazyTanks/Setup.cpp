/*
	Module:  Setup.cpp
	Purpose: Implementation of the class Setup
*/

#include "Definitions.h"
#include "Setup.h"
#include "AbstractTank.h"
#include "TankPlayer.h"

// Singleton
Setup& Setup::SetupInstance()
{
	static Setup s;
	return s;
}
// Constructor
Setup::Setup() : stop(0), mapWidth(40), mapHeight(20), playTime(0)
{}
// Destructor
Setup::~Setup()
{}

// Accessors
bool Setup::Getstop()
{
	return stop;
}
void Setup::Setstop(bool Stop)
{
	stop = Stop;
}
int Setup::GetmapHeight()
{
	return mapHeight;
}
void Setup::SetmapHeight(int MapHeight)
{
	mapHeight = MapHeight;
}
int Setup::GetmapWidth()
{
	return mapWidth;
}
void Setup::SetmapWidth(int MapWidth)
{
	mapWidth = MapWidth;
}
int Setup::GetplayTime()
{
	return playTime;
}
void Setup::SetplayTime(int PlayTime)
{
	playTime = PlayTime;
}


// Drawing a map
int Setup::DrawMap()
{
	
	return 0;
}

// Starting a game
int Setup::GameStart()
{
	system("cls");
	return 0;
}

// Game ending (loose)
int Setup::GameOver()
{
	system("cls");
	cout << "Game over" << endl;
	return 0;
}

// Game ending (victory)
int Setup::Victory()
{
	system("cls");
	cout << "You win!!!" << endl;
	return 0;
}

// Restarting the game
int Setup::Restart()
{
	GameStart();
	return 0;
}

// Output game time
int Setup::DrawTime(time_t start)
{
	time_t counter;
	int min = 0, sec = 0;
	counter = time(NULL);
	cout << "Time : ";
	if (counter - start > 59)
		min = (counter - start) % 60;
	sec = counter - start - min * 60;
	cout << min << " : " <<  sec << " seconds" << endl;
	return 0;
}

// Output player's Health Points
int Setup::DrawHp(AbstractTank& ptank)
{
	cout << "HP left : ";
	char hpBlock = 178;
	if (ptank.Gethp() == 3)
	{
		cout << hpBlock << hpBlock << hpBlock << endl;
	}
	else
	{
		if (ptank.Gethp() == 2)
		{
			cout << hpBlock << hpBlock << endl;
		}
		else
			cout << hpBlock << endl;
	}
	return 0;
}

// Output player's score 
int Setup::DrawScore(TankPlayer& ptank)
{
	cout << "Score : " << ptank.Getscore() << endl;
	return 0;
}