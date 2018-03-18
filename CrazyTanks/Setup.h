/*
	Module:  Setup.h
	Purpose: Declaration of the class Setup
*/
#include "Definitions.h"
#include "TankPlayer.h"
#include "AbstractTank.h"
#if !defined(__CrazyTanks_Setup_h)
#define __CrazyTanks_Setup_h

class Setup
{
public:
	int GenerateMap();			// Empty map genering
	int PlayersPlacing(AbstractTank&, AbstractTank&, AbstractTank&, AbstractTank&);		// Placing players on map
	int DrawMap();				// Drawing a map
	int GameStart();			// Starting a game
	int GameOver();				// Game ending (loose)
	int Victory();				// Game ending (victory)
	int Restart();				// Restarting the game
	int DrawTime(time_t);		// Output game time
	int DrawHp(AbstractTank&);	// Output player's Health Points
	int DrawScore(TankPlayer&); // Output player's Score Points

	static Setup& SetupInstance();
	
	// Accessors
	int GetmapHeight();
	void SetmapHeight(int);
	int GetmapWidth();
	void SetmapWidth(int);
	int GetplayTime();
	void SetplayTime(int);

protected:
private:	
	Setup();		// Constructor is not avaliable
	~Setup();		// neither destructor
	// Singleton pattern for prevent creating	
	Setup(Setup const&) = delete;
	// and copying additional incstances of class Setup
	Setup& operator= (Setup const&) = delete;
	
	int mapWidth;
	int mapHeight;
	int playTime;
	char map[20][40];

};

#endif