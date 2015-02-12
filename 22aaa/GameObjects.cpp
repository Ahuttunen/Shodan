#include "GameObjects.h"


GameObjects::GameObjects()
{
}


GameObjects::~GameObjects()
{
}
void GameObjects::update(sf::Time deltaTime)
{

}
void GameObjects::draw(sf::RenderWindow& myWindow)
{
	myWindow.draw(shape);
}
