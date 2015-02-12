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
	//Vaatii muokkausta sitten ku on pelaajalla grafiikka
	myWindow.draw(shape);
}
sf::Vector2f GameObjects::getPosition()
{
	//Positionin saanti
	return shape.getPosition();
}
