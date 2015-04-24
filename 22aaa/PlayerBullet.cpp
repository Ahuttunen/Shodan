#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(sf::Vector2f pos,float rotation)
{
	Sprites.setPosition(pos - sf::Vector2f(0.f, pos.y*0.1f));

}


PlayerBullet::~PlayerBullet()
{
}
void PlayerBullet::loadTextures()
{
	Textures.loadFromFile("Textures/BulletPlaceHolder.png");
	Sprites.setTexture(Textures);
}
void PlayerBullet::update(sf::Time deltatime)
{
	float angle = 0;
	float Bspeed = 5000;
	sf::Vector2f target(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	angle = atan2(target.x - Sprites.getPosition().x, target.y - Sprites.getPosition().y);
	angle = angle*(180 / 3.14159);
	sf::Vector2f moves(0, 0);
	float velocityX = cos((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	float velocityY = sin((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	moves.x += velocityX;
	moves.y -= velocityY;
	Sprites.move(moves*deltatime.asSeconds());

}