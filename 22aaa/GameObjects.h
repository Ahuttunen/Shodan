#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GameObjects
{
public:
	GameObjects();
	virtual ~GameObjects(void);
	virtual void draw(sf::RenderWindow& myWindow);
	virtual void update(sf::Time deltatime);
	sf::Vector2f TowerCannonPosition(){ return TowerCannonSprite.getPosition(); }
	sf::FloatRect bounds();
	sf::Vector2f getPos(){ return Sprites.getPosition(); }
protected:
	sf::Texture Textures;
	sf::Sprite Sprites;
	sf::Texture TowerTexture;
	sf::Sprite TowerCannonSprite;
	sf::FloatRect boundingbox;
};
