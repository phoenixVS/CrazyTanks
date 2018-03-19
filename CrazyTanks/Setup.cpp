/*
	Module:  Setup.cpp
	Purpose: Implementation of the class Setup
*/

#include "Definitions.h"
#include "Setup.h"
#include "AbstractTank.h"
#include "TankAI.h"
#include "TankPlayer.h"

// Singleton
Setup& Setup::SetupInstance()
{
	static Setup s;
	return s;
}
// Constructor
Setup::Setup() : mapHeight(20), mapWidth(40), playTime(0)
{}
// Destructor
Setup::~Setup()
{}

// Accessors
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
void Setup::Setmap(char ch, int i, int j)
{
	map[i][j] = ch;
}
// Empty map genering (with walls)
int Setup::GenerateMap()
{
	srand(time(NULL));
	char luc = 201, ruc = 187, lbc = 200, rbc = 188, hwall = 205, vwall = 186;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 40; j++)
			map[i][j] = ' ';
	for (int i = 0; i < mapWidth; i++)
	{
		map[0][i] = hwall;
	}
	for (int i = 0; i < mapHeight; i++)
	{
		map[i][0] = vwall;
		map[i][mapWidth-1] = vwall;		
	}
	for (int i = 0; i < mapWidth; i++)
	{
		map[mapHeight-1][i] = hwall;
	}
	map[0][0] = luc;
	map[0][mapWidth - 1] = ruc;
	map[mapHeight - 1][0] = lbc;
	map[mapHeight - 1][mapWidth - 1] = rbc;
	
	// Walls 1 x 2
	int wone1x2[2][2], wtwo1x2[2][2], wthree1x2[2][2];
	wone1x2[0][0] = rand() % 15 + 1;
	wone1x2[0][1] = rand() % 35 + 1;
	wone1x2[1][0] = wone1x2[0][0] + 1;
	wone1x2[1][1] = wone1x2[0][1];
	map[wone1x2[0][0]][wone1x2[0][1]] = vwall;
	map[wone1x2[1][0]][wone1x2[1][1]] = vwall;

	wtwo1x2[0][0] = rand() % 16 + 1;
	wtwo1x2[0][1] = rand() % 36 + 1;
	wtwo1x2[1][0] = wtwo1x2[0][0];
	wtwo1x2[1][1] = wtwo1x2[0][1] -1;
	map[wtwo1x2[0][0]][wtwo1x2[0][1]] = hwall;
	map[wtwo1x2[1][0]][wtwo1x2[1][1]] = hwall;

	wthree1x2[0][0] = rand() % 15 + 1;
	wthree1x2[0][1] = rand() % 35 + 1;
	wthree1x2[1][0] = wthree1x2[0][0];
	wthree1x2[1][1] = wthree1x2[0][1] + 1;
	map[wthree1x2[0][0]][wthree1x2[0][1]] = hwall;
	map[wthree1x2[1][0]][wthree1x2[1][1]] = hwall;
	
	// Wall 1 x 3
	int w1x3[3][2];
	w1x3[0][0] = rand() % 15 + 1;
	w1x3[0][1] = rand() % 35 + 1;
	w1x3[1][0] = w1x3[0][0];
	w1x3[1][1] = w1x3[0][1] + 1;
	w1x3[2][0] = w1x3[0][0];
	w1x3[2][1] = w1x3[0][1] + 2;
	map[w1x3[0][0]][w1x3[0][1]] = hwall;
	map[w1x3[1][0]][w1x3[1][1]] = hwall;
	map[w1x3[2][0]][w1x3[2][1]] = hwall;
	return 0;
};

// Placing players on map
int Setup::PlayersPlacing(AbstractTank& ptank, AbstractTank& en1, AbstractTank& en2)
{
	// Player placing

	map[ptank.GetyPos()][ptank.GetxPos()] = ptank.Getmodel(0, 0);
	map[ptank.GetyPos()][ptank.GetxPos() + 1] = ptank.Getmodel(0, 1);
	map[ptank.GetyPos()][ptank.GetxPos() + 2] = ptank.Getmodel(0, 2);

	map[ptank.GetyPos() + 1][ptank.GetxPos()] = ptank.Getmodel(1, 0);
	map[ptank.GetyPos() + 1][ptank.GetxPos() + 1] = ptank.Getmodel(1, 1);
	map[ptank.GetyPos() + 1][ptank.GetxPos() + 2] = ptank.Getmodel(1, 2);

	// cleaning track
	switch (ptank.Getdir())
	{
		case 1: 
		{   
			map[ptank.GetyPos()-1][ptank.GetxPos()] = ' ';
			map[ptank.GetyPos()-1][ptank.GetxPos() + 1] = ' ';
			map[ptank.GetyPos()-1][ptank.GetxPos() + 2] = ' ';
			break; 
		}
		case 2: 
		{
			map[ptank.GetyPos() + 2][ptank.GetxPos()] = ' ';
			map[ptank.GetyPos() + 2][ptank.GetxPos() + 1] = ' ';
			map[ptank.GetyPos() + 2][ptank.GetxPos() + 2] = ' ';
			break; 
		}
		case 3: 
		{ 
			map[ptank.GetyPos()][ptank.GetxPos() - 1] = ' ';
			map[ptank.GetyPos() + 1][ptank.GetxPos() - 1] = ' ';
			break; 
		}
		case 4: 
		{
			map[ptank.GetyPos()][ptank.GetxPos() + 3] = ' ';
			map[ptank.GetyPos() + 1][ptank.GetxPos() + 3] = ' ';
			break; 
		}
	}
	// Enemy 1 placing
	map[en1.GetyPos()][en1.GetxPos()] = en1.Getmodel(0, 0);
	map[en1.GetyPos()][en1.GetxPos() + 1] = en1.Getmodel(0, 1);
	map[en1.GetyPos()][en1.GetxPos() + 2] = en1.Getmodel(0, 2);

	map[en1.GetyPos() + 1][en1.GetxPos()] = en1.Getmodel(1, 0);
	map[en1.GetyPos() + 1][en1.GetxPos() + 1] = en1.Getmodel(1, 1);
	map[en1.GetyPos() + 1][en1.GetxPos() + 2] = en1.Getmodel(1, 2);
	
	// cleaning track
	switch (en1.Getdir())
	{
	case 1:
	{
		map[en1.GetyPos() - 1][en1.GetxPos()] = ' ';
		map[en1.GetyPos() - 1][en1.GetxPos() + 1] = ' ';
		map[en1.GetyPos() - 1][en1.GetxPos() + 2] = ' ';
		break;
	}
	case 2:
	{
		map[en1.GetyPos() + 2][en1.GetxPos()] = ' ';
		map[en1.GetyPos() + 2][en1.GetxPos() + 1] = ' ';
		map[en1.GetyPos() + 2][en1.GetxPos() + 2] = ' ';
		break;
	}
	case 3:
	{
		map[en1.GetyPos()][en1.GetxPos() - 1] = ' ';
		map[en1.GetyPos() + 1][en1.GetxPos() - 1] = ' ';
		break;
	}
	case 4:
	{
		map[en1.GetyPos()][en1.GetxPos() + 3] = ' ';
		map[en1.GetyPos() + 1][en1.GetxPos() + 3] = ' ';
		break;
	}
	}
	// Enemy 2 placing
	map[en2.GetyPos()][en2.GetxPos()] = en2.Getmodel(0, 0);
	map[en2.GetyPos()][en2.GetxPos() + 1] = en2.Getmodel(0, 1);
	map[en2.GetyPos()][en2.GetxPos() + 2] = en2.Getmodel(0, 2);

	map[en2.GetyPos() + 1][en2.GetxPos()] = en2.Getmodel(1, 0);
	map[en2.GetyPos() + 1][en2.GetxPos() + 1] = en2.Getmodel(1, 1);
	map[en2.GetyPos() + 1][en2.GetxPos() + 2] = en2.Getmodel(1, 2);

	// cleaning track
	switch (en2.Getdir())
	{
	case 1:
	{
		map[en2.GetyPos() - 1][en2.GetxPos()] = ' ';
		map[en2.GetyPos() - 1][en2.GetxPos() + 1] = ' ';
		map[en2.GetyPos() - 1][en2.GetxPos() + 2] = ' ';
		break;
	}
	case 2:
	{
		map[en2.GetyPos() + 2][en2.GetxPos()] = ' ';
		map[en2.GetyPos() + 2][en2.GetxPos() + 1] = ' ';
		map[en2.GetyPos() + 2][en2.GetxPos() + 2] = ' ';
		break;
	}
	case 3:
	{
		map[en2.GetyPos()][en2.GetxPos() - 1] = ' ';
		map[en2.GetyPos() + 1][en2.GetxPos() - 1] = ' ';
		break;
	}
	case 4:
	{
		map[en2.GetyPos()][en2.GetxPos() + 3] = ' ';
		map[en2.GetyPos() + 1][en2.GetxPos() + 3] = ' ';
		break;
	}
	}
	return 0;
}
// Drawing a map
int Setup::DrawMap(AbstractTank& ptank, AbstractTank& en1, AbstractTank& en2)
{
	// drawing
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

// Starting a game
int Setup::GameStart()
{
	system("cls");
	GenerateMap();
	return 0;
}

// Game ending (loose)
int Setup::GameOver()
{
	system("cls");
	cout << "	Game over" << endl;
	return 0;
}

// Game ending (victory)
int Setup::Victory()
{
	system("cls");
	cout << "	You win!!!" << endl;
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
	cout << "	Time : ";
	SetplayTime(counter - start);
	if (counter - start > 59)
		min = (counter - start) % 60;
	sec = counter - start - min * 60;
	cout << min << " : " <<  sec << " seconds" << endl;
	return 0;
}

// Output player's Health Points
int Setup::DrawHp(AbstractTank& ptank)
{
	cout << "	HP left : ";
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
	cout << "	Score : " << ptank.Getscore() << endl;
	return 0;
}