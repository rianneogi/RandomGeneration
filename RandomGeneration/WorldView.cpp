#include "WorldView.h"

int WINDOW_LENGTH = 1200;
int WINDOW_HEIGHT = 800;

WorldView::WorldView()
{
	posx=0;
	posy=0;
}

WorldView::~WorldView()
{
}

void WorldView::draw(const Area& area,sf::RenderTarget& window)
{
	sf::Sprite sprite(area.texture.getTexture());
	sprite.setPosition((area.x-posx)*32,(area.y-posy)*32);
	window.draw(sprite);
	/*for(int i = 0;i<area.subareas.size();i++)
	{
		draw(*area.subareas.at(i),window);
	}*/

	cout << "drawing" << endl;

	/*int ybegin = max(0,posy-area.y);
	int yend = min(area.height,posy-area.y+(WINDOW_HEIGHT/32));
	int xbegin = max(0,posx-area.x);
	int xend = min(area.height,posx-area.x+(WINDOW_LENGTH/32));
	for(int i = 0;i<area.height;i++)
	{
		for(int j = 0;j<area.length;j++)
		{
			if (area.Map[i*area.length + j] != "null")
			{
				if (containsLabel(area.Map[i*area.length + j], "A2"))
				{
					int surr = area.getTileSurrounding(j, i, 0);
					int bits[8];
					for (int k = 0; k < 8; k++)
					{
						bits[k] = (surr&(1 << k)) >> k;
					}
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[0]) + to_string(bits[1]) + to_string(bits[2]) + "_0"].setPosition((posx + j) * 32, (posy + i) * 32);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[0]) + to_string(bits[1]) + to_string(bits[2]) + "_0"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[2]) + to_string(bits[3]) + to_string(bits[4]) + "_1"].setPosition((posx + j) * 32 + 16, (posy + i) * 32);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[2]) + to_string(bits[3]) + to_string(bits[4]) + "_1"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[6]) + to_string(bits[7]) + to_string(bits[0]) + "_2"].setPosition((posx + j) * 32, (posy + i) * 32 + 16);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[6]) + to_string(bits[7]) + to_string(bits[0]) + "_2"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[4]) + to_string(bits[5]) + to_string(bits[6]) + "_3"].setPosition((posx + j) * 32 + 16, (posy + i) * 32 + 16);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[4]) + to_string(bits[5]) + to_string(bits[6]) + "_3"]);
				}
				else if (containsLabel(area.Map[i*area.length + j], "A3"))
				{
					int surr = area.getTileSurrounding(j, i, 0);
					int bits[8];
					for (int k = 0; k < 8; k++)
					{
						bits[k] = (surr&(1 << k)) >> k;
					}
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[0]) + to_string(bits[2]) + "_0"].setPosition((posx + j) * 32, (posy + i) * 32);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[0]) + to_string(bits[2]) + "_0"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[2]) + to_string(bits[4]) + "_1"].setPosition((posx + j) * 32 + 16, (posy + i) * 32);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[2]) + to_string(bits[4]) + "_1"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[6]) + to_string(bits[0]) + "_2"].setPosition((posx + j) * 32, (posy + i) * 32 + 16);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[6]) + to_string(bits[0]) + "_2"]);
					Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[4]) + to_string(bits[6]) + "_3"].setPosition((posx + j) * 32 + 16, (posy + i) * 32 + 16);
					window.draw(Sprites[area.Map[i*area.length + j] + "_" + to_string(bits[4]) + to_string(bits[6]) + "_3"]);
				}
				else
				{
					Sprites[area.Map[i*area.length + j]].setPosition((posx + j) * 32, (posy + i) * 32);
					window.draw(Sprites[area.Map[i*area.length + j]]);
				}
			}
		}
	}

	for (int i = 0; i<area.subareas.size(); i++)
	{
		draw(*area.subareas.at(i), window);
	}*/
}

void WorldView::handleEvent(sf::Event& event)
{
	if(event.type==sf::Event::KeyPressed)
	{
		if(event.key.code==sf::Keyboard::Up)
		{
			posy--;
		}
		else if(event.key.code==sf::Keyboard::Left)
		{
			posx--;
		}
		else if(event.key.code==sf::Keyboard::Right)
		{
			posx++;
		}
		else if(event.key.code==sf::Keyboard::Down)
		{
			posy++;
		}
	}
}
