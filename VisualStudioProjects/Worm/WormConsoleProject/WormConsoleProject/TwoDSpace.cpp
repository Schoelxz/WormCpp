#include "TwoDSpace.h"



TwoDSpace::TwoDSpace()
{
	//PlayFields initial values
	for (int i = 0; i < PLAYSIZE; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < PLAYSIZE; j++)
		{
			if (!(posX == i && posY == j))
				playField[i][j] = 0;
			else
				playField[i][j] = 1;
			std::cout << playField[i][j];
		}
	}
	/*std:cout << endl;
	std::cout << posX << "," << posY << endl;*/



}


TwoDSpace::~TwoDSpace()
{
}
