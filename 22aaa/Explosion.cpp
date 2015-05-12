#include "Explosion.h"


Explosion::Explosion(sf::Vector2f a)
{
	Sprites.setPosition(a.x, a.y);
}

void Explosion::loadTexture()
{
	Textures.loadFromFile("Textures/Explosion.png");
	Sprites.setTexture(Textures);
}
void Explosion::update(sf::Time deltaTime)
{
}