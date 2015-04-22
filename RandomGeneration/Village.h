#pragma once
#include "House.h"
class Village :
	public Area
{
public:
	string villagetype;

	Village();
	Village(int x,int y,int length,int height,string t);
	~Village();

	void generate();
};

