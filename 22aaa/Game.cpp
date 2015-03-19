#include "Game.h"


Game::Game(void):myWindow(sf::VideoMode(1280, 720), "Shodan", sf::Style::Close)
{
	//Videomodessa voi muokata resolutiota 
}

//sassssssssss
Game::~Game(void)
{
	
}
void Game::run()
{
	//Vaatii vielä aika paljon viilausta

	//HUOM tätä kutsutaan mainista
	sf::Clock a;
	sf::Time LastUpdate = sf::Time::Zero;
	while (myWindow.isOpen())
	{
		processEvents();
		
		LastUpdate += a.restart();
		sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	
		while (LastUpdate > TimePerFrame)
		{	
		LastUpdate -= TimePerFrame;
		player.update(TimePerFrame);
		enemy.update(TimePerFrame);
		processEvents();
		}
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
	enemy.DrawEnemy(myWindow);
	myWindow.display();

}
