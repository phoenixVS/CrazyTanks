/*
	Module:  TankAI.h
	Purpose: Declaration of the class TankAI
*/
#include "Definitions.h"
#if !defined(__CrazyTanks_TankAI_h)
#define __CrazyTanks_TankAI_h

class TankAI
{
public:
	int Logic();	// AI behaviour logic

protected:
private:
	int startPosX;
	int startPosY;

};

#endif