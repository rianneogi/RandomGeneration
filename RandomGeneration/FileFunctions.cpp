#include "FileFunctions.h"

sf::Texture Textures[16];
map<string,sf::Sprite> Sprites;

void generateSpriteSetA2(string name,int t,const sf::Vector2i& rect)
{
	name = name+"_A2";
	Sprites[name+"_000_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+32,16,16));
	Sprites[name+"_000_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+32,16,16));
	Sprites[name+"_000_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+80,16,16));
	Sprites[name+"_000_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+80,16,16));

	Sprites[name+"_101_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y,16,16));
	Sprites[name+"_101_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y,16,16));
	Sprites[name+"_101_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+16,16,16));
	Sprites[name+"_101_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+16,16,16));

	Sprites[name+"_111_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+64,16,16));
	Sprites[name+"_111_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+64,16,16));
	Sprites[name+"_111_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+48,16,16));
	Sprites[name+"_111_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+48,16,16));
	
	Sprites[name+"_001_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+64,16,16));
	Sprites[name+"_001_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+32,16,16));
	Sprites[name+"_001_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+80,16,16));
	Sprites[name+"_001_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+48,16,16));

	Sprites[name+"_100_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+32,16,16));
	Sprites[name+"_100_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+64,16,16));
	Sprites[name+"_100_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+48,16,16));
	Sprites[name+"_100_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+80,16,16));

	Sprites[name+"_011_0"] = Sprites[name+"_001_0"];
	Sprites[name+"_011_1"] = Sprites[name+"_001_1"];
	Sprites[name+"_011_2"] = Sprites[name+"_001_2"];
	Sprites[name+"_011_3"] = Sprites[name+"_001_3"];

	Sprites[name+"_110_0"] = Sprites[name+"_100_0"];
	Sprites[name+"_110_1"] = Sprites[name+"_100_1"];
	Sprites[name+"_110_2"] = Sprites[name+"_100_2"];
	Sprites[name+"_110_3"] = Sprites[name+"_100_3"];

	Sprites[name+"_010_0"] = Sprites[name+"_000_0"];
	Sprites[name+"_010_1"] = Sprites[name+"_000_1"];
	Sprites[name+"_010_2"] = Sprites[name+"_000_2"];
	Sprites[name+"_010_3"] = Sprites[name+"_000_3"];
}

void generateSpriteSetA3(string name,int t,const sf::Vector2i& rect)
{
	name = name+"_A3";
	Sprites[name+"_00_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y,16,16));
	Sprites[name+"_00_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y,16,16));
	Sprites[name+"_00_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+48,16,16));
	Sprites[name+"_00_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+48,16,16));

	Sprites[name+"_01_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+32,16,16));
	Sprites[name+"_01_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y,16,16));
	Sprites[name+"_01_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+48,16,16));
	Sprites[name+"_01_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+16,16,16));

	Sprites[name+"_10_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y,16,16));
	Sprites[name+"_10_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+48,rect.y+32,16,16));
	Sprites[name+"_10_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x,rect.y+16,16,16));
	Sprites[name+"_10_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+48,16,16));

	Sprites[name+"_11_0"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+32,16,16));
	Sprites[name+"_11_1"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+32,16,16));
	Sprites[name+"_11_2"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+32,rect.y+16,16,16));
	Sprites[name+"_11_3"] = sf::Sprite(Textures[t],sf::IntRect(rect.x+16,rect.y+16,16,16));
}

void generateSpriteSetA4(string tilename,int t,const sf::Vector2i& rect)
{
	string name = tilename+"_Roof";
	generateSpriteSetA2(name,t,rect);
	name = tilename+"_Wall";
	generateSpriteSetA3(name,t,sf::Vector2i(rect.x,rect.y+96));
}

void generateSpriteSetA3RoofAndWall(string tilename,int t,const sf::Vector2i& rect)
{
	string name = tilename+"_Roof";
	generateSpriteSetA3(name,t,rect);
	name = tilename+"_Wall";
	generateSpriteSetA3(name,t,sf::Vector2i(rect.x,rect.y+64));
}

int loadfiles()
{
	Textures[0].loadFromFile("Graphics\\Dungeon_A1.png");
	Textures[1].loadFromFile("Graphics\\Dungeon_A2.png");
	Textures[2].loadFromFile("Graphics\\Dungeon_A4.png");
	Textures[3].loadFromFile("Graphics\\Dungeon_B.png");
	Textures[4].loadFromFile("Graphics\\Dungeon_C.png");
	Textures[5].loadFromFile("Graphics\\Inside_A1.png");
	Textures[6].loadFromFile("Graphics\\Inside_A2.png");
	Textures[7].loadFromFile("Graphics\\Inside_A4.png");
	Textures[8].loadFromFile("Graphics\\Inside_B.png");
	Textures[9].loadFromFile("Graphics\\Inside_C.png");
	Textures[10].loadFromFile("Graphics\\Outside_A1.png");
	Textures[11].loadFromFile("Graphics\\Outside_A2.png");
	Textures[12].loadFromFile("Graphics\\Outside_A3.png");
	Textures[13].loadFromFile("Graphics\\Outside_A4.png");
	Textures[14].loadFromFile("Graphics\\Outside_B.png");
	Textures[15].loadFromFile("Graphics\\Outside_C.png");

	Sprites["Empty"] = sf::Sprite(Textures[8], sf::IntRect(0, 0, 32, 32));

	//Dungeon_A1
	Sprites["Dungeon_Dirt_Ground"] = sf::Sprite(Textures[1],sf::IntRect(0,0,32,32));

	//Dungeon_A
	Sprites["Dungeon_Dirt_Rock"] = sf::Sprite(Textures[3],sf::IntRect(0,7*32,32,32));
	Sprites["Dungeon_Dirt_Rock2"] = sf::Sprite(Textures[3],sf::IntRect(0,8*32,32,64));

	//Dungeon_A4
	generateSpriteSetA4("Dungeon_Dirt",2,sf::Vector2i(0,0));
	generateSpriteSetA4("Dungeon_Rock",2,sf::Vector2i(64,0));
	generateSpriteSetA4("Dungeon_Lava",2,sf::Vector2i(128,0));
	generateSpriteSetA4("Dungeon_Ice",2,sf::Vector2i(192,0));
	generateSpriteSetA4("Dungeon_Swamp",2,sf::Vector2i(256,0));
	generateSpriteSetA4("Dungeon_Crystal",2,sf::Vector2i(320,0));
	generateSpriteSetA4("Dungeon_Alien",2,sf::Vector2i(384,0));
	generateSpriteSetA4("Dungeon_Demon",2,sf::Vector2i(448,0));

	//Outside A2

	Sprites["Outside_Grass_Ground"] = sf::Sprite(Textures[11],sf::IntRect(0,0,32,32));
	Sprites["Outside_Dirt_Ground"] = sf::Sprite(Textures[11],sf::IntRect(0,96,32,32));
	Sprites["Outside_Sand_Ground"] = sf::Sprite(Textures[11],sf::IntRect(0,192,32,32));
	Sprites["Outside_Snow_Ground"] = sf::Sprite(Textures[11],sf::IntRect(0,288,32,32));

	generateSpriteSetA2("Outside_DirtInGrass",11,sf::Vector2i(64,0));
	generateSpriteSetA2("Outside_GrassInDirt",11,sf::Vector2i(64,96));
	generateSpriteSetA2("Outside_GrassInSand",11,sf::Vector2i(64,192));
	generateSpriteSetA2("Outside_DirtInSnow",11,sf::Vector2i(64,288));

	generateSpriteSetA2("Outside_StoneInGrass",11,sf::Vector2i(128,0));
	generateSpriteSetA2("Outside_StoneInDirt",11,sf::Vector2i(128,96));
	generateSpriteSetA2("Outside_StoneInSand",11,sf::Vector2i(128,192));
	generateSpriteSetA2("Outside_StoneInSnow",11,sf::Vector2i(128,288));

	generateSpriteSetA2("Outside_Stone",11,sf::Vector2i(192,0));
	generateSpriteSetA2("Outside_Snowstone",11,sf::Vector2i(192,96));
	generateSpriteSetA2("Outside_Sandstone",11,sf::Vector2i(192,192));
	//generateSpriteSetA2("Outside_Mattress",11,sf::IntRect(192,288,64,96));

	generateSpriteSetA2("Outside_Grass_Bush",11,sf::Vector2i(256,0));
	generateSpriteSetA2("Outside_Dirt_Bush",11,sf::Vector2i(256,96));
	generateSpriteSetA2("Outside_Sand_Bush",11,sf::Vector2i(256,192));
	generateSpriteSetA2("Outside_Snow_Bush",11,sf::Vector2i(256,288));

	generateSpriteSetA2("Outside_Grass_Fence",11,sf::Vector2i(384,0));
	generateSpriteSetA2("Outside_Dirt_Fence",11,sf::Vector2i(384,96));
	generateSpriteSetA2("Outside_Sand_Fence",11,sf::Vector2i(384,192));
	generateSpriteSetA2("Outside_Snow_Fence",11,sf::Vector2i(384,288));

	//Outside A3
	generateSpriteSetA3RoofAndWall("House_Plaster",12,sf::Vector2i(0,0));
	generateSpriteSetA3RoofAndWall("House_Yellow",12,sf::Vector2i(64,0));
	generateSpriteSetA3RoofAndWall("House_Green",12,sf::Vector2i(128,0));
	generateSpriteSetA3RoofAndWall("House_Blue",12,sf::Vector2i(192,0));
	generateSpriteSetA3RoofAndWall("House_Brick",12,sf::Vector2i(256,0));
	generateSpriteSetA3RoofAndWall("House_Decorative",12,sf::Vector2i(320,0));
	generateSpriteSetA3RoofAndWall("House_Dirt",12,sf::Vector2i(384,0));
	generateSpriteSetA3RoofAndWall("House_Reinforced",12,sf::Vector2i(448,0));
	generateSpriteSetA3RoofAndWall("House_Wood",12,sf::Vector2i(0,128));
	generateSpriteSetA3RoofAndWall("House_Wood2",12,sf::Vector2i(64,128));
	generateSpriteSetA3RoofAndWall("House_Log",12,sf::Vector2i(128,128));
	generateSpriteSetA3RoofAndWall("House_Thatch",12,sf::Vector2i(192,128));
	generateSpriteSetA3RoofAndWall("House_Stone",12,sf::Vector2i(256,128));
	generateSpriteSetA3RoofAndWall("House_Tent",12,sf::Vector2i(320,128));
	generateSpriteSetA3RoofAndWall("House_SnowThatch",12,sf::Vector2i(384,128));
	generateSpriteSetA3RoofAndWall("House_SnowWood",12,sf::Vector2i(448,128));

	Sprites["House_Entrance_Square"] = sf::Sprite(Textures[14],sf::IntRect(96,256,32,32));
	Sprites["House_Entrance_Arch"] = sf::Sprite(Textures[14],sf::IntRect(192,256,32,32));

	Sprites["House_Sign_Weapon"] = sf::Sprite(Textures[14],sf::IntRect(32,0,32,32));
	Sprites["House_Sign_WeaponAndArmor"] = sf::Sprite(Textures[14],sf::IntRect(64,0,32,32));
	Sprites["House_Sign_Armor"] = sf::Sprite(Textures[14],sf::IntRect(96,0,32,32));
	Sprites["House_Sign_Misc"] = sf::Sprite(Textures[14],sf::IntRect(128,0,32,32));
	Sprites["House_Sign_Potion"] = sf::Sprite(Textures[14],sf::IntRect(160,0,32,32));
	Sprites["House_Sign_Inn"] = sf::Sprite(Textures[14],sf::IntRect(192,0,32,32));
	Sprites["House_Sign_Pub"] = sf::Sprite(Textures[14],sf::IntRect(224,0,32,32));
	Sprites["House_Sign_Farm"] = sf::Sprite(Textures[14],sf::IntRect(0,32,32,32));
	Sprites["House_Sign_Magic"] = sf::Sprite(Textures[14],sf::IntRect(32,32,32,32));
	Sprites["House_Sign_Staff"] = sf::Sprite(Textures[14],sf::IntRect(64,32,32,32));
	Sprites["House_Sign_Gold"] = sf::Sprite(Textures[14],sf::IntRect(96,32,32,32));
	Sprites["House_Sign_Boots"] = sf::Sprite(Textures[14],sf::IntRect(128,32,32,32));
	Sprites["House_Sign_Ring"] = sf::Sprite(Textures[14],sf::IntRect(160,32,32,32));
	Sprites["House_Sign_Hammer"] = sf::Sprite(Textures[14],sf::IntRect(192,32,32,32));
	Sprites["House_Sign_Crest"] = sf::Sprite(Textures[14],sf::IntRect(224,32,32,32));

	return 0;
}