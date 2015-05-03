#pragma once
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include "Player.h"
class Spawner
{
public:
	Spawner();
	void wave(sf::RenderWindow &myWindow);
	void update(sf::Time deltatime);
	void checkCollision(Player &p);
private:
	std::vector<Enemy> Enemyz;
	sf::Clock timer;
};

