#include "Draw.h"
void DrawMenu()
{
	for (int i = 0; i <= WidthMenu; i++)
	{
		gotoxy(i, 0); cout << char(219);
		gotoxy(i, HeightMenu); cout << char(219);
	}
	for (int i = 0; i <= HeightMenu; i++)
	{
		gotoxy(0, i); cout << char(219);
		gotoxy(WidthMenu, i); cout << char(219);
	}
}

void DrawTextSnake()
{
	ifstream FileIn("Text.IN", ios::in);
	if (FileIn.fail())
	{
		cout << "ERROR file text";
		Sleep(5000);
		exit(0);
	}

	int line = 1;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);

		if (text == "**")
		{
			break;
		}
		else
		{
			gotoxy(5, line++); cout << text;
		}
	}
	
	FileIn.close();
}

void DrawMap()
{
	char dmap = 219;
	for (int i = 0; i < HeightGame; i++)
	{
		gotoxy(WidthGame, i);
		cout << dmap;
	}
	for (int i = 0; i <= WidthGame; i++)
	{
		gotoxy(i, HeightGame);
		cout << dmap;
	}
}

void DrawBoxScore()
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = WidthGame; i <= WidthGame + 12; i++)
		{
			if (j == 0 || j == 4 || i == WidthGame || i == WidthGame + 12)
			{
				gotoxy(i, j); cout << (char)219;
			}
		}
	}
}

void DrawIconSmile()
{
	ifstream FileIn("Text.IN", ios::in);

	if (FileIn.fail())
	{
		cout << "ERROR file text";
		Sleep(5000);
		exit(0);
	}

	while (!FileIn.eof())
	{
		string temp;

		getline(FileIn, temp);

		if (temp == "**")
		{
			break;
		}
	}
	int line = 6;
	while (!FileIn.eof())
	{
		string text;
		getline(FileIn, text);

		gotoxy(64, line++); ColorText(text, 10);
	}

}