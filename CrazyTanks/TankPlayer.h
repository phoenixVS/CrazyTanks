/*
	Module:  TankPlayer.h
	Purpose: Declaration of the class TankPlayer
*/
#include "Definitions.h"
#include "AbstractTank.h"
#if !defined(__CrazyTanks_TankPlayer_h)
#define __CrazyTanks_TankPlayer_h

class TankPlayer : public AbstractTank
{
public:

	TankPlayer();	// Default constructor
	~TankPlayer();	// Destructor

	// Accessors
	int Getscore();
	void Setscore(int);

protected:
private:
	int score;

};

#endif