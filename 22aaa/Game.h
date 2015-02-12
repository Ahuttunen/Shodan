#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "GameObjects.h"


class Game
{
public:
	Game(void);
	~Game();
	void run();
private:
	void processEvents();
	void render();
private:
	sf::RenderWindow myWindow;
	Player player;

};
