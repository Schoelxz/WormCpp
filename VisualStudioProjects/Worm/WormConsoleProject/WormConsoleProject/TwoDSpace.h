#pragma once
#include <iostream>
class TwoDSpace
{

public:

	static const int PLAYSIZE = 15;

	int posX = 0;
	int posY = 0;

	int playField[PLAYSIZE][PLAYSIZE];

	TwoDSpace();
	~TwoDSpace();
};

