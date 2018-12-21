#include "Menu.h"
#include "Snake.h"
#include "File.h"
#include "Draw.h"

int main()
{
	resizeConsole(WidthConsole, HeightConsole);
	AnConTro();

	vector<Menu> listMenu;

	InMenu(listMenu);

	int dir = 0;
	bool CheckChoose = false;

	while (true)
	{
		DrawMenu();
		DrawTextSnake();

		PrintMenu(listMenu);

		TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

		MoveSelect(listMenu, dir, CheckChoose);

		if (CheckChoose == true)
		{
			CheckChoose = false;

			if (dir == 0) // PlayGame
			{
				playGame();
			}
			else if (dir == 1) // Height Score
			{
				system("cls");
				DrawMenu();
				DrawTextSnake();

				hightScore();

				system("cls");
			}
			else if (dir == 2) // Guide
			{
				system("cls");
				DrawMenu();
				DrawTextSnake();

				Guide();

				system("cls");
			}
			else if (dir == 3) // Info
			{
				system("cls");
				DrawMenu();
				DrawTextSnake();

				Info();

				system("cls");
			}
			else if (dir == 4) // exit
			{
				exit(0);
			}
		}
	}
	
	system("pause");
	return 0;
}