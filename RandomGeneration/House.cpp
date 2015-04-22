#include "House.h"


House::House()
{
	rooftype = "";
	walltype = "";
}

House::House(int x,int y,int length,int height,string rt,string wt) : Area(x,y,length,height)
{
	rooftype = rt;
	walltype = wt;
}

House::~House()
{
}

void House::generate()
{
	Map = new string[length*height*2];

	int wallheight = random(1,max(2,height-2));
	int roofheight = height-wallheight;
	for(int i = 0;i<roofheight*length;i++)
	{
		Map[i] = "House_" + rooftype + "_Roof_A3";
	}
	for(int i = roofheight*length;i<height*length;i++)
	{
		Map[i] = "House_" + walltype + "_Wall_A3";
	}
	int door = random(1,length);
	Map[height*length*2 - door] = "House_Entrance_Arch"; 
	createRenderTexture();
}
