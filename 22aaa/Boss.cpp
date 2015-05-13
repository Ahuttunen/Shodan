#include "Boss.h"


Boss::Boss()
{
	Sprites.setPosition(300, -Sprites.getGlobalBounds().height - 100);
	Health = 20;

}


Boss::~Boss(void)
{
}

void Boss::update(sf::Time deltaTime)

{
	if (!Life)
	{
		if (Sprites.getPosition().y < 100)
		{
			sf::Vector2f movement(0, 100);
			Sprites.move((movement * deltaTime.asSeconds()));
		}

		if (__clock.getElapsedTime() < sf::seconds(2))
		{
			sf::Vector2f movement(150, 0);
			Sprites.move((movement * deltaTime.asSeconds()));
		}
		if (__clock.getElapsedTime() > sf::seconds(2))
		{
			sf::Vector2f movement(-150, 0);
			Sprites.move((movement * deltaTime.asSeconds()));
			if (__clock.getElapsedTime() > sf::seconds(4))
			{
				__clock.restart();
			}
		}
	}
	
}
void Boss::loadtextures()
{
	Textures.loadFromFile("Textures/Boss.png");
	Sprites.setTexture(Textures);
	Sprites.setOrigin(Textures.getSize().x*0.5, Textures.getSize().y*0.5);
}