#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

Pellets::Pellets()
{
	posX = rand() % 10 * 50;
	posY = rand() % 10 * 50;

	pellet.setRadius(25.0f);
	pellet.setFillColor(sf::Color::Yellow);

	pellet.setPosition(posX, posY);
}

SnakeBody::SnakeBody()
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(Color::Green);
}
