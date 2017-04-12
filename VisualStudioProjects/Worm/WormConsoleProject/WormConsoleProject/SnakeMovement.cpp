#include "SnakeMovement.h"

void SnakeMovement::moveSnake(int& posX, int& posY)
{
		if (keyboardState[sf::Keyboard::D] == true)
			moveKeys = D;
		if (keyboardState[sf::Keyboard::W] == true)
			moveKeys = W;;
		if (keyboardState[sf::Keyboard::S] == true)
			moveKeys = S;
		if (keyboardState[sf::Keyboard::A] == true)
			moveKeys = A;
		
	switch (moveKeys)
	{
	case W:
		snakeDir = UP;
		cout << "W" << endl;
		moveKeys = NOKEY;
		break;
	case A:
		snakeDir = LEFT;
		cout << "A" << endl;
		moveKeys = NOKEY;
		break;
	case S:
		snakeDir = DOWN;
		cout << "S" << endl;
		moveKeys = NOKEY;
		break;
	case D:
		snakeDir = RIGHT;
		cout << "D" << endl;
		moveKeys = NOKEY;
		break;
	case NOKEY:
		break;
	default:
		break;
	}

	switch (snakeDir)
	{
	case UP:
		posY -= 1;
		cout << "UP";
		break;
	case LEFT:
		posX -= 1;
		cout << "LEFT";
		break;
	case DOWN:
		posY += 1;
		cout << "DOWN";
		break;
	case RIGHT:
		posX += 1;
		cout << "RIGHT";
		break;
	case START:
		break;
	default:
		break;
	}
	
	if (posX >= 10)
		posX = 0;
	if (posX < 0)
		posX = 9;
	if (posY >= 10)
		posY = 0;
	if (posY < 0)
		posY = 9;
}

SnakeMovement::SnakeMovement()
{
	for (int i = 0; i < KEYBOARDSTATES; i++)
		keyboardState[i] = false;

	snakeDir = START;
	moveKeys = NOKEY;
}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !flag1)
	{
		posY -= 1;
		cout << "W" << endl;
		flag1 = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		flag1 = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !flag2)
	{
		posX -= 1;
		cout << "A" << endl;
		flag2 = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		flag2 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !flag3)
	{
		posY += 1;
		cout << "S" << endl;
		flag3 = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		flag3 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !flag4)
	{

		cout << "D" << endl;
		flag4 = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		flag4 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !flag5)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		//updatePlayfield(playField, posY, posX);
		cout << "SPACE" << endl;
		flag5 = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		flag5 = false;
}*/


SnakeMovement::~SnakeMovement()
{
}
