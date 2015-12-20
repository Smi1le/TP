#include <SFML/Graphics.hpp>
#include "figures.h"
#include <iostream>


using namespace std;
using namespace sf;

void determinationReduction(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	figures->reductionFactor = (1 - (RESIZING_PIECES.x / STANDARD_SIZE_PIECES.x)) / ((*it)->getPosition().x / HORIZONTAL_SPEED.x);
	figures->determineReductionFactor = false;
}

void delaysDefinitionHorizAccel(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	figures->accelerationDiagonally = { (float(SIZE_WINDOW.x) - 100.0f - LEFT_BOUNDARY) / (float(SIZE_WINDOW.y) - LEFT_BOUNDARY - (SIZE_WINDOW.y - (*it)->getPosition().y)), 1.0f };
}

void usingBreakpoint(pieces * figures) {
	figures->itPieces = figures->listPieces.begin();
	list<RectangleShape*>::iterator it = figures->itPieces;
	figures->breakpoint = { (*it)->getPosition().x, (*it)->getPosition().y };
	figures->useBreakpoint = false;
}

void drawing(RenderWindow &window, pieces *figures) {
	window.clear(Color::White);


	for (figures->itPieces = figures->listPieces.begin(); figures->itPieces != figures->listPieces.end(); figures->itPieces++) {
		list<RectangleShape*>::iterator it = figures->itPieces;
		window.draw(**it);
	}
	window.display();
}

void basicCycle(pieces * figures, RenderWindow &window) {
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (figures->step == 1) {
			if (!figures->useBreakpoint) {
				figures->useBreakpoint = true;
			}
			firstStep(figures);
		}
		else if (figures->step == 2) {
			secondStep(figures);
		}
		else if (figures->step == 3) {
			if (figures->determineReductionFactor) {
				determinationReduction(figures);
			}
			thirdStep(figures);
		}
		else if (figures->step == 4) {
			if (!figures->determineReductionFactor) {
				figures->determineReductionFactor = true;
				delaysDefinitionHorizAccel(figures);
			}
			fourthStep(figures);
		}
		else if (figures->step == 5) {
			if (figures->useBreakpoint) {
				usingBreakpoint(figures);
			}
			fifthStep(figures);
		}
		drawing(window, figures);
	}
}

void removal(pieces * figures) {
	delete figures->window;
}

int main()
{
	pieces *figures = new pieces;
	createPieces(figures);
	RenderWindow & window = *figures->window;
	basicCycle(figures, window);
	removal(figures);
	delete figures;
	return 0;
}