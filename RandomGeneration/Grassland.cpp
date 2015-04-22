#include "Grassland.h"


Grassland::Grassland()
{
}

Grassland::Grassland(int x, int y, int length, int height) : Area(x,y,length,height)
{
}

Grassland::~Grassland()
{
}

void Grassland::generate()
{
	Map = new string[length*height * 2];

	const int perlcnt = 5; //number of perlin octaves
	int size = 2; //size of a perlin square for the lowest octave

	int xsize = size;

	PerlinNoise p[perlcnt];
	for (int i = 0; i < perlcnt; i++)
	{
		p[i] = PerlinNoise(length / xsize + 2, height / xsize + 2);
		p[i].computeGradient();
		xsize *= 2;
	}

	int totalfactor = (1 << perlcnt) - 1;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			double x = 0;
			xsize = size;
			for (int k = 0; k < perlcnt; k++)
			{
				x += (p[k].perlin(((i + 1)*1.0) / xsize, ((j + 1)*1.0) / xsize))*(xsize/size);
				xsize *= 2;
			}
			x = x / totalfactor;
			//cout << "final x: " << x << endl;
			if (x > -0.66)
			{
				Map[i*length + j] = "Outside_Grass_Ground";
				if (x >= 0.1)
				{
					Map[i*length + j + length*height] = "Outside_Grass_Bush_A2";
				}
			}
			else
			{
				Map[i*length + j] = "Outside_DirtInGrass_A2";
			}
		}
	}

	int villagecount = random(0, min(length, height) / 60 + 1);
	for (int i = 0; i < villagecount; i++)
	{
		int hlength = random(20, min(length, height) / villagecount + 2);
		int hheight = random(20, min(length, height) / villagecount + 2);

		Area* a = new Village(random(1, length - hlength - 2), random(1, height - hheight - 2), hlength, hheight, "Grass");
		a->generate();
		subareas.push_back(a);
	}
	
	createRenderTexture();
}
