#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(sf::Vector2f pos, int speed) : Bspeed(speed)
{
	Sprites.setPosition(pos - sf::Vector2f(0.f, pos.y*0.1f));
	Sprites.setOrigin(Sprites.getGlobalBounds().width / 2, Sprites.getGlobalBounds().height / 2);
}
void Bullet::loadTexture()
{
	Textures.loadFromFile("Textures/BulletPlaceHolder.png");
	Sprites.setTexture(Textures);
}

void Bullet::update(sf::Time deltatime)
{

	sf::Vector2f movement(0.f, 0.f);

	movement.y -= Bspeed;

	Sprites.move(movement * deltatime.asSeconds());
	
	
	
	


}




