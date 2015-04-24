#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(sf::Vector2f pos,float rotation)
{
	Sprites.setPosition(pos - sf::Vector2f(0.f, pos.y*0.1f));
	Sprites.setRotation(rotation);
	float angle = atan2(sf::Mouse::getPosition().y-TowerCannonPosition().y,sf::Mouse::getPosition().x-TowerCannonPosition().x);
	angle = angle *(180 / 3.14159);
}


PlayerBullet::~PlayerBullet()
{
}
void PlayerBullet::loadTextures()
{
	Textures.loadFromFile("Textures/BulletPlaceHolder.png");
	Sprites.setTexture(Textures);
}
float PlayerBullet::GetAngle()
{
	float angle = atan2(sf::Mouse::getPosition().y - TowerCannonPosition().y, sf::Mouse::getPosition().x - TowerCannonPosition().x);
	angle = angle *(180 / 3.14159);
	return angle;
}
void PlayerBullet::update(sf::Time deltatime)
{
	sf::Vector2f movement(0,0);
	float Bspeed = 5000;
	float VelocityX = cos((GetAngle())*3.14159/180)*(Bspeed*deltatime.asSeconds());
	float VelocityY = sin((GetAngle())*3.14159 / 180)*(Bspeed*deltatime.asSeconds());
	movement.x += VelocityX;
	movement.y += VelocityY;
	Sprites.move(movement*deltatime.asSeconds());
	/*float angle = 0;
	float Bspeed = 500;

	sf::Vector2f target(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	angle = atan2(target.x - Sprites.getPosition().x, target.y - Sprites.getPosition().y);
	angle = angle*(180 / 3.14159);
	sf::Vector2f moves(0, 0);
	float velocityX = cos((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	float velocityY = sin((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	moves.x += velocityX;
	moves.y -= velocityY;
	Sprites.move(moves*deltatime.asSeconds());*/
}