#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

#include <iostream>
class PlayerBullet : public GameObjects
{
public:
	PlayerBullet(sf::Vector2f pos,float rotation);
	~PlayerBullet();
	void update(sf::Time deltatime);
	void loadTextures();
//	//float angle = 0;
//sf::Vector2f target(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
//angle = atan2(target.x - Sprites.getPosition().x, target.y - Sprites.getPosition().y);
//angle = angle*(180 / 3.14159);
//sf::Vector2f moves(0, 0);
//float velocityX = cos((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
//float velocityY = sin((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
//moves.x += velocityX;
//moves.y -= velocityY;
//Sprites.move(moves);
};

