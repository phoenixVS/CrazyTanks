/*
	Module:  AbstractTank.h
	Purpose: Declaration of the class AbstractTank
*/
#include "Definitions.h"
#if !defined(__CrazyTanks_AbstractTank_h)
#define __CrazyTanks_AbstractTank_h

class AbstractTank
{
public:
	int Move();		// Tank's moving
	int Shoot();	// Tank's shooting
	int Hit();		// Tank is getting damage
	int Miss();		// Tank missed

	AbstractTank();		// Default constructor
	~AbstractTank();	// Destructor

protected:
	int xPos;
	int yPos;
	int hp;
	string model;
	string hitbox;
	string color;
private:

};

#endif