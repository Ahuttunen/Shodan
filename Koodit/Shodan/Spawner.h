#pragma once
#include "Enemy.h"
#include "Enemy2.h"
#include "Bullet.h"
#include <vector>
#include "Player.h"
#include "Explosion.h"
#include "Boss.h"
#include <SFML/Graphics.hpp>
class Spawner : public GameObjects
{
public:
	Spawner();
	void wave(sf::RenderWindow &myWindow);
	void wave2(sf::RenderWindow &myWindow);
	void update(sf::Time deltatime);
	void checkCollision(Player &p);
	void draw(sf::RenderWindow& myWindow);
	void SpawnForBoss(sf::RenderWindow &myWindow);
	void loadTextures();
private:
	std::vector<Enemy> Enemyz;
	std::vector<Enemy2> Enemyz2;
	std::vector<Explosion>Explositions;
	sf::Clock timer;
	sf::Clock timer2;
	sf::Clock timer3;
	Boss boss;
	bool Draw;
	bool _Boss;

};