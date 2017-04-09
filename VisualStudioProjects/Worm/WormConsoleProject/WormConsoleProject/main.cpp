#include <SFML/Graphics.hpp>
#include "TwoDSpace.h"

TwoDSpace twoDSpace;

using namespace sf;
using namespace std;

void draw(int asdf[][twoDSpace.PLAYSIZE])
{
	for (int i = 0; i < twoDSpace.PLAYSIZE; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < twoDSpace.PLAYSIZE; j++)
		{
			std::cout << asdf[i][j];

		}
	}
}
void updatePlayfield(int playField[][twoDSpace.PLAYSIZE], int posX, int posY)
{
	for (int i = 0; i < twoDSpace.PLAYSIZE; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < twoDSpace.PLAYSIZE; j++)
		{
			if (!(posX == i && posY == j))
				playField[i][j] = 0;
			else
				playField[i][j] = 1;
			std::cout << playField[i][j];

		}
	}
	
}

int main()
{
	sf::Clock clock;


	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Green);
	
	

	sf::Vector2f velocity(100, 0);

	int playerPositionX;
	int playerPositionY;


	int flag1 = false;
	int flag2 = false;
	int flag3 = false;
	int flag4 = false;
	int flag5 = false;

	int posX = 0;
	int posY = 0;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (posX > 29)
			posX = 29;
		if (posX < 0)
			posX = 0;
		if (posY > 29)
			posY = 29;
		if (posY < 0)
			posY = 0;
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !flag1)
		{
			posY -= 1;
			cout << "W" << endl;
			flag1 = true;
		}
		else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
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
			posX += 1;
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
			updatePlayfield(twoDSpace.playField, posY, posX);
			cout << "SPACE" << endl;
			flag5 = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			flag5 = false;
		
		window.clear();
		window.draw(shape);
		window.display();
		

	}

	return 0;
}

