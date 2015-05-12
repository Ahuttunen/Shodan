#pragma once
#include "Enemy.h"
#include "Bullet.h"
#include <vector>
#include "Player.h"
#include "Explosion.h"
#include <SFML/Graphics.hpp>
class Spawner: public GameObjects
{
public:
	Spawner();
	void wave(sf::RenderWindow &myWindow);
	void update(sf::Time deltatime);
	void checkCollision(Player &p);
	void draw(sf::RenderWindow& myWindow);
private:
	std::vector<Enemy> Enemyz;
	std::vector<Explosion>Explositions;
	sf::Clock timer;
	sf::Clock timer2;
	bool Draw;
};

