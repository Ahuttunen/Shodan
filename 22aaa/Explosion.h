#pragma once
#include <SFML/Graphics.hpp>
#include "GameObjects.h"
#include <vector>
class Explosion:public GameObjects
{
public:
	Explosion(sf::Vector2f a);
	void update(sf::Time deltaTime);
	void loadTexture();
	
private:

};

