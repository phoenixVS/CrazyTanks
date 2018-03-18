/*
	Module:  Bullet.h
	Purpose: Declaration of the class Bullet
*/
#include "Definitions.h"
#if !defined(__CrazyTanks_Bullet_h)
#define __CrazyTanks_Bullet_h

class Bullet
{
public:
	int Flight();	// Bullet's flight

	Bullet();	// Default constructor
	~Bullet();	// Destructor

protected:
private:
	int directions;

};

#endif