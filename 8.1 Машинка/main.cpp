#include "animation.h"

using namespace sf;
using namespace std;

void removal(Car &machines) {
	delete machines.imageCar;
	delete machines.imageWheels;
	delete machines.spriteCar;
	delete machines.spriteWhellFirst;
	delete machines.spriteWhellSecond;
	delete machines.textureCar;
	delete machines.textureWhells;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Car Simulator");
	Car *machine = new Car;
	createCar(*machine);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		movingMachines(*machine);
		draw(*machine, window);
	}
	removal(*machine);
	delete machine;
	return 0;
}