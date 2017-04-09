#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace sf;



class SnakeMovement
{
public:

	bool keyboardState[256];
	
	void moveSnake(int& posX, int& posY);
	

	SnakeMovement();
	~SnakeMovement();

private:

	enum SnakeDirection {UP, RIGHT, DOWN, LEFT, START};
	SnakeDirection snakeDir;

	enum MoveKeys {W, A, S, D, NOKEY};
	MoveKeys moveKeys;

	
};

