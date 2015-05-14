#pragma once
#include "Enemy.h"
class Enemy2:public Enemy
{
public:
	Enemy2();
	~Enemy2(void);

	void loadTextures();
	void update(sf::Time deltatime);
	void GettingHit();
	int GetEnemyHealth();
	bool CheckEnemy();
private:
	bool EnemyisAlive;
	int EnemyHealth;
	sf::Clock _clock;
};

