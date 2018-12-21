#include "Snake.h"

void Init(vector<InfomationS> &Snake, InfomationS &Food, InfomationS &Derection, bool &endGame, int Point)
{
	InfomationS Body;
	endGame = false;
	AnConTro();
	//In điểm ban đầu:

	DrawBoxScore();
	DrawIconSmile();
	gotoxy(62, 2);  ColorText("Score: ", 10); cout << Point;

	//Khởi tạo rắn:
	int Temp = 3;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			Body.data = "@";
			Body.x = 4; Body.y = 0; //Khởi tạo vị trí của đầu là (0, 4);

			Snake.push_back(Body); 
		}
		else
		{
			if (i == 4)
			{
				Body.ox = -1; Body.oy = 0;
			}
			Body.data = "o";
			Body.x = Temp; Body.y = 0;
			Snake.push_back(Body);
			Temp--;
		}
	}

	// Tạo thức ăn.
	srand(time(0));
	Food.x = 1 + rand() % (WidthGame - 2);
	//srand(time(0));
	Food.y = 1 + rand() % (HeightGame - 2);
	

	//Khởi tạo hướng đi ban đầu là đứng yên.
	Derection.x = 0;          Derection.y = 0;

}

void MoveSnake(vector<InfomationS> &Snake, InfomationS dir, InfomationS &Food, bool &endGame, int &Point)
{
	InfomationS Add;
	int size = Snake.size();

	if (dir.x == 0 && dir.y == 0)
	{
		for (int i = 0; i < size; i++)
		{
			//Snake[0].ox = Snake[0].x;    Snake[0].oy = Snake[0].y;
			Snake[0].x += dir.x;         Snake[0].y += dir.y;
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
			{
				// di chuyển đầu rắn
				Snake[0].ox = Snake[0].x;    Snake[0].oy = Snake[0].y;
				Snake[0].x += dir.x;         Snake[0].y += dir.y;
			}
			else
			{
				// di chuyển phần thân rắn
				Snake[i].ox = Snake[i].x;         Snake[i].oy = Snake[i].y;
				Snake[i].x = Snake[i - 1].ox;     Snake[i].y = Snake[i - 1].oy;
			}

			// khi rắn vượt ra khỏi màn hình thì cho nó xuất hiện lại
			if (Snake[i].x >= WidthGame) Snake[i].x = 0;
			if (Snake[i].x < 0) Snake[i].x = WidthGame - 1;
			if (Snake[i].y >= HeightGame) Snake[i].y = 0;
			if (Snake[i].y < 0) Snake[i].y = HeightGame - 1;

			// kiểm tra coi con rắn có cắn trúng nó không
			if (i != 0 && (Snake[0].x == Snake[i].x && Snake[0].y == Snake[i].y))
				endGame = true;
		}
	}

	gotoxy(Food.x, Food.y);  ColorText("O", Food.x);
	
	//Rắn ăn Food:
	if (Snake[0].x == Food.x && Snake[0].y == Food.y)
	{
		Add.data = "o";
		Add.x = Snake[size - 1].ox;
		Add.y = Snake[size - 1].oy;
		Snake.push_back(Add);
		
		Point++;  gotoxy(62, 2); ColorText("Score: ", 10); cout << Point;

		//Tạo Food mới: 
		srand(time(0));
		Food.x = 1 + rand() % (WidthGame - 1);
		Food.y = 1 + rand() % (HeightGame - 1);
		gotoxy(Food.x, Food.y); ColorText("O", Food.x);

		//gotoxy(63, 10); cout << Food.x << "   " << Food.y;
	}
}

void DrawSnake(vector<InfomationS> &Snake)
{
	int size = Snake.size();
	for (int i = 0; i < size; i++)
	{
		gotoxy(Snake[i].x, Snake[i].y);
		cout << Snake[i].data;
	}
	gotoxy(Snake[size - 1].ox, Snake[size - 1].oy);
	cout << " "; // xóa phần đuôi trước đó của nó

}

void MainLoop(Status &StatusMove, Status &StatusGame, vector<InfomationS> &Snake, InfomationS &Direction, InfomationS &Food, int &Speed, bool &endGame, int &Point)
{
	MoveSnake(Snake, Direction, Food, endGame, Point);

	
	if (_kbhit())	// phát hiện có phím nhấn vào
	{
	     int key = _getch();
		 

		if (key == 75)
			StatusMove = LEFT;
		else if (key == 77)
			StatusMove = RIGHT;
		else if (key == 72)
			StatusMove = UP;
		else if (key == 80)
			StatusMove = DOWN;
		else if (key == 32) // Space tam dung game
			StatusGame = PAUSE;
		else if (key == 27) // ESC exit game
			StatusGame = ESC;
		else if (key == 13) // Enter tang toc do game
			StatusGame = SPEED;
	}

	if (StatusMove == LEFT)
	{
		if (Direction.x != 1)
		{
			Direction.x = -1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == RIGHT)
	{
		if (Direction.x != -1)
		{
			Direction.x = 1;
			Direction.y = 0;
		}
	}
	else if (StatusMove == UP)
	{
		if (Direction.y != 1)
		{
			Direction.y = -1;
			Direction.x = 0;
		}
	}
	else if (StatusMove == DOWN)
	{
		if (Direction.y != -1)
		{
			Direction.y = 1;
			Direction.x = 0;
		}
	}
	if (StatusGame == PAUSE)
	{
		while (true)
		{
			if (_kbhit()) // Đợi bắt phím chương trình chỉ tiếp tục khi nhấn nút space 1 lần nữa.
			{
				int key = _getch();

				if (key == 32)
				{
					StatusGame = EMPTY;
					break;
				}
				else
					continue;
			}
		}
	}
	if (StatusGame == ESC)
	{
		endGame = true;
	}
	
	if (StatusGame == SPEED)
	{
		if (Speed == SPEEDFIRST)
		{
			Speed = SPEEDLATER;
			StatusGame = EMPTY;
		}
		else
		{
			Speed = SPEEDFIRST;
			StatusGame = EMPTY;
		}
	}
}

void playGame()
{
	system("cls");
	resizeConsole(WidthConsoleGame, HeightConsoleGame);

	vector<InfomationS> Snake;
	InfomationS Derection, Food;
	Status StatusMove, StatusGame;
	int Speed = SPEEDFIRST, Point = 0;
	bool endGame = false;

	Init(Snake, Food, Derection, endGame, Point);

	while (!endGame)
	{
		DrawMap();

		Sleep(Speed);
		MainLoop(StatusMove, StatusGame, Snake, Derection, Food, Speed, endGame, Point);
		DrawSnake(Snake);
	}

	if (Point > getLowScore())
	{
		system("cls");
		File(Point);
		exit(0);
	}
	
}