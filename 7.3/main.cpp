#include <SFML/Graphics.hpp>
#include "system.h"
#include "config.h"
#include <iostream>


using namespace sf;
using namespace std;

void drawingSystem(RenderWindow & window, mySystem &sys) {
	window.clear(Color::Blue);
	window.draw(*sys.firstGears);
	window.draw(*sys.secondGears);
	window.draw(*sys.mintySprite);
	window.display();
}

void basicCycle(RenderWindow &window, mySystem &sys) {
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		operationSystem(sys);
		drawingSystem(window, sys);
	}
}

void cleaning(mySystem *sys) {
	delete sys->mintyImage;
	delete sys->mintySprite;
	delete sys->mintyTexture;
	delete sys->window;
	delete sys->firstGears;
	delete sys->secondGears;
	delete sys->firstGearsImage;
	delete sys->firstGearsTexture;
	delete sys->secondGearsImage;
	delete sys->secondGearsTexture;
}

int main()
{
	mySystem *sys = new mySystem;
	createSystem(*sys);
	RenderWindow &window = *sys->window;
	
	basicCycle(window, *sys);
	
	cleaning(sys);
	delete sys;
	return 0;
}