#include "car.h"

void createCar(Car &machines) {
	machines.imageCar = new Image;
	machines.imageWheels = new Image;
	machines.textureCar = new Texture;
	machines.textureWhells = new Texture;
	machines.spriteCar = new Sprite;
	machines.spriteWhellFirst = new Sprite;
	machines.spriteWhellSecond = new Sprite;
	machines.imageCar->loadFromFile("images/car.png");
	machines.imageWheels->loadFromFile("images/whell.png");
	machines.imageCar->createMaskFromColor(Color::White);
	machines.textureCar->loadFromImage(*machines.imageCar);
	machines.textureWhells->loadFromImage(*machines.imageWheels);
	machines.spriteCar->setTexture(*machines.textureCar);
	machines.spriteWhellFirst->setTexture(*machines.textureWhells);
	machines.spriteWhellSecond->setTexture(*machines.textureWhells);
	machines.spriteCar->setPosition(COORDINATES_START_MACHINES.x, COORDINATES_START_MACHINES.y);
	machines.spriteCar->setOrigin(machines.imageCar->getSize().x / 2.0f, machines.imageCar->getSize().y / 2.0f);
	machines.spriteWhellFirst->setOrigin(machines.imageWheels->getSize().x / 2.0f, machines.imageWheels->getSize().y / 2.0f);
	machines.spriteWhellSecond->setPosition(COORDINATES_START_SECOND_WHEEL.x, COORDINATES_START_SECOND_WHEEL.y);
	machines.spriteWhellFirst->setScale(0.065f, 0.065f);
	machines.spriteWhellSecond->setOrigin(machines.imageWheels->getSize().x / 2.0f, machines.imageWheels->getSize().y / 2.0f);
	machines.spriteWhellFirst->setPosition(COORDINATES_START_FIRST_WHEEL.x, COORDINATES_START_FIRST_WHEEL.y);
	machines.spriteWhellSecond->setScale(0.065f, 0.065f);
}