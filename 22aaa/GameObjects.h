#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GameObjects
{
public:
	GameObjects();
	virtual ~GameObjects(void);
	virtual void draw(sf::RenderWindow& myWindow);
	virtual void update(sf::Time deltaTime);
	sf::Vector2f getPosition();
protected:
	sf::CircleShape shape;
};

