#include "WorldView.h"

#include <time.h>

int main()
{
	srand(time(0));
	Random.Randomize();

	sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGHT), "RNG");
	window.setVerticalSyncEnabled(true);
	window.setPosition(sf::Vector2i(0,0));
	
	loadfiles();

	WorldView wv;

	Dungeon d(0,20,20,20,"Dirt");
	d.generate();

	Grassland g(0, 0, 100, 100);
	g.generate();

	/*PerlinNoise p(34,18);
	p.computeGradient();
	PerlinNoise p2(18,10);
	p2.computeGradient();
	PerlinNoise p3(10,6);
	p3.computeGradient();*/

	int state = 0;

	sf::RenderTexture t;
	t.create(WINDOW_LENGTH, WINDOW_HEIGHT);
	sf::Sprite spr;

	while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
			{
				//world.handleEvent(event);
                window.close();
			}
			//world.handleEvent(event);
			//world.update();
			wv.handleEvent(event);
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Space)
				{
					state = (state+1)%6;
				}
			}
        }

        window.clear();
        
		//world.draw(window);
		//wv.draw(d,window);

		t.clear();
		wv.draw(g, t);
	
		/*for(int i = 1;i<=640;i++)
		{
			for(int j = 1;j<=320;j++)
			{
				sf::RectangleShape r(sf::Vector2f(2,2));
				r.setPosition(i*2,j*2);
				double x = p.perlin((i*1.0)/20,(j*1.0)/20)+1;
				double y = (p2.perlin((i*1.0)/40,(j*1.0)/40)+1)*2;
				double z = (p3.perlin((i*1.0)/80,(j*1.0)/80)+1)*4;
				double ans = (x+y+z)/14;
				x = x/2;
				y = y/4;
				z = z/8;
				if(ans>1 || ans <0) cout << "ERROR" << endl;
				r.setFillColor(sf::Color(ans*255,ans*255,ans*255));
				window.draw(r);
			}
		}*/

        t.display();
		spr = sf::Sprite(t.getTexture());
		spr.setPosition(sf::Vector2f(0, 0));
		window.draw(spr);
		window.display();
		cout << "done" << endl;
    }

	return 0;
}