#include <SFML/Graphics.hpp>
#include "figures.h"
#include <iostream>

using namespace std;
using namespace sf;


void createPieces(pieces * pieces) {
	pieces->window = new RenderWindow(VideoMode(SIZE_WINDOW.x, SIZE_WINDOW.y), "Animation's");
	for (int i = 0; i < NUMBER_PIECES;i++) {
		pieces->listPieces.push_back(new RectangleShape(Vector2f(STANDARD_SIZE_PIECES)));
	}
	int i = 0;
	for (pieces->itPieces = pieces->listPieces.begin(); pieces->itPieces != pieces->listPieces.end(); pieces->itPieces++) {
		list<RectangleShape*>::iterator it = pieces->itPieces;
		(*it)->setPosition(INITIAL_COORD_PIECES.x, INITIAL_COORD_PIECES.y + OFFSET_IN_SETTING * i);
		(*it)->setFillColor(COLOR_PIECES);
		(*it)->setOrigin(STANDARD_SIZE_PIECES.x / 2.0f, STANDARD_SIZE_PIECES.y / 2.0f);
		i++;
	}
}

void firstStep(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	if ((*it)->getPosition().x <= RIGHT_BOUNDARY) {
		for (; figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
			list<RectangleShape*>::iterator it = figures->itPieces;
			(*it)->move(HORIZONTAL_SPEED.x, HORIZONTAL_SPEED.y);
		}
	}
	else {
		figures->itPieces = figures->listPieces.begin();
		list<RectangleShape*>::iterator it = figures->itPieces;
		figures->breakpoint = { (*it)->getPosition().x, (*it)->getPosition().y };
		figures->step = 2;
	}
}

void secondStep(pieces * figures) {
	if (figures->count < BORDER){
		int i = 1;
		for (figures->itPieces = figures->listPieces.begin(); figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
			list<RectangleShape*>::iterator it = figures->itPieces;
			(*it)->move(VERTICAL_SPEED.x, VERTICAL_SPEED.y);
			(*it)->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
			if (i % 2 == 0) {
				(*it)->rotate(-0.5f);
			}
			else {
				(*it)->rotate(0.5f);
			}
			i++;
		}
		figures->count += VERTICAL_SPEED.y;
		figures->capacity -= 0.00003f;
	}
	else {
		for (figures->itPieces = figures->listPieces.begin(); figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
			list<RectangleShape*>::iterator it = figures->itPieces;
			(*it)->setRotation(0.0f);
		}
		figures->step = 3;
		figures->count = 0;
	}
}

void thirdStep(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	if ((*it)->getPosition().x > LEFT_BOUNDARY) {
		for (; figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
			list<RectangleShape*>::iterator it = figures->itPieces;
			(*it)->setScale((*it)->getScale().x - figures->reductionFactor, (*it)->getScale().y - figures->reductionFactor);
			(*it)->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y);
		}
	}
	else {
		figures->step = 4;
	}
}

void fourthStep(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	if ((*it)->getPosition().y > UP_BOUNDARY) {
		for (; figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
			list<RectangleShape*>::iterator it = figures->itPieces;
			(*it)->move(figures->accelerationDiagonally.x * DELAY_IN_HORIZONTAL_ACCELERATION, (figures->accelerationDiagonally.y * -1.0f) * DELAY_IN_HORIZONTAL_ACCELERATION);
			(*it)->setFillColor(Color::Color(21, 21, 247, 255 * figures->capacity));
			(*it)->setScale((*it)->getScale().x + figures->reductionFactor, (*it)->getScale().y + figures->reductionFactor);
		}
		figures->capacity += 0.00005f;
	}
	else {
		figures->step = 5;
	}
}

void fifthStep(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	float averageFigure = floor(figures->listPieces.size() / 2.0f - 0.5f);
	if ((*it)->getPosition().x > LEFT_BOUNDARY) {
		if ((*it)->getPosition().x > (SIZE_WINDOW.x - 100.0f + LEFT_BOUNDARY) / 2.0f) {
			for (; figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
				list<RectangleShape*>::iterator it = figures->itPieces;
				(*it)->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * (averageFigure * 1.0f));
				averageFigure -= 1.0f;
			}
		}
		figures->itPieces = figures->listPieces.begin();
		list<RectangleShape*>::iterator it = figures->itPieces;
		if (((*it)->getPosition().x <= (SIZE_WINDOW.x - 100.0f + LEFT_BOUNDARY) / 2.0f) && (*it)->getPosition().x > LEFT_BOUNDARY) {
 			for (; figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
				list<RectangleShape*>::iterator it = figures->itPieces;
				(*it)->move(HORIZONTAL_SPEED.x * -1.0f, HORIZONTAL_SPEED.y + RATE_DISPLACEMENT * (averageFigure * -1.0f));
				averageFigure -= 1.0f;
			}
		}

	}
	else {
		figures->step = 1;
	}

}

