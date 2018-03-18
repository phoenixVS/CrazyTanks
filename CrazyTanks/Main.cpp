/* 
	Main.cpp
	Project Crazy Tanks, created by Valentine Shapoval
*/
#include "Definitions.h"
#include "AbstractTank.h"
#include "Bullet.h"
#include "Setup.h"
#include "TankAI.h"
#include "TankPlayer.h"

int main()
{
	cout << "Version 0.4" << endl;
	{
		// Using a singleton pattern and static function
		Setup& s = Setup::SetupInstance();
		time_t start = time(NULL);
		bool end = false;
		while (!end)
		{			
			while (!s.Getstop())
			{
				system("cls");
				s.DrawMap();
				TankPlayer ptank;
				s.DrawTime(start);
				s.DrawHp(ptank);
				s.DrawScore(ptank);
			}
			if (s.Getstop() == 1)
				s.GameOver();
			else
				s.Victory();
			bool pressed = false;
			int sw = 0;
			cout << "Do you want to play again?" << endl;
			cout << "   Yes" << endl;
			cout << "   No" << endl;
			while (!pressed)
			{
				switch (_getch())
				{
				case 72:
					system("cls");
					cout << "Do you want to play again?" << endl;
					cout << "-> Yes" << endl;
					cout << "   No" << endl;
					sw = 1;
					break;
				case 80:
					system("cls");
					cout << "Do you want to play again?" << endl;
					cout << "   Yes" << endl;
					cout << "-> No" << endl;
					sw = 2;
					break;
				case 13:
				{
					if (sw == 1)
					{
						pressed = true;
						s.Restart();
					}
					else
					{
						pressed = true;
					    end = true;
					}
				}
				}

			}
		}
	}
}