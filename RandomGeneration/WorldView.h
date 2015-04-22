#pragma once

#include "Grassland.h"

extern int WINDOW_LENGTH;
extern int WINDOW_HEIGHT;

class WorldView
{
public:
	int posx, posy;

	WorldView();
	~WorldView();

	void handleEvent(sf::Event& event);
	void draw(const Area& area,sf::RenderTarget& window);
};

