#include "Game.h"


Game::Game(void):myWindow(sf::VideoMode(1280, 720), "Melkein valmis peli", sf::Style::Close)
{

}


Game::~Game()
{
	
}
void Game::run()
{
	/*sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;*/
	while (myWindow.isOpen())
	{
		
		processEvents();
		render();
	}

}
void Game::processEvents()
{
	sf::Event event;
	while (myWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			{
				player.PlayerInputs(event.key.code,false);
				if (event.key.code == sf::Keyboard::Escape)
				{
					myWindow.close();
				}
				break;
			}
			case sf::Event::KeyReleased:
			{
				player.PlayerInputs(event.key.code,true);
				break;
			}
			case sf::Event::Closed:
			{
				myWindow.close();
				break;
			}
		}
	}
}
void Game::render()
{
	myWindow.clear();
	player.draw(myWindow);
	myWindow.display();
}
