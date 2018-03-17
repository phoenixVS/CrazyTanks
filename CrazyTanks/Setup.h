/*
	Module:  Setup.h
	Purpose: Declaration of the class Setup
*/
#include "Definitions.h"
#if !defined(__CrazyTanks_Setup_h)
#define __CrazyTanks_Setup_h

class Setup
{
public:
	int DrawMap();		// Drawing a map
	int GameStart();	// Starting a game
	int GameOver();		// Game ending (loose)
	int Victory();		// Game ending (victory)
	int Restart();		// Restarting the game
	int DrawTime();		// Output game time
	int DrawHp();		// Output player's Health Points

protected:
private:
	int mapWidth;
	int mapHeight;
	int PlayTime;

};

#endif