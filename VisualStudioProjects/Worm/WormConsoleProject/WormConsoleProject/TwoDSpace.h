#pragma once
#include <iostream>
#include "GameObject.h"

class TwoDSpace
{

public:


	static const int PLAYSIZE = 10;

	int playField[PLAYSIZE][PLAYSIZE]; //2D array representing the playable area

	void updatePlayfield(int playField[][PLAYSIZE], int posX, int posY, vector<SnakeBody*> snakeBody);

	TwoDSpace();
	~TwoDSpace();

private:
	void initField();

	void printField(int playFieldArray[][PLAYSIZE]);


	

};


