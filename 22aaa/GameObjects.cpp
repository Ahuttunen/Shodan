#include "GameObjects.h"


GameObjects::GameObjects()
{
	//Player_Sprite.setOrigin(3,3);
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
	myWindow.draw(Sprites);

}
//sf::Vector2f GameObjects::PlayerGetPosition()
//{
//	//Positionin saanti
//	return Player_Sprite.getPosition();
//}
//void GameObjects::draw2(sf::RenderWindow&myWindow)
//{
//	myWindow.draw(Enemy_Sprite);
//}
//sf::Vector2f GameObjects::EnemyGetPosition()
//{
//	return Enemy_Sprite.getPosition();
//}

//ÅPelaajan sprite muokkaus