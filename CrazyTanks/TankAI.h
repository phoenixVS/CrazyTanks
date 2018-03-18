/*
	Module:  TankAI.h
	Purpose: Declaration of the class TankAI
*/
#include "Definitions.h"
#include "AbstractTank.h"
#if !defined(__CrazyTanks_TankAI_h)
#define __CrazyTanks_TankAI_h

class TankAI: public AbstractTank
{
public:
	int Logic();	// AI behaviour logic

	TankAI();	// Default constructor
	~TankAI();	// Destructor

protected:
private:
	int startPosX;
	int startPosY;

};

#endif