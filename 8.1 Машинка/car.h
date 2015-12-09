#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"

using namespace sf;
using namespace std;

struct Car {
	Image *imageCar = nullptr;
	Image *imageWheels = nullptr;
	Texture *textureCar = nullptr;
	Texture *textureWhells = nullptr;
	Sprite *spriteCar = nullptr;
	Sprite *spriteWhellFirst = nullptr;
	Sprite *spriteWhellSecond = nullptr;
	bool left = true;
	float speed = 0;
};

void createCar(Car &machines);