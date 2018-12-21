#pragma once
#include "Graphics.h"

struct  Menu
{
	int x, y;
	string data;
};

void mButton();
void InMenu(vector<Menu> &listMenu);
void PrintMenu(vector<Menu> listMenu);
void MoveSelect(vector<Menu> listMenu, int &dir, bool &Check);
void Guide();
void Info();
