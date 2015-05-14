#include "Game.h"


Game::Game(void) :myWindow(sf::VideoMode(800, 600), "Shodan", sf::Style::Close) {}
Game::~Game(void){}
void Game::run()
{
	
	sf::Time LastUpdate = sf::Time::Zero;
<<<<<<< HEAD
<<<<<<< HEAD
	music.openFromFile("Sounds/Backgroundmsc.ogg");
	music.setLoop(true);
	music.setVolume(25);
	music.play();
=======
	//ÄÄNIÄ
	//music.openFromFile("Music/Backgroundmsc.ogg");
	//music.setLoop(true);
	//music.play();
>>>>>>> origin/master
=======
	
>>>>>>> 060978ccc3c01caf335b79130b1b821768eae778
	while (myWindow.isOpen())
	{
		processEvents();
		LastUpdate += clock.restart();
		sf::Time TimePerFrame = sf::seconds(1.f /60.f);
		while (LastUpdate > TimePerFrame)
		{	
		LastUpdate -= TimePerFrame;
		processEvents();
		update(TimePerFrame);
		spawner.update(TimePerFrame);
		player.update(TimePerFrame);
		player.GeRot();
		player.GetBulletForCannon();
		player.CannonRotation(myWindow);
		player.fire(myWindow);
		background.Scroll();
		CollisionChecker();
		
		}
		render();

	
	}
}
void Game::update(sf::Time deltatime){}
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
	
	myWindow.clear();
	background.draw(myWindow);
	if (clock2.getElapsedTime() < sf::seconds(20))
	{
spawner.wave(myWindow);
	}
	
	if (clock2.getElapsedTime() > sf::seconds(20))
	{

		spawner.wave2(myWindow);

	}
	if (clock2.getElapsedTime() > sf::seconds(40))
	{
			spawner.SpawnForBoss(myWindow);
	}
	
	spawner.draw(myWindow);
	player.draw(myWindow);
	myWindow.display();
	myWindow.setVerticalSyncEnabled(true);
}

void Game::	CollisionChecker()
{
	spawner.checkCollision(player);
}
