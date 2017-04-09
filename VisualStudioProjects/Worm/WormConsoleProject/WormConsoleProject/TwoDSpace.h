#pragma once
#include <iostream>
class TwoDSpace
{

public:

	

	

	static const int PLAYSIZE = 10;

	int playField[PLAYSIZE][PLAYSIZE]; //2D array representing the playable area

	int posX = 0;
	int posY = 0;

	void updatePlayfield(int playField[][PLAYSIZE], int posX, int posY);

	TwoDSpace();
	~TwoDSpace();

private:
	void initField();

	void printField(int playFieldArray[][PLAYSIZE]);


	

};


