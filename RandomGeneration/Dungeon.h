#pragma once

#include "DungeonWalker.h"

class Dungeon :
	public Area
{
public:
	string dungeontype;

	Dungeon();
	Dungeon(int x,int y,int length,int height,string t);
	~Dungeon();

	void generate();
	//void draw(sf::RenderWindow& window);
};

