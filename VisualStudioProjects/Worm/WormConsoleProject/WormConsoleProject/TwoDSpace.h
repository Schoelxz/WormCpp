#pragma once
#include <iostream>
#include "SnakeBody.h"

class TwoDSpace
{

public:

	static const int PLAYSIZE = 10;

	int playField[PLAYSIZE][PLAYSIZE]; //2D array representing the playable area

	vector<SnakeBody*> snakeBody;

	void updatePlayfield(int playField[][PLAYSIZE], int posX, int posY);

	TwoDSpace();
	~TwoDSpace();

private:
	void initField();

	void printField(int playFieldArray[][PLAYSIZE]);


	

};


