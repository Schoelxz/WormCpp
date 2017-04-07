#include <SFML/Graphics.hpp>
#include "TwoDSpace.h"
#include "SnakeMovement.h"
#include "SnakeBody.h"

using namespace sf;
using namespace std;



/**/



int main()
{

	TwoDSpace twoDSpace;
	SnakeMovement snakeMovement;

	Vector2<float> headPos;



	const int numFramesPerSecond = 2;
	sf::Clock clock;
	const float updateInterval = 1.0f / (numFramesPerSecond);

	vector<SnakeBody*> snakeBody;
	

	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	sf::RectangleShape shape;
	sf::RectangleShape shape2;
	sf::RectangleShape shape3;
	sf::RectangleShape shape4;
	sf::RectangleShape shape5;
	shape.setSize(sf::Vector2f(50, 50));
	shape.setFillColor(sf::Color::Blue);
	shape2.setSize(sf::Vector2f(50, 50));
	shape2.setFillColor(sf::Color::Green);
	shape3.setSize(sf::Vector2f(50, 50));
	shape3.setFillColor(sf::Color::Green);
	shape4.setSize(sf::Vector2f(50, 50));
	shape4.setFillColor(sf::Color::Green);
	shape5.setSize(sf::Vector2f(50, 50));
	shape5.setFillColor(sf::Color::Green);
	

	/*Snake needs to be 2blocks atleast to start (2 push_backs!)*/
	snakeBody.push_back(new SnakeBody());
	snakeBody.push_back(new SnakeBody());
	snakeBody[0]->rect.setFillColor(sf::Color::Red);

	sf::Vector2f velocity(100, 0);
	
	float currentTime = 0.0f;

	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		currentTime += dt.asSeconds();
		sf::Event event;
		
		if (currentTime >= updateInterval) //Update Timer
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::KeyPressed)
				{
					snakeMovement.keyboardState[event.key.code] = true;
				}
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				//twoDSpace.updatePlayfield(twoDSpace.playField, twoDSpace.posX, twoDSpace.posY);
				//cout << twoDSpace.posX << " and " << twoDSpace.posY << endl;

				snakeBody.push_back(new SnakeBody());
			}

			snakeMovement.moveSnake(twoDSpace.posX, twoDSpace.posY); //Moves the Digital Snake
			for (int i = 0; i < 256; i++)
				snakeMovement.keyboardState[i] = false;

			shape5.setPosition(shape4.getPosition());
			shape4.setPosition(shape3.getPosition());
			shape3.setPosition(shape2.getPosition());
			shape2.setPosition(shape.getPosition());
			
			/*snakeBody[7]->rect.setPosition(snakeBody[6]->rect.getPosition());
			snakeBody[6]->rect.setPosition(snakeBody[5]->rect.getPosition());
			snakeBody[5]->rect.setPosition(snakeBody[4]->rect.getPosition());
			snakeBody[4]->rect.setPosition(snakeBody[3]->rect.getPosition());
			snakeBody[3]->rect.setPosition(snakeBody[2]->rect.getPosition());
			snakeBody[2]->rect.setPosition(snakeBody[1]->rect.getPosition());
			snakeBody[1]->rect.setPosition(snakeBody[0]->rect.getPosition());*/
			
			if (snakeBody.size() >= 2)
			{
				for (int i = snakeBody.size()-1; i >= 1; i--)
				{
					snakeBody[i]->rect.setPosition(snakeBody[i - 1]->rect.getPosition());
				}
			}
			snakeBody[0]->rect.setPosition((twoDSpace.posX * 50), (twoDSpace.posY * 50)); //Snake Head

			twoDSpace.updatePlayfield(twoDSpace.playField, twoDSpace.posX, twoDSpace.posY);
			currentTime -= updateInterval;
		}

		
		
		
		window.clear();
		if (snakeBody.size() >= 2)
		{
			for (int i = snakeBody.size()-1; i >= 0; i--)
			{
				window.draw(snakeBody[i]->rect);
			}
		}
		
		window.draw(shape);
		//window.draw(shape2);
		//window.draw(shape3);
		//window.draw(shape4);
		//window.draw(shape5);
		window.display();
		

	}
	

	return 0;
}

