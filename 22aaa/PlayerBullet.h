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
	float GetAngle();
};

