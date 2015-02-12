#include "Player.h"


Player::Player() :GameObjects()
{
	/*sf::CircleShape shape(100);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(180 ,200);*/
}


Player::~Player(void)
{

}
void Player::update(sf::Time deltatime)
{
	int PlayerSpeed = 150;
	if (Up)
	{

	}
	if (Down)
	{

	}
	if (Left)
	{

	}
	if (Right)
	{

	}
}
void Player::PlayerInputs(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
	{

	}
	if (key == sf::Keyboard::Down)
	{
		
	}
	if (key == sf::Keyboard::Left)
	{
		
	}
	if (key == sf::Keyboard::Right)
	{
		
	}
}

void Player::draw(sf::RenderWindow& myWindow)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	myWindow.draw(shape);
}
