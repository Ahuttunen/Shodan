#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"

#include <iostream>
class PlayerBullet : public GameObjects
{
public:
	PlayerBullet(float a,float b);
	~PlayerBullet();
	void update(sf::Time deltatime);
	void loadTextures();
	float GetAngle();
private:
	float dx, dy;
};

