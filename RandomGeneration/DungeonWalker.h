#pragma once

#include "Area.h"

//const int MAXSIZE = 50;
extern int min(int a,int b);
extern int max(int a,int b);

class DungeonWalker
{
public:
	DungeonWalker();
	DungeonWalker(int len,int hei);
	~DungeonWalker();

	int x;
	int y;
	int roomchance;
	int dirchance;
	int dir;
	int length;
	int height;

	int iterate();
};

