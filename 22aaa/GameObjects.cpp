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
