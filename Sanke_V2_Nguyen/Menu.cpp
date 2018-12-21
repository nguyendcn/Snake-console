#include "Menu.h"

void mButton()
{
	AnConTro();
	int Check;
	do {
		gotoxy(60, 23);
		cout << " 1: Back ";
		if (_kbhit())
		{
			Check = _getch();
			if (Check == 49)
				break;
		}
	} while (true);
}

void InMenu(vector<Menu> &listMenu)
{
	Menu items;

	items.x = 35;
	items.y = 15;
	items.data = "Play Game";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 17;
	items.data = "Score";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 19;
	items.data = "Guide";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 21;
	items.data = "Info";
	listMenu.push_back(items);

	items.x = 37;
	items.y = 23;
	items.data = "Quit";
	listMenu.push_back(items);
}

void PrintMenu(vector<Menu> listMenu)
{
	for (int i = 0; i < listMenu.size(); i++)
	{
		gotoxy(listMenu[i].x, listMenu[i].y); cout << listMenu[i].data;
	}
}

void MoveSelect(vector<Menu> listMenu, int &dir, bool &Check)
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key == 72) // UP
			{
				gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << "             ";
				gotoxy(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;
				if (dir == 0)
				{
					dir = 4;
				}
				else
					dir--;

				TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

				break;
			}
			else if (key == 80) // DOWN
			{
				gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << "             ";
				gotoxy(listMenu[dir].x, listMenu[dir].y); cout << listMenu[dir].data;

				if (dir == 4)
				{
					dir = 0;
				}
				else
					dir++;

				TextColor(10); gotoxy(listMenu[dir].x - 3, listMenu[dir].y); cout << (char)175 << " " << listMenu[dir].data << " "; TextColor(7);

				break;
			}
			else if (key == 13) // ENTER
			{
				Check = true;
				break;
			}
		}
	}
}

void Guide()
{
	ifstream FileIn("TextGame.dll", ios::in);
	int line = 15;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);
		if (text == "**")
			break;
		gotoxy(10, line++); ColorText(text, 10);
	}
	FileIn.close();

	mButton();
}

void Info()
{
	char text1[50] = "CoppyRight: Dang Cao Nguyen - PTIT - D16", text2[40] = "Support: Superntseal@gmail.com";
	char text3[50] = ">>-----Thanks you for play game-----<<";
	TextBT(22, 25, 22, 15, text1, 10, 10, 1);
	TextBT(26, 25, 26, 16, text2, 10, 10, 1);
	TextBT(22, 25, 22, 18, text3, 10, 10, 1);

	TextColor(7);

	mButton();
}