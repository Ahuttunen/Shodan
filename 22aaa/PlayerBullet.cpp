#include "PlayerBullet.h"
#include "Game.h"

PlayerBullet::PlayerBullet(sf::Vector2f pos, float c) : _Bspeed(c)
{
	
	Sprites.setPosition(pos.x,pos.y);
	
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

	sf::Vector2f movement(cos(TowerCannonSprite.getRotation()),sin(TowerCannonSprite.getRotation()));
	Sprites.move(movement * deltatime.asSeconds()*_Bspeed);
	
	
}