#pragma once

#include "RandomFunctions.h"
#include "FileFunctions.h"

class Area
{
public:
	int x;
	int y;
	int length;
	int height;
	int drawCover;
	string* Map;

	vector<Area*> subareas;

	sf::RenderTexture texture;

	Area();
	Area(int _x,int _y,int len,int hei);
	~Area();

	string at(int x,int y,int layer) const;
	int getTileSurrounding(int tx,int ty,int layer) const;
	void createRenderTexture();
	void draw(sf::RenderTexture& window, int xoff, int yoff);
	void drawLayer(int layer, sf::RenderTarget& window, int xoff, int yoff);
	virtual void generate() = 0;
};

bool containsLabel(string name, string label);

