#include "system.h"
#include <iostream>



void turnGears(mySystem *sys) {
	sys->firstGears->rotate(10);
	sys->secondGears->rotate(-10);
}

void createSystem(mySystem *sys) {
	sys->window = new RenderWindow(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "lab 7.3 | Garanin Tim");

	sys->mintyImage = new Image;
	sys->mintySprite = new Sprite;
	sys->mintyTexture = new Texture;

	sys->mintyImage->loadFromFile("images/minty.png");
	sys->mintyImage->createMaskFromColor(Color::White);
	sys->mintyTexture->loadFromImage(*sys->mintyImage);
	sys->mintyTexture->isSmooth();
	sys->mintySprite->setTexture(*sys->mintyTexture);
	sys->mintySprite->setOrigin(sys->mintyTexture->getSize().x / 2, 0);
	sys->mintySprite->setPosition(POSITION_MINTY.x, POSITION_MINTY.y);
	
	sys->firstGearsImage = new Image;
	sys->firstGearsTexture = new Texture;
	sys->firstGears = new Sprite;

	sys->secondGearsImage = new Image;
	sys->secondGearsTexture = new Texture;
	sys->secondGears = new Sprite;

	sys->firstGearsImage->loadFromFile("images/firstGears.png");
	sys->firstGearsImage->createMaskFromColor(Color::White);
	sys->firstGearsTexture->loadFromImage(*sys->firstGearsImage);
	sys->firstGearsTexture->isSmooth();
	sys->firstGears->setTexture(*sys->firstGearsTexture);
	sys->firstGears->setOrigin(sys->firstGearsTexture->getSize().x / 2.0f, sys->firstGearsTexture->getSize().y / 2.0f);
	sys->firstGears->setPosition(POSITION_MINTY.x + (sys->mintyTexture->getSize().x / 2.0f), POSITION_MINTY.y + sys->mintyTexture->getSize().y + (sys->firstGearsTexture->getSize().y / 2.0f) - 10.0f);


	sys->secondGearsImage->loadFromFile("images/secondGears.png");
	sys->secondGearsImage->createMaskFromColor(Color::White);
	sys->secondGearsTexture->loadFromImage(*sys->secondGearsImage);
	sys->secondGearsTexture->isSmooth();
	sys->secondGears->setTexture(*sys->secondGearsTexture);
	sys->secondGears->setOrigin(sys->secondGearsTexture->getSize().x / 2.0f, sys->secondGearsTexture->getSize().y / 2.0f);
	sys->secondGears->setPosition(sys->firstGears->getPosition().x + sys->secondGearsTexture->getSize().x / 2.0f + sys->secondGearsTexture->getSize().x / 4.0f, sys->firstGears->getPosition().y + sys->secondGearsTexture->getSize().y / 2.0f + 10.0f);


}

void swingingPendulum(mySystem *sys) {
	if (sys->counter < MAXIMUM_DEVIATION && !sys->reversed && !sys->left) {
		sys->mintySprite->rotate(0 + (FACTOR_ROTATION * (MAXIMUM_DEVIATION - sys->counter)));
		sys->counter++;
		sys->intersection = false;
	}
	else if (sys->counter == MAXIMUM_DEVIATION && !sys->left && !sys->reversed) {
		sys->reversed = true;
		sys->counter--;
	}
	else if (sys->counter > 0 && sys->reversed && !sys->left ) {
		sys->mintySprite->rotate(0 - (FACTOR_ROTATION * (MAXIMUM_DEVIATION - sys->counter)));
		sys->counter--;
		sys->intersection = false;
	}
	else if (sys->counter == 0 && !sys->left && sys->reversed) {
		sys->left = true;
		sys->reversed = false;
		sys->intersection = true;
	}
	else if (sys->counter < MAXIMUM_DEVIATION && !sys->reversed && sys->left) {
		sys->mintySprite->rotate(0 - (FACTOR_ROTATION * (MAXIMUM_DEVIATION - sys->counter)));
		sys->counter++;
		sys->intersection = false;
	}
	else if (sys->counter == MAXIMUM_DEVIATION && sys->left && !sys->reversed) {
		sys->reversed = true;
		sys->counter--;
	}
	else if (sys->counter > 0 && sys->reversed && sys->left) {
		sys->mintySprite->rotate(0 + (FACTOR_ROTATION * (MAXIMUM_DEVIATION - sys->counter)));
		sys->counter--;
	}
	else if (sys->counter == 0 && sys->left && sys->reversed) {
		sys->left = false;
		sys->reversed = false;
		sys->intersection = true;
	}
}

void operationSystem(mySystem *sys) {
	swingingPendulum(sys);
	if (sys->intersection) {
		turnGears(sys);
	}
}