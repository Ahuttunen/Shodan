#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(int speed, float _rot, sf::Vector2f _pos,sf::Vector2f c) : Bspeed(speed), _Dir(c)
{
	Sprites.setOrigin(Sprites.getGlobalBounds().width / 2, Sprites.getGlobalBounds().height / 2);
	Sprites.setRotation(_rot);
	Sprites.setPosition(_pos.x,_pos.y);
}
void Bullet::loadTexture()
{
	Textures.loadFromFile("Textures/Bullet.png");
	Sprites.setTexture(Textures);
}

void Bullet::update(sf::Time deltatime)
{
	sf::Vector2f movement2(0,0);
	sf::Vector2f movement;
	movement.x = _Dir.x*Bspeed;
	movement.y = _Dir.y*Bspeed;
	movement2 = movement;
	Sprites.move(movement2*deltatime.asSeconds());
}




