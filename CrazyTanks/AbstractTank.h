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
	enum direcrion { Stop, LEFT, RIGHT, UP, DOWN };

	int Move();		// Tank's moving
	int Shoot();	// Tank's shooting
	int Hit();		// Tank is getting damage
	int Miss();		// Tank missed

	AbstractTank();		// Default constructor
	~AbstractTank();	// Destructor

	// Accessors
	int GetxPos();
	void SetxPos(int);
	int GetyPos();
	void SetyPos(int);
	int Gethp();
	void Sethp(int);
	string Getmodel();
	void Setmodel(string);
	string Gethitbox();
	void Sethitbox(string);
	string Getcolor();
	void SetColor(string);
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