#pragma once
#include "Draw.h"
#include "File.h"

enum Status {UP, DOWN, LEFT, RIGHT, ESC, PAUSE, EMPTY, SPEED};
struct InfomationS // Rắn của người chơi
{
	string data;
	int x, y;     //là vị trí hiện tại của ô đó.
	int ox, oy;   // là vị trí trước đó của nó.
};

void Init(vector<InfomationS> &, InfomationS &, InfomationS &, bool &, int);
void MoveSnake(vector<InfomationS> &, InfomationS , InfomationS &, bool &, int &);
void DrawSnake(vector<InfomationS> &);
void MainLoop(Status &, Status &, vector<InfomationS> &, InfomationS &, InfomationS &, int &, bool &, int &);
void playGame();