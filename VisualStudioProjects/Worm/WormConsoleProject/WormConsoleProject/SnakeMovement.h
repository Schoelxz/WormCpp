#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace sf;



class SnakeMovement
{
public:

	int posX = 0;
	int posY = 0;

	static const int KEYBOARDSTATES = 256;

	bool keyboardState[KEYBOARDSTATES];
	
	void moveSnake(int& posX, int& posY);
	
	SnakeMovement();
	~SnakeMovement();

	
private:

	enum SnakeDirection {UP, RIGHT, DOWN, LEFT, START};
	SnakeDirection snakeDir;

	enum MoveKeys {W, A, S, D, NOKEY};
	MoveKeys moveKeys;

	
};

