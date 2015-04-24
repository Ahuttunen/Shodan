#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include <vector>
class Bullet: public GameObjects
{
public:
	Bullet(sf::Vector2f, int speed);
	void update(sf::Time deltaTime);
	void loadTexture();
private:
	int Bspeed;
};

