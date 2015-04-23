#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include "Backround.h"
#include "Spawner.h"
class Game
{
public:
Game(void);
void run();
~Game(void);
private:

	void processEvents();
	void update(sf::Time deltatime);
	void render();
	void checkCollision();
private:
	sf::RenderWindow myWindow;
	Spawner spawner;
	Player player;
	Backround background;
	Enemy enemy;
	sf::Clock clock;
};
