#pragma once
#include <SFML/Graphics.hpp>

class Pellets
{
private:
	int posX = 0;
	int posY = 0;

public:

	sf::CircleShape pellet;

	Pellets();
	~Pellets();
};

