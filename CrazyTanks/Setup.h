/*
	Module:  Setup.h
	Purpose: Declaration of the class Setup
*/
#include "Definitions.h"
#include "AbstractTank.h"
#include "TankPlayer.h"
#if !defined(__CrazyTanks_Setup_h)
#define __CrazyTanks_Setup_h

class Setup
{
public:
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
	bool Getstop();
	void Setstop(bool);
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
	
	bool stop;
	int mapWidth;
	int mapHeight;
	int playTime;	

};

#endif