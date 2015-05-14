#pragma once
#include "Enemy.h"
class Boss :public Enemy
{
public:
	Boss();
	~Boss(void);
	void update(sf::Time deltaTime);
	void Dead();
	int GetBossHealth();
	void BossGettingHit();
	bool GetBossStatus();
	bool ChangeStatus();
private:
	int BossHealth;
	bool Life;
	sf::Clock __clock;
	sf::Clock __clock2;
	sf::Clock __clock3;
};

