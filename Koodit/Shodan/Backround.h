#pragma once
#include <SFML/Graphics.hpp>
class Backround
{
public:
	Backround();
	~Backround(void);
	void draw(sf::RenderWindow& myWindow);
	void Scroll();
private:
	sf::Sprite BSprite;
	sf::Sprite BSprite2;
	sf::Sprite BSprite3;
	sf::Texture BTexture;
};

