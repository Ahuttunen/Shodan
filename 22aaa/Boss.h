#pragma once
#include "Enemy.h"
class Boss:public Enemy
{
public:
	Boss();
	~Boss(void);
	void update(sf::Time deltaTime);
	void loadtextures();
	void Status(){ Health--; }
	void Dead(){ Life = false; }
private:
	bool Life;
	int Health;
	sf::Clock __clock;
};

