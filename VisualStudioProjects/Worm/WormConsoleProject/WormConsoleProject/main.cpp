#include <SFML/Graphics.hpp>
#include "TwoDSpace.h"
#include "SnakeMovement.h"
#include "SnakeBody.h"
#include "Pellets.h"

using namespace sf;
using namespace std;

class Game
{
public:
	/*
	SAKNAR ARV OCH POLYPHORMISM!
	*/
	void Run()
	{
		while (true)
		{
			TwoDSpace twoDSpace;
			SnakeMovement snakeMovement;
			Pellets* pellet = new Pellets();

			bool lostGame = false;

			const int numFramesPerSecond = 6;
			sf::Clock clock;
			const float updateInterval = 1.0f / (numFramesPerSecond);
			float currentTime = 0.0f;

			sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");

			twoDSpace.snakeBody.push_back(new SnakeBody()); //Firdt Paert of snake added (head)
			twoDSpace.snakeBody[0]->rect.setFillColor(sf::Color::Red); //head is red

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

					snakeMovement.moveSnake(twoDSpace.snakeBody[0]->posX, twoDSpace.snakeBody[0]->posY); //Moves the Digital Snake head

					for (int i = 0; i < snakeMovement.KEYBOARDSTATES; i++)
						snakeMovement.keyboardState[i] = false;

					//If Pellet hits snake body (not head), reset pellet
					for (int i = 1; i < twoDSpace.snakeBody.size(); i++)
						if (twoDSpace.snakeBody[i]->rect.getGlobalBounds().intersects(pellet->pellet.getGlobalBounds()))
						{
							delete pellet;
							pellet = new Pellets();
						}

					//Pellet hits snake face? Grow larger, get new pellet
					if (twoDSpace.snakeBody[0]->rect.getGlobalBounds().intersects(pellet->pellet.getGlobalBounds()))
					{
						delete pellet;
						pellet = new Pellets();
						twoDSpace.snakeBody.push_back(new SnakeBody());
					}

					//SnakeMovement Visual:
					if (twoDSpace.snakeBody.size() >= 2)
					{
						for (int i = twoDSpace.snakeBody.size() - 1; i >= 1; i--)
						{
							twoDSpace.snakeBody[i]->rect.setPosition(twoDSpace.snakeBody[i - 1]->rect.getPosition());
						}
					}
					twoDSpace.snakeBody[0]->rect.setPosition((twoDSpace.snakeBody[0]->posX * 50), (twoDSpace.snakeBody[0]->posY * 50)); //Snake Head

																																		//For every snakebody; If snakeHead collides with snakeBody; Turn snakeHead Blue;.

					//---


					twoDSpace.updatePlayfield(twoDSpace.playField, twoDSpace.snakeBody[0]->posX, twoDSpace.snakeBody[0]->posY);
					currentTime -= updateInterval;
				}
				//---UpdateInterval End---

				for (int i = twoDSpace.snakeBody.size() - 1; i >= 1; i--) //all snakeparts except for the head
					if (twoDSpace.snakeBody[0]->rect.getGlobalBounds().intersects(twoDSpace.snakeBody[i]->rect.getGlobalBounds()))
					{
						twoDSpace.snakeBody[0]->rect.setFillColor(sf::Color::Blue);
						lostGame = true;
					}

				window.clear();
				if (twoDSpace.snakeBody.size() >= 1)
				{
					for (int i = twoDSpace.snakeBody.size() - 1; i >= 0; i--)
					{
						window.draw(twoDSpace.snakeBody[i]->rect);
					}
				}
				window.draw(pellet->pellet);
				window.display();

				if (lostGame == true)
					break;
			}//---Game Loop End---

			cout << endl;
			cout << "You just hit yourself! Try again? y/n" << endl;
			char answer;
			cin >> answer;

			if (answer == 'y')
				cout << "yes" << endl;
			else if (answer == 'n')
				break;

		}
	}

};


int main()
{
	Game game;
	game.Run();
	

	return 0;
}
