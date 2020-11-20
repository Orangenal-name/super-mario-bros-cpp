#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Player.hpp"
#include "Platform.hpp"

const int winWidth = 1000;
const int winHeight = 1000;
const int halfWinHeight = winHeight / 2;
const int halfWinWidth = winWidth / 2;

using namespace std;

int main()
{

	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Super Mario Bros. 1");

	bool keyUp, keyDown, keyLeft, keyRight;

	keyUp, keyDown, keyLeft, keyRight = false;

	int levelArray[10][10] = { {0,0,0,0,0,0,0,0,0,0},
							   {0,0,0,0,0,0,0,0,0,0},
							   {0,0,0,0,0,0,0,0,0,0},
							   {0,0,0,0,0,0,0,0,0,0},
							   {0,0,0,0,0,0,0,0,0,0},
							   {0,0,0,0,0,0,0,0,0,0},
							   {1,1,0,1,1,0,0,0,0,0},
							   {1,0,0,0,0,1,0,0,0,0},
							   {0,0,0,0,0,0,1,0,0,0},
							   {1,1,1,1,1,1,1,1,1,1} };

	Platform level[100];

	int sizeOfLevel = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (levelArray[i][j] == 1)
			{
				level[sizeOfLevel].init("data/images/block.png", j * 16, i * 16, 16, 16);
 				cout << j * 16 << "," << i * 16 << endl;
				sizeOfLevel++;
			}
		}
	}

	Player player("data/images/mario.png", 0, 128, 13, 16);

	player.setOrigin(sf::Vector2f(211, 0));

	sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(winWidth, winHeight));

	view.zoom(0.25);
	sf::Clock gameClock;
	
	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		float deltaTime = gameClock.getElapsedTime().asSeconds();

		player.update(keyUp, keyDown, keyLeft, keyRight, deltaTime);
		view.setCenter(sf::Vector2f(player.m_centrePos[0], player.m_centrePos[1]));
		gameClock.restart().asSeconds();
		window.setView(view);

		window.clear(sf::Color(99, 173, 255));

		for (int i = 0; i < sizeOfLevel; i++)
		{
			window.draw(level[i]);
			
		}

		window.draw(player);

		window.display();
	}
}