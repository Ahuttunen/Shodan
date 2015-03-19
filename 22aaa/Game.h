#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "GameObjects.h"
#include "Enemy.h"

class Game
{
public:
	Game(void);
	~Game(void);
	void run();
	void processEvents();
	void render();
private:
	
	sf::RenderWindow myWindow;
	Player player;
	Enemy enemy;
	sf::Clock a;
};
