#include "GameObjects.h"


GameObjects::GameObjects()
{
	Sprites.setOrigin(Sprites.getGlobalBounds().width*0.5, Sprites.getGlobalBounds().height*0.5);
}
GameObjects::~GameObjects()
{
}
void GameObjects::update(sf::Time deltatime)
{
}
void GameObjects::draw(sf::RenderWindow& myWindow)
{
	myWindow.draw(Sprites);
}
sf::FloatRect GameObjects::bounds()
{
	return boundingbox = Sprites.getGlobalBounds();;
}



