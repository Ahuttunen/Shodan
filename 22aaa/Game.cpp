#include "Game.h"


Game::Game(void) :myWindow(sf::VideoMode(640, 640), "Shodan", sf::Style::Close) {}

void Game::run()
{
	sf::Clock clock;
	sf::Time LastUpdate = sf::Time::Zero;
	while (myWindow.isOpen())
	{
		processEvents();
		LastUpdate += clock.restart();
		sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	
		while (LastUpdate > TimePerFrame)
		{	
		LastUpdate -= TimePerFrame;
		processEvents();
		update(TimePerFrame);
		spawner.update(TimePerFrame);
		player.update(TimePerFrame);
		player.CannonRotation(myWindow);
		background.Scroll();
		}
		render();
	}
}
void Game::update(sf::Time deltatime)
{}
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
			case sf::Event::MouseButtonReleased:
			{
				player.PlayerMouseInputs(event.mouseButton.button, true);
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
	myWindow.setVerticalSyncEnabled(true);
	myWindow.clear();
	background.draw(myWindow);	
	spawner.wave(myWindow);
	player.draw(myWindow);
	myWindow.display();
}
Game::~Game(void)
{}
//void Game::checkCollision()
//{
//	spa.checkCollision(player);
//}
