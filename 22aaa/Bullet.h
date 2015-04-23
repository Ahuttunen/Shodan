#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include<vector>
class Bullet: public GameObjects
{
public:
	Bullet(sf::Vector2f, int speed);
	void update(sf::Time deltaTime);
	void loadTexture();
	float GetRotation(sf::RenderWindow& myWindow);
	void Mouse(sf::RenderWindow& myWindow);
	void Shoot(sf::Time deltaTime, sf::RenderWindow &myWindow);
private:
	int Bspeed;
	float angle;

};

