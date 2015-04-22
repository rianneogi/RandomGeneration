#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>
#include "AltSpriteHolder.hpp"

using namespace std;

extern sf::Texture Textures[16];
extern map<string,sf::Sprite> Sprites;

extern int loadfiles();