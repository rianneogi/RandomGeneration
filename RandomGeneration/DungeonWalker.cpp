#include "DungeonWalker.h"

//const int MAXSIZE = 50;

enum DIRECTION {DIR_UP,DIR_DOWN,DIR_LEFT,DIR_RIGHT};

int min(int a,int b)
{
	return (a<b?a:b);
}

int max(int a,int b)
{
	return (a>b?a:b);
}

DungeonWalker::DungeonWalker()
{
	length = 4;
	height = 4;
	x = random(0,length);
	y = random(0,height);
	roomchance = 0;
	dirchance = 0;
	dir = random(0,4);
}

DungeonWalker::DungeonWalker(int len,int hei)
{
	length = len;
	height = hei;
	x = random(0,len);
	y = random(0,hei);
	roomchance = 0;
	dirchance = 0;
	dir = random(0,4);
}

DungeonWalker::~DungeonWalker()
{
}

int DungeonWalker::iterate()
{
	int res = 0;
	while((dir==DIR_UP && y<=1) || (dir==DIR_DOWN && y>=height-2) || (dir==DIR_LEFT && x<=1) || (dir==DIR_RIGHT && x>=length-2))
	{
		dir = random(0,4); //force change direction
		dirchance = 0;
	}

	dirchance+=3;
	roomchance+=1;

	if(random(0,100)<dirchance)
	{
		dirchance = 0;
		dir = random(0,4);
		while((dir==DIR_UP && y<=1) || (dir==DIR_DOWN && y>=height-2) || (dir==DIR_LEFT && x<=1) || (dir==DIR_RIGHT && x>=length-2))
		{
			dir = random(0,4); //force change direction
		}
	}
	if(random(0,100)<roomchance)
	{
		roomchance = 0;
		res = random(1,3);
	}

	if(dir==DIR_UP)
		y--;
	if(dir==DIR_DOWN)
		y++;
	if(dir==DIR_LEFT)
		x--;
	if(dir==DIR_RIGHT)
		x++;
	return res;
}
