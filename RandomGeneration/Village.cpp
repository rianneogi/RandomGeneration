#include "Village.h"


Village::Village()
{
	villagetype = "Grass";
}

Village::Village(int x,int y,int length,int height,string t) : Area(x,y,length,height)
{
	villagetype = t;
}

Village::~Village()
{
}

void Village::generate()
{
	Map = new string[length*height*2];
	for(int i = 0;i<length*height;i++)
	{
		Map[i] = "Empty";
		Map[length*height + i] = "Empty";
	}
	for(int i = 0;i<length;i++)
	{
		Map[i + length*height] = "Outside_"+villagetype+"_Fence_A2";
		Map[length*height*2 -1-i] = "Outside_"+villagetype+"_Fence_A2";
	}
	for(int i = 0;i<height;i++)
	{
		Map[i*length + length*height] = "Outside_"+villagetype+"_Fence_A2";
		Map[length*height*2 -1-(i*length)] = "Outside_"+villagetype+"_Fence_A2";
	}

	//create houses
	int housecount = random(min(length, height) / 10, min(length, height) / 5);
	for(int i = 0;i<housecount;i++)
	{
		int hlength = random(3,5);
		int hheight = random(3,4);

		int htype = random(0, 4);
		string shtype;
		switch (htype)
		{
		case 0:
			shtype = "Wood";
			break;
		case 1:
			shtype = "Wood2";
			break;
		case 2:
			shtype = "Log";
			break;
		case 3:
			shtype = "Thatch";
			break;
		}

		Area* a = new House(random(1, length - hlength - 2), random(1, height - hheight - 2), hlength, hheight, shtype, shtype);
		a->generate();
		subareas.push_back(a);
	}

	cout << "generated village" << endl;
	createRenderTexture();
}
