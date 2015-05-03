#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include<vector>
class Enemy : public GameObjects
{
public:
	Enemy();
	virtual	~Enemy(void);
	virtual	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow& myWindow);
	
	void Attack();
	virtual	void loadTextures();
	virtual	void GettingHit();
	virtual	int GetEnemyHealth();
	bool checkBullet(GameObjects& a);
	void DeathtoEnemy();
	virtual bool Check();
private:
	bool EnemyisAlive;
	int EnemyHealth;
	sf::Clock _clock;
	std::vector<Bullet>shots;
};

