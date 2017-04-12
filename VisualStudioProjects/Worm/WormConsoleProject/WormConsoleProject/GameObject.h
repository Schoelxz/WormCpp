#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class GameObject
{
public:
	
	GameObject();
	~GameObject();

	void objectCreated() { cout << "object created" << endl; };

	int posX = 0;
	int posY = 0;
};

class Pellets : public GameObject
{
public:
	CircleShape pellet;

	void objectCreated() { cout << "pellet created" << endl; };

	Pellets();
};

class SnakeBody : public GameObject
{
public:
	RectangleShape rect;

	void objectCreated() { cout << "snake body created" << endl; };

	SnakeBody();
};
