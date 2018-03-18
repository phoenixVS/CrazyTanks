/*
	Module:  TankPlayer.h
	Purpose: Declaration of the class TankPlayer
*/
#include "Definitions.h"
#if !defined(__CrazyTanks_TankPlayer_h)
#define __CrazyTanks_TankPlayer_h

class TankPlayer : public AbstractTank
{
public:

	TankPlayer();	// Default constructor
	~TankPlayer();	// Destructor

protected:
private:
	int score;

};

#endif