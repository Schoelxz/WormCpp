#include "Pellets.h"



Pellets::Pellets()
{
	posX = rand() % 10 * 50;
	posY = rand() % 10 * 50;

	pellet.setRadius(25.0f);
	pellet.setFillColor(sf::Color::Yellow);

	pellet.setPosition(posX, posY);
}


Pellets::~Pellets()
{
}
