#include "TwoDSpace.h"

void TwoDSpace::initField()
{
	//The PlayFields initial values created:
	for (int i = 0; i < PLAYSIZE; i++)
	{
		std::cout << std::endl; //new row
		for (int j = 0; j < PLAYSIZE; j++)
		{
			playField[i][j] = 0;
		}
	}
	playField[0][0] = 1; //start pos
}

void TwoDSpace::printField(int playFieldArray[][PLAYSIZE])
{
	for (int i = 0; i < PLAYSIZE; i++)
	{
		std::cout << std::endl;

		for (int j = 0; j < PLAYSIZE; j++)
		{
			std::cout << playFieldArray[i][j] << " ";

		}
	}
}

void TwoDSpace::updatePlayfield(int playField[][PLAYSIZE], int posX, int posY)
{
	for (int i = 0; i < PLAYSIZE; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < PLAYSIZE; j++)
		{
			if (!(posX == i && posY == j))
				playField[j][i] = 0; 
			else						//i and j reversed to make movement make sense!!! (bad?)
				playField[j][i] = 1;
		}
	}
	printField(playField);

}

TwoDSpace::TwoDSpace()
{
	initField();
	printField(playField);
}


TwoDSpace::~TwoDSpace()
{
}
