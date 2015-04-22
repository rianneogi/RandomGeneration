#include "Area.h"

Area::Area()
{
	x=0;
	y=0;
	length=4;
	height=4;
	drawCover=1;
}

Area::Area(int _x,int _y,int len,int hei)
{
	x=_x;
	y=_y;
	length=len;
	height=hei;
	drawCover=1;
}

Area::~Area()
{
	delete [] Map;
	for(int i = 0;i<subareas.size();i++)
	{
		delete subareas.at(i);
	}
}

string Area::at(int x,int y,int layer) const
{
	if(x<0 || y<0 || x>=length || y>=height || layer<0 || layer>1)
		return "null";
	return Map[layer*height*length + y*length + x];
}

int Area::getTileSurrounding(int tx,int ty,int layer) const
{
	int sum = 0;

	string t = at(tx,ty,layer);

	if(at(tx-1,ty,layer)==t)
	{
		sum += 1;
	}
	if(at(tx-1,ty-1,layer)==t)
	{
		sum += 2;
	}
	if(at(tx,ty-1,layer)==t)
	{
		sum += 4;
	}
	if(at(tx+1,ty-1,layer)==t)
	{
		sum += 8;
	}
	if(at(tx+1,ty,layer)==t)
	{
		sum += 16;
	}
	if(at(tx+1,ty+1,layer)==t)
	{
		sum += 32;
	}
	if(at(tx,ty+1,layer)==t)
	{
		sum += 64;
	}
	if(at(tx-1,ty+1,layer)==t)
	{
		sum += 128;
	}
	return sum;
}

bool containsLabel(string name,string label)
{
	int p = 0;
	int i = 0;
	for(;i<name.size();i++)
	{
		if(name.at(i)=='_')
		{
			if(name.substr(p,i-p)==label)
				return true;
			p = i+1;
			i++;
		}
	}
	if(name.substr(p,i-p)==label)
		return true;
	return false;
}

void Area::createRenderTexture()
{
	texture.create(32 * length, 32 * height);
	texture.clear();
	draw(texture, 0, 0);
	texture.display();
}

void Area::draw(sf::RenderTexture& window, int xoff, int yoff)
{
	/*for (int i = 0; i<subareas.size(); i++)
	{
		subareas.at(i)->createRenderTexture();
	}*/
	/*window.create(32 * length, 32 * height);
	window.clear();*/
	drawLayer(0, window, xoff, yoff);
	drawLayer(1, window, xoff, yoff);
	for (int i = 0; i < subareas.size();i++)
	{
		subareas.at(i)->draw(window, xoff+subareas.at(i)->x, yoff+subareas.at(i)->y);
	}
	
	
	/*for(int i = 0;i<height;i++)
	{
		for(int j = 0;j<length;j++)
		{
			if(containsLabel(Map[i*length+j],"A2"))
			{
				int surr = getTileSurrounding(j,i);
				int bits[8];
				for(int k=0;k<8;k++)
				{
					bits[k] = (surr&(1<<k))>>k;
				}
				Sprites[Map[i*length+j]+"_"+to_string(bits[0])+to_string(bits[1])+to_string(bits[2])+"_0"].setPosition(j*32,i*32);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[0])+to_string(bits[1])+to_string(bits[2])+"_0"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[2])+to_string(bits[3])+to_string(bits[4])+"_1"].setPosition(j*32+16,i*32);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[2])+to_string(bits[3])+to_string(bits[4])+"_1"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[6])+to_string(bits[7])+to_string(bits[0])+"_2"].setPosition(j*32,i*32+16);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[6])+to_string(bits[7])+to_string(bits[0])+"_2"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[4])+to_string(bits[5])+to_string(bits[6])+"_3"].setPosition(j*32+16,i*32+16);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[4])+to_string(bits[5])+to_string(bits[6])+"_3"]);
			}
			else if(containsLabel(Map[i*length+j],"A3"))
			{
				int surr = getTileSurrounding(j,i);
				int bits[8];
				for(int k=0;k<8;k++)
				{
					bits[k] = (surr&(1<<k))>>k;
				}
				Sprites[Map[i*length+j]+"_"+to_string(bits[0])+to_string(bits[2])+"_0"].setPosition(j*32,i*32);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[0])+to_string(bits[2])+"_0"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[2])+to_string(bits[4])+"_1"].setPosition(j*32+16,i*32);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[2])+to_string(bits[4])+"_1"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[6])+to_string(bits[0])+"_2"].setPosition(+j*32,i*32+16);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[6])+to_string(bits[0])+"_2"]);
				Sprites[Map[i*length+j]+"_"+to_string(bits[4])+to_string(bits[6])+"_3"].setPosition(+j*32+16,i*32+16);
				texture.draw(Sprites[Map[i*length+j]+"_"+to_string(bits[4])+to_string(bits[6])+"_3"]);
			}
			else
			{
				Sprites[Map[i*length+j]].setPosition(j*32,i*32);
				texture.draw(Sprites[Map[i*length+j]]);
			}
		}
	}*/
	//texture.display();
}

void Area::drawLayer(int layer, sf::RenderTarget& window, int xoff, int yoff)
{
	for(int i = 0;i<height;i++)
	{
		for(int j = 0;j<length;j++)
		{
			int index = layer*height*length + i*length + j;
			if(Map[index]=="null") continue;
			if(containsLabel(Map[index],"A2"))
			{
				int surr = getTileSurrounding(j,i,layer);
				int bits[8];
				for(int k=0;k<8;k++)
				{
					bits[k] = (surr&(1<<k))>>k;
				}
				Sprites[Map[index] + "_" + to_string(bits[0]) + to_string(bits[1]) + to_string(bits[2]) + "_0"].setPosition(xoff * 32 + j * 32, yoff * 32 + i * 32);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[0]) + to_string(bits[1]) + to_string(bits[2]) + "_0"]);
				Sprites[Map[index] + "_" + to_string(bits[2]) + to_string(bits[3]) + to_string(bits[4]) + "_1"].setPosition(xoff * 32 + j * 32 + 16, yoff * 32 + i * 32);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[2]) + to_string(bits[3]) + to_string(bits[4]) + "_1"]);
				Sprites[Map[index] + "_" + to_string(bits[6]) + to_string(bits[7]) + to_string(bits[0]) + "_2"].setPosition(xoff * 32 + j * 32, yoff * 32 + i * 32 + 16);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[6]) + to_string(bits[7]) + to_string(bits[0]) + "_2"]);
				Sprites[Map[index] + "_" + to_string(bits[4]) + to_string(bits[5]) + to_string(bits[6]) + "_3"].setPosition(xoff * 32 + j * 32 + 16, yoff * 32 + i * 32 + 16);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[4]) + to_string(bits[5]) + to_string(bits[6]) + "_3"]);
			}
			else if(containsLabel(Map[index],"A3"))
			{
				int surr = getTileSurrounding(j,i,layer);
				int bits[8];
				for(int k=0;k<8;k++)
				{
					bits[k] = (surr&(1<<k))>>k;
				}
				Sprites[Map[index] + "_" + to_string(bits[0]) + to_string(bits[2]) + "_0"].setPosition(xoff * 32 + j * 32, yoff * 32 + i * 32);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[0]) + to_string(bits[2]) + "_0"]);
				Sprites[Map[index] + "_" + to_string(bits[2]) + to_string(bits[4]) + "_1"].setPosition(xoff * 32 + j * 32 + 16, yoff * 32 + i * 32);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[2]) + to_string(bits[4]) + "_1"]);
				Sprites[Map[index] + "_" + to_string(bits[6]) + to_string(bits[0]) + "_2"].setPosition(xoff * 32 + j * 32, yoff * 32 + i * 32 + 16);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[6]) + to_string(bits[0]) + "_2"]);
				Sprites[Map[index] + "_" + to_string(bits[4]) + to_string(bits[6]) + "_3"].setPosition(xoff * 32 + j * 32 + 16, yoff * 32 + i * 32 + 16);
				window.draw(Sprites[Map[index] + "_" + to_string(bits[4]) + to_string(bits[6]) + "_3"]);
			}
			else
			{
				Sprites[Map[index]].setPosition(xoff * 32 + j * 32, yoff * 32 + i * 32);
				window.draw(Sprites[Map[index]]);
			}
		}
	}
}
