#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include <vector>
class Bullet: public GameObjects
{
public:
	Bullet(int speed,float _rot,sf::Vector2f _pos,sf::Vector2f c);
	void update(sf::Time deltaTime);
	void loadTexture();
private:
	int Bspeed;
	sf::Vector2f _Dir;
};

