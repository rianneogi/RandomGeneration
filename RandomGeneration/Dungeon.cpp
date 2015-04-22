#include "Dungeon.h"

Dungeon::Dungeon() : Area()
{
	dungeontype = "Dirt";
}

Dungeon::Dungeon(int x,int y,int length,int height,string t) : Area(x,y,length,height)
{
	dungeontype = t;
}

Dungeon::~Dungeon()
{
}

void Dungeon::generate()
{
	Map = new string[length*height*2];
	for(int i = 0;i<length*height;i++)
	{
		Map[i] = "Dungeon_"+dungeontype+"_Roof_A2";
		Map[length*height + i] = "null";
	}

	int a=random(0,length);
	int b=random(0,height);
	for(int k = 0;k<1;k++)
	{
		int count = 0;
		DungeonWalker b1(length,height);
		b1.x=a;
		b1.y=b;
		//b1.iterate();
		while(count<(length*height/2))
		{
			int x = b1.iterate();
			if(x==0)
			{
				if(Map[b1.y*length+b1.x]=="Dungeon_"+dungeontype+"_Roof_A2")
				{
					Map[b1.y*length+b1.x] = "Dungeon_"+dungeontype+"_Ground";
					count++;
				}
			}
			else if(x>0) //make room
			{
				for(int i = max(1,b1.y-x);i<min(height-1,b1.y+x+1);i++)
				{
					for(int j = max(1,b1.x-x);j<min(length-1,b1.x+x+1);j++)
					{
						if(Map[b1.y*length+b1.x]=="Dungeon_"+dungeontype+"_Roof_A2")
						{
							Map[i*length+j] = "Dungeon_"+dungeontype+"_Ground";
							count++;
						}
					}
				}
			}
			//cout << count << " " << b1.x << " " << b1.y << endl;
		}
	}

	//post processing
	for(int i = 0;i<height;i++)
	{
		for(int j = 0;j<length;j++)
		{
			int surr = getTileSurrounding(j,i,0);
			if(at(j,i,0)=="Dungeon_"+dungeontype+"_Roof_A2" && at(j,i+1,0)!="Dungeon_"+dungeontype+"_Roof_A2" && i!=height-1)
			{
				Map[i*length+j] = "Dungeon_"+dungeontype+"_Wall_A3";
				if(at(j,i-1,0)=="Dungeon_"+dungeontype+"_Roof_A2" && i!=0)
				{
					Map[i*length+j-length] = "Dungeon_"+dungeontype+"_Wall_A3";
				}
			}
			if(surr==0)
			{
				Map[i*length+j] = "Dungeon_"+dungeontype+"_Rock";
			}
		}
	}
	createRenderTexture();
}

//void Dungeon::draw(sf::RenderWindow& window)
//{
//	for(int i = 0;i<height;i++)
//	{
//		for(int j = 0;j<length;j++)
//		{
//			if(Map[i*length+j]=="Dungeon_"+dungeontype+"_Roof")
//			{
//				int surr = getTileSurrounding(j,i);
//				int bits[8];
//				for(int k=0;k<8;k++)
//				{
//					bits[k] = (surr&(1<<k))>>k;
//				}
//				Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[0])+to_string(bits[1])+to_string(bits[2])+"_0"].setPosition(j*32,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[0])+to_string(bits[1])+to_string(bits[2])+"_0"]);
//				Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[2])+to_string(bits[3])+to_string(bits[4])+"_1"].setPosition(j*32+16,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[2])+to_string(bits[3])+to_string(bits[4])+"_1"]);
//				Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[6])+to_string(bits[7])+to_string(bits[0])+"_2"].setPosition(j*32,i*32+16);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[6])+to_string(bits[7])+to_string(bits[0])+"_2"]);
//				Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[4])+to_string(bits[5])+to_string(bits[6])+"_3"].setPosition(j*32+16,i*32+16);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Roof_"+to_string(bits[4])+to_string(bits[5])+to_string(bits[6])+"_3"]);
//			}
//			else if(Map[i*length+j]=="Dungeon_"+dungeontype+"_Wall")
//			{
//				int surr = getTileSurrounding(j,i);
//				int bits[8];
//				for(int k=0;k<8;k++)
//				{
//					bits[k] = (surr&(1<<k))>>k;
//				}
//				Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[0])+to_string(bits[2])+"_0"].setPosition(j*32,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[0])+to_string(bits[2])+"_0"]);
//				Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[2])+to_string(bits[4])+"_1"].setPosition(j*32+16,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[2])+to_string(bits[4])+"_1"]);
//				Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[6])+to_string(bits[0])+"_2"].setPosition(j*32,i*32+16);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[6])+to_string(bits[0])+"_2"]);
//				Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[4])+to_string(bits[6])+"_3"].setPosition(j*32+16,i*32+16);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Wall_"+to_string(bits[4])+to_string(bits[6])+"_3"]);
//			}
//			else if(Map[i*length+j]=="Dungeon_"+dungeontype+"_Ground")
//			{
//				Sprites["Dungeon_"+dungeontype+"_Ground"].setPosition(j*32,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Ground"]);
//			}
//			else if(Map[i*length+j]=="Dungeon_"+dungeontype+"_Rock")
//			{
//				Sprites["Dungeon_"+dungeontype+"_Ground"].setPosition(j*32,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Ground"]);
//				Sprites["Dungeon_"+dungeontype+"_Rock"].setPosition(j*32,i*32);
//				window.draw(Sprites["Dungeon_"+dungeontype+"_Rock"]);
//			}
//			/*else if(Map[i*length+j]==3)
//			{
//				Sprites["Dungeon_Dirt_Ground"].setPosition(32+j*32,32+i*32);
//				window.draw(Sprites["Dungeon_Dirt_Ground"]);
//				Sprites["Dungeon_Stairs_Up_Right"].setPosition(32+j*32,32+i*32);
//				window.draw(Sprites["Dungeon_Stairs_Up_Right"]);
//			}*/
//		}
//	}
//}
