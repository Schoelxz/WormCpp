#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class SnakeBody
{
public:

	int posX = 0;
	int posY = 0;

	RectangleShape rect;


	SnakeBody();
	~SnakeBody();
};

