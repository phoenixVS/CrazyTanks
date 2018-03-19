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
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds
	system("color 70");
	{
		// Using a singleton pattern and static function
		Setup& s = Setup::SetupInstance();
		time_t start = time(NULL);
		bool end = false;
		while (!end)
		{
			int stop = 0;TankPlayer ptank;
			srand(time(NULL) + 1);
			TankAI ai1;
			srand(time(NULL) + 2);
			TankAI ai2;
			ptank.Setdir(0);
			ai1.Setdir(0);
			ai2.Setdir(0);
			s.GenerateMap();			
			while (!stop)
			{
				s.PlayersPlacing(ptank, ai1, ai2);
				system("cls");
				s.DrawMap(ptank, ai1, ai2);				
				s.DrawTime(start);
				s.DrawHp(ptank);
				s.DrawScore(ptank);
				ai1.Logic();
				ai2.Logic();
				// Moving the tank
				if (_kbhit())
				{
					switch (_getch()) {
					case 72: ptank.Setdir(1); ptank.Setmodel(ptank.Getdir());
						break;
					case 80: ptank.Setdir(2); ptank.Setmodel(ptank.Getdir());
						break;
					case 75: ptank.Setdir(3); ptank.Setmodel(ptank.Getdir());
						break;
					case 77: ptank.Setdir(4); ptank.Setmodel(ptank.Getdir());
						break;
					default: break;
					}
				}
				ptank.Move();
				//sleep_for(nanoseconds(250000000));
			}
			if (stop == 1)
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