#include "Boss.h"


Boss::Boss()
{
	Sprites.setPosition(400, - 50);
	Sprites.setOrigin(Textures.getSize().x*0.5, Textures.getSize().y*0.5);
	BossHealth = 20;
	Life = true;
}
Boss::~Boss(void)
{}
void Boss::update(sf::Time deltaTime)
{
	
if (Life==true)
{
	if (__clock2.getElapsedTime() < sf::seconds(28))
	{
		if (Sprites.getPosition().y < 100)
		{
			sf::Vector2f movement(0, 200);
			Sprites.move((movement * deltaTime.asSeconds()));
		}
		if (__clock.getElapsedTime() < sf::seconds(2))
		{
			sf::Vector2f movement(-150, 0);
			Sprites.move((movement * deltaTime.asSeconds()));
		}
		if (__clock.getElapsedTime() > sf::seconds(2))
		{
			sf::Vector2f movement(200, 0);
			Sprites.move((movement * deltaTime.asSeconds()));
		}

		if (__clock.getElapsedTime() > sf::seconds(4))
		{
			__clock.restart();
		}
	}
		if (__clock2.getElapsedTime() > sf::seconds(28))
		{
			if (__clock.getElapsedTime() < sf::seconds(2))
			{
				sf::Vector2f movement(150, 0);
				Sprites.move((movement * deltaTime.asSeconds()));
			}
			if (__clock.getElapsedTime() > sf::seconds(2))
			{
				sf::Vector2f movement(-200, 0);
				Sprites.move((movement * deltaTime.asSeconds()));
			}

			if (__clock.getElapsedTime() > sf::seconds(4))
			{
				__clock.restart();
			}
			if (__clock2.getElapsedTime() > sf::seconds(44))
			{
				__clock2.restart();
			}
		}
	}

}
void Boss::Dead()
{ 
	Life = false;
}
int Boss::GetBossHealth()
{
	return BossHealth; 
}
void Boss::BossGettingHit()
{
	BossHealth--;
}
bool Boss::GetBossStatus()
{ 
	return Life; 
}
bool Boss::ChangeStatus()
{
	
	return Life == true;

}