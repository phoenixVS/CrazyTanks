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
	enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

	int Move();		// Tank's moving
	int Shoot();	// Tank's shooting
	int Hit();		// Tank is getting damage
	int Miss();		// Tank missed

	AbstractTank();		// Default constructor
	~AbstractTank();	// Destructor

	// Accessors
	int Getdir();
	void Setdir(int);
	int GetxPos();
	void SetxPos(int);
	int GetyPos();
	void SetyPos(int);
	int Gethp();
	void Sethp(int);
	char Getmodel(int, int);
	void Setmodel(direction);
	int Gethitbox(int, int);
	void Sethitbox(direction);
	string Getcolor();
	void SetColor(string);
protected:
	
	direction dir;
	int xPos;
	int yPos;
	int hp;
	char model[2][3];
	int hitbox[2][3];
	string color;
private:

};

#endif