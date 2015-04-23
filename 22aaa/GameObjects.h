#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class GameObjects
{
public:
	GameObjects();
	virtual ~GameObjects(void);
	virtual void draw(sf::RenderWindow& myWindow);
	//virtual void draw2(sf::RenderWindow& myWindow);dfdf
	virtual void update(sf::Time deltaTime);
	sf::Vector2f PlayerGetPosition(){ return Sprites.getPosition(); }
	//sf::Vector2f EnemyGetPosition(){return Enemy_Sprite.getPosition();}
protected:
	sf::Texture Textures;
	/*sf::Texture EnemyTexture;*/
	sf::Sprite Sprites;
	/*sf::Sprite Enemy_Sprite;*/
};

