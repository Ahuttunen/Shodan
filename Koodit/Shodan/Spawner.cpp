#include "Spawner.h"
#include "Game.h"

Spawner::Spawner()
{
	_Boss = false;

}

void Spawner::wave(sf::RenderWindow &myWindow)
{

	std::vector<Enemy>::iterator it;
	if (!_Boss)
	{
		sf::Time _Time = sf::seconds(1);
		if (timer.getElapsedTime()>_Time)
		{
			Enemy _Enemy;
			Enemyz.push_back(_Enemy);
			timer.restart();
		}
	}
	it = Enemyz.begin();
	while (it != Enemyz.end())
	{
		it->draw(myWindow);
		if (it->bounds().top > myWindow.getSize().y)
		{
			std::cout << "Vihollinen poistettiin" << std::endl;
			it = Enemyz.erase(it);
			it = Enemyz.begin();
		}

		if (!Enemyz.empty())
		{
			it++;
		}


	}
	//Get the local bounding rectangle of the entity.
	//The returned rectangle is in local coordinates, which means that it ignores the transformations(translation, rotation, scale, ...) that are applied to the entity.
	//In other words, this function returns the bounds of the entity in the entity's coordinate system.
	//Eri waweille joutuu tekemään uuvestaan saman


}
void Spawner::wave2(sf::RenderWindow &myWindow)
{
	std::vector<Enemy2>::iterator it;
	if (!_Boss)
	{
		sf::Time _Time = sf::seconds(1);
		if (timer.getElapsedTime()>_Time)
		{
			Enemy2 _Enemy;
			Enemyz2.push_back(_Enemy);
			timer.restart();
		}

	}
	it = Enemyz2.begin();
	while (it != Enemyz2.end())
	{
		it->draw(myWindow);
		if (it->bounds().top > myWindow.getSize().y)
		{
			std::cout << "Vihollinen poistettiin" << std::endl;
			it = Enemyz2.erase(it);
			it = Enemyz2.begin();
		}

		if (!Enemyz2.empty())
		{
			it++;
		}


	}
}
void Spawner::checkCollision(Player &p)
{
	std::vector<Enemy>::iterator at = Enemyz.begin();
	while (at != Enemyz.end())
	{
		if (p.CheckShots(*at))
		{
			at->GettingHit();
			if (at->GetEnemyHealth() <= 0)
			{

				if (!Enemyz.empty())
				{
					sf::Vector2f aa = at->getPos();
					Explosion ab(aa);
					Explositions.push_back(ab);
					at = Enemyz.erase(at);
					at = Enemyz.begin();

				}
			}
		}

		if (p.bounds().intersects(at->bounds()))
		{
			at = Enemyz.erase(at);
			at = Enemyz.begin();
			p.Damage();
		}
		if (!Enemyz.empty())
		{
			at++;
		}
	}

	std::vector<Enemy2>::iterator st = Enemyz2.begin();

	while (st != Enemyz2.end())
	{
		if (p.CheckShots(*st))
		{
			st->GettingHit();
			if (st->GetEnemyHealth() <= 0)
			{
				if (!Enemyz2.empty())
				{
					sf::Vector2f aa = st->getPos();
					Explosion ac(aa);
					Explositions.push_back(ac);
					st = Enemyz2.erase(st);
					st = Enemyz2.begin();
				}
			}
		}
		if (p.bounds().intersects(st->bounds()))
		{
			st = Enemyz2.erase(st);
			st = Enemyz2.begin();
			p.Damage();
		}
		if (!Enemyz2.empty())
		{
			st++;
		}
	}

	if (p.bounds().intersects(boss.bounds()))
	{
		p.Damage();
	}
	if (p.CheckShots(boss))
	{
		boss.BossGettingHit();
		if (boss.GetBossHealth() <= 0)
		{
			boss.Dead();
		}

	}

}
void Spawner::draw(sf::RenderWindow& myWindow)
{
	std::vector<Explosion>::iterator az = Explositions.begin();
	while (az != Explositions.end())
	{
		az->loadTexture();
		az->draw(myWindow);
		az++;
	}
}
void Spawner::update(sf::Time deltatime)
{
	std::vector<Enemy>::iterator it = Enemyz.begin();

	while (it != Enemyz.end())
	{
		it->update(deltatime);
		it++;
	}
	std::vector<Enemy2>::iterator it2 = Enemyz2.begin();
	while (it2 != Enemyz2.end())
	{
		it2->update(deltatime);
		it2++;
	}
	std::vector<Explosion>::iterator az = Explositions.begin();
	sf::Time ExplosionTimer = sf::seconds(2);
	while (az != Explositions.end())
	{
		az->update(deltatime);
		if (timer2.getElapsedTime() > ExplosionTimer)
		{
			az = Explositions.erase(az);
			az = Explositions.begin();

		}
	}

	if (_Boss == true)
	{
		boss.update(deltatime);
	}

}
void Spawner::SpawnForBoss(sf::RenderWindow &myWindow)
{
	if (boss.GetBossStatus() == true)
	{
		boss.draw(myWindow);
		_Boss = true;
	}
	else
	{
		_Boss = false;
	}
}
