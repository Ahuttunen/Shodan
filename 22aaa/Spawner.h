#pragma once
#include "Enemy.h"
#include "Bullet.h"
#include <vector>

class Spawner
{
public:
	Spawner();
	void wave(sf::RenderWindow &myWindow);
	void update(sf::Time deltatime);
	void checkCollision();
private:
	std::vector<Enemy> Enemyz;
	sf::Clock timer;
};

