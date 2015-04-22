#pragma once
#include "Dungeon.h"
class House :
	public Area
{
public:
	string rooftype;
	string walltype;

	House();
	House(int x,int y,int length,int height,string rt,string wt);
	~House();

	void generate();
};

