#include "Backround.h"


Backround::Backround()
{
	BTexture.loadFromFile("Textures/backgroundPlaceHolder.jpg");
	BSprite.setTexture(BTexture);
	BSprite.setPosition(0, -BSprite.getGlobalBounds().height);
	BSprite2 = BSprite;
	BSprite3 = BSprite;
}


Backround::~Backround(void)
{
}
void Backround::draw(sf::RenderWindow& myWindow)
{

	myWindow.draw(BSprite);
	if (BSprite.getPosition().y > 0)
	{
		myWindow.draw(BSprite2);

		if (BSprite2.getPosition().y > myWindow.getSize().y)
		{
			BSprite2.setPosition(0, BSprite.getGlobalBounds().top - BSprite3.getGlobalBounds().height);
		}
	}
	if (BSprite2.getPosition().y > 0)
	{
		myWindow.draw(BSprite3);

		if (BSprite3.getPosition().y > myWindow.getSize().y)
		{
			BSprite3.setPosition(0, BSprite.getGlobalBounds().top - BSprite.getGlobalBounds().height);
		}
	}
	if (BSprite3.getPosition().y > 0)
	{
		BSprite.setPosition(0, BSprite3.getGlobalBounds().top - BSprite.getGlobalBounds().height);
	}
	
}
void Backround::Scroll()
{
	sf::Time time = sf::seconds(1.f / 60.f);
	int speed = 400;
	sf::Vector2f scrollDown(0, 0);
	scrollDown.y += speed;
	BSprite.move(scrollDown * time.asSeconds());
	BSprite2.move(scrollDown * time.asSeconds());
	BSprite3.move(scrollDown * time.asSeconds());
}