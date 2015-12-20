#pragma once
#include "config.h"
#include <vector>
#include <list>

using namespace std;
using namespace sf;

struct pieces {
	RenderWindow *window;
	unsigned int step = 1;
	list<RectangleShape*> listPieces;
	list<RectangleShape*>::iterator itPieces;
	int i = 0;
	bool determineReductionFactor = true;
	float reductionFactor;
	Vector2f breakpoint;
	Vector2f accelerationDiagonally;
	unsigned int distanceBetweenFigures;
	float capacity = 1.0f;
	bool useBreakpoint = true;
	float count = 0;
	
};

void createPieces(pieces * pieces);
void firstStep(pieces * pieces);
void secondStep(pieces * pieces);
void thirdStep(pieces * pieces);
void fourthStep(pieces * pieces);
void fifthStep(pieces * pieces);