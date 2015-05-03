#include "Spawner.h"


Spawner::Spawner()
{
}
void Spawner::wave(sf::RenderWindow &myWindow)
{	
	//Enemyn spawnaamiseen k‰ytet‰‰n randomi generoitia ajallisesti
	std::vector<Enemy>::iterator it;
	sf::Time _Time = sf::seconds(rand()%1+2);
	if (timer.getElapsedTime()>_Time)
	{ 
	Enemy _Enemy;
	Enemyz.push_back(_Enemy);
	timer.restart();
	}

	it = Enemyz.begin();
	while (it!=Enemyz.end())
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
	//Eri waweille joutuu tekem‰‰n uuvestaan saman

	
}

void Spawner::checkCollision(Player &p)
{
	std::vector<Enemy>::iterator at = Enemyz.begin();
	while (at!=Enemyz.end())
	{
		if (p.CheckShots(*at))
		{
			at->GettingHit();
			if (at->GetEnemyHealth() <=0)
			{
				at->DeathtoEnemy();
				if (at->GetEnemyHealth()==0)
				{ 
				if (!Enemyz.empty())
				{
					at = Enemyz.erase(at);
					at = Enemyz.begin();
				}
				}
			}
		}

	if (p.bounds().intersects(at->bounds()))
	{
		if (at->Check())
		{
			p.Death();
		}
	}
	if (!Enemyz.empty())
	{
		at++;
	}
	}
}

void Spawner::update(sf::Time deltatime)
{
	std::vector<Enemy>::iterator it = Enemyz.begin();

	while (it !=Enemyz.end())
	{
		it->update(deltatime);
		it++;
	}
	//Eri waweille joutuu tekem‰‰n uuvestaan saman
}