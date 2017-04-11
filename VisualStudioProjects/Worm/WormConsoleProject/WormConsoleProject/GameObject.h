#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class GameObject
{
public:
	GameObject();
	~GameObject();

	int posX = 0;
	int posY = 0;
};

class Pellets : public GameObject
{
public:
	sf::CircleShape pellet;

	Pellets();
};

class SnakeBody : public GameObject
{
public:
	RectangleShape rect;

	SnakeBody();
};
