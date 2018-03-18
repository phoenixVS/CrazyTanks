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
	char luc = 201, ruc = 187, lbc = 200, rbc = 188, hwall = 205, vwall = 186;
	cout << luc;
	for (int i = 0; i < mapWidth-2; i++)
	{
		cout << hwall;
	}
	cout << ruc << endl;
	for (int i = 0; i < mapWidth - 2; i++)
	{
		cout << vwall;
		for (int j = 0; j < mapWidth - 2; j++)
		{
			cout << " ";
		}
		cout << vwall << endl;
	}
	cout << lbc;
	for (int i = 0; i < mapWidth - 2; i++)
	{
		cout << hwall;
	}
	cout << rbc << endl;
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
	char hp1 = 178, hp2 = 176;
	if (ptank.Gethp() == 3)
	{
		cout << hp1 << hp1 << hp1 << endl;
	}
	else
	{
		if (ptank.Gethp() == 2)
		{
			cout << hp1 << hp1 << hp2 << endl;
		}
		else
			cout << hp1 << hp2 << hp2 << endl;
	}
	return 0;
}

// Output player's score 
int Setup::DrawScore(TankPlayer& ptank)
{
	cout << "Score : " << ptank.Getscore() << endl;
	return 0;
}