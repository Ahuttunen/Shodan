#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

#include <iostream>
class PlayerBullet : public GameObjects
{
public:
	PlayerBullet(sf::Vector2f, float c);
	~PlayerBullet();
	void update(sf::Time deltatime);
	void loadTextures();
private:
	float _Bspeed;
};

