#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"
#include <list>

using namespace sf;
using namespace std;

struct mySystem {
	RenderWindow *window;
	Image *mintyImage = nullptr;
	Texture *mintyTexture = nullptr;
	Sprite *mintySprite = nullptr;
	int counter = 0;
	bool reversed = false;
	bool left = false;
	Texture *firstGearsTexture = nullptr;
	Texture *secondGearsTexture = nullptr;
	Image *firstGearsImage = nullptr;
	Image *secondGearsImage = nullptr;
	Sprite *firstGears = nullptr;
	Sprite *secondGears = nullptr;
	bool intersection = false;
	int timer = 0;

};

void createSystem(mySystem &sys);
void operationSystem(mySystem &sys);