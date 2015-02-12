#include "Player.h"


Player::Player() :GameObjects()
{
	/*sf::CircleShape shape(100);
	shape.setFillColor(sf::Color(100, 250, 50));
	shape.setPosition(180 ,200);*/
}
//asasdasd

Player::~Player(void)
{

}
void Player::PlayerInputs(sf::Keyboard::Key key, bool Pressed)
{

	//Liikkumista varten checkaa että jos painaa esim ylös(up), niin se antaa sille arvon
	//Pressed jolloin se liikuttaa pelajaa siihen suuntaan seuraavassa funktiossa
	if (key == sf::Keyboard::Up)
	{
		Up = Pressed;
	}
	if (key == sf::Keyboard::Down)
	{
		Down = Pressed;
	}
	if (key == sf::Keyboard::Left)
	{
		Left = Pressed;
	}
	if (key == sf::Keyboard::Right)
	{
		Right = Pressed;
	}
}
void Player::update(sf::Time deltatime)
{
//Liikkuminen vaatii vielä että checkais että ei mee yli "kuvan" y- ja x-akselilla
	int PlayerSpeed = 150;
	sf::Vector2f move(0, 0);
	//T
	if (Up)
	{
		move.y += PlayerSpeed;
	}
	if (Down)
	{
		move.y -= PlayerSpeed;
	}
	if (Left)
	{
		move.x += PlayerSpeed;
	}
	if (Right)
	{
		move.x -= PlayerSpeed;
	}
	shape.move(move*deltatime.asSeconds());
}


void Player::draw(sf::RenderWindow& myWindow)
{
	//Tällä hetkellä vaan piirtää pallon. Vaatii muokkausta kun ollaan saatu.
	//Pelaajalle grafiikka.
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	myWindow.draw(shape);
}
