#pragma once

#include "Village.h"

class Grassland :
	public Area
{
public:
	Grassland();
	Grassland(int x, int y, int length, int height);
	~Grassland();

	void generate();
};

