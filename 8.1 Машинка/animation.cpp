#include "animation.h"

void draw(Car &machines, RenderWindow &window) {
	window.clear(Color::White);
	window.draw(*machines.spriteCar);
	window.draw(*machines.spriteWhellFirst);
	window.draw(*machines.spriteWhellSecond);
	window.display();
}

void movingMachines(Car &machines) {
	if (machines.spriteCar->getPosition().x >= WINDOW_SIZE.x / 2.0f && machines.left) {
		machines.spriteCar->move(0 - machines.speed, 0);
		machines.spriteWhellFirst->move(0 - machines.speed, 0);
		machines.spriteWhellSecond->move(0 - machines.speed, 0);
		machines.spriteWhellFirst->rotate(0 - machines.speed);
		machines.spriteWhellSecond->rotate(0 - machines.speed);
		machines.speed += INDEX_INCREASE_RATE;
	}
	else if (machines.speed > 0 && machines.spriteCar->getPosition().x < WINDOW_SIZE.x / 2.0f && machines.left) {
		machines.spriteCar->move(0 - machines.speed, 0);
		machines.spriteWhellFirst->move(0 - machines.speed, 0);
		machines.spriteWhellSecond->move(0 - machines.speed, 0);
		machines.spriteWhellFirst->rotate(0 - machines.speed);
		machines.spriteWhellSecond->rotate(0 - machines.speed);
		machines.speed -= INDEX_INCREASE_RATE;

		if (machines.speed < 0) {
			machines.left = false;
		}
	}

	else if (machines.spriteCar->getPosition().x <= WINDOW_SIZE.x / 2.0f && !machines.left) {
		machines.spriteCar->move(0 + machines.speed, 0);
		machines.spriteWhellFirst->move(0 + machines.speed, 0);
		machines.spriteWhellSecond->move(0 + machines.speed, 0);
		machines.spriteWhellFirst->rotate(0 + machines.speed);
		machines.spriteWhellSecond->rotate(0 + machines.speed);
		machines.speed += INDEX_INCREASE_RATE;
	}
	else if (machines.speed > 0 && machines.spriteCar->getPosition().x > WINDOW_SIZE.x / 2.0f && !machines.left) {
		machines.spriteCar->move(0 + machines.speed, 0);
		machines.spriteWhellFirst->move(0 + machines.speed, 0);
		machines.spriteWhellSecond->move(0 + machines.speed, 0);
		machines.spriteWhellFirst->rotate(0 + machines.speed);
		machines.spriteWhellSecond->rotate(0 + machines.speed);
		machines.speed -= INDEX_INCREASE_RATE;
		if (machines.speed < 0) {
			machines.left = true;
		}
	}
}