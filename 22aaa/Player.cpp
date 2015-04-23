#include "Player.h"


Player::Player() :GameObjects()
{
	//Pelaajan grafiikka ,asettaa sille kuvan ja positionin
	Textures.loadFromFile("Textures/tankki.png");
	Sprites.setTexture(Textures);
	Sprites.setPosition(300.f,150.f);
	//Player_Sprite.setOrigin(sf::Vector2f(25, 25));
	Health = 100;
	Lives = 3;
	alive = true;
	std::cout << "Pelaaja syntyi" << std::endl;
}


Player::~Player(void)
{

}
void Player::PlayerInputs(sf::Keyboard::Key key, bool Pressed)
{
	//Liikkumista varten checkaa ett‰ jos painaa esim ylˆs(up), niin se antaa sille arvon
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
	if (sf::Event::MouseButtonPressed==sf::Mouse::Left)
	{
		MouseLeft = Pressed;
		std::cout << "aaaa" << std::endl;
	}
}

void Player::update(sf::Time deltatime)
{
	//Liikkuminen vaatii viel‰ ett‰ checkais ett‰ ei mee yli "kuvan" y- ja x-akselilla
	
	int PlayerSpeed = 200;
	sf::Vector2f moves(0, 0);
	if (Up)
	{ 
		if (Sprites.getPosition().y<680)
		{
			moves.y += PlayerSpeed;
		}
		else
		{
			moves.y += 0;
		}
	}
	if (Down)
	{
		if (Sprites.getPosition().y > 10)
		{
			moves.y -= PlayerSpeed;
		}
		else
		{
			moves.y -= 0;
		}
	}
	if (Left)
	{
		if (Sprites.getPosition().x < 1200)
		{
			moves.x += PlayerSpeed;
		}
		else
		{
			moves.x += 0;
		}
	}
	if (Right)
	{
		if (Sprites.getPosition().x > 15)
		{
		moves.x -= PlayerSpeed;
		}
		else
		{
			moves.x += 0;
		}
	}

	Sprites.move(moves * deltatime.asSeconds());
}

void Player::draw(sf::RenderWindow& myWindow)
{
	//T‰ll‰ hetkell‰ vaan piirt‰‰ pallon. Vaatii muokkausta kun ollaan saatu.
	//Pelaajalle grafiikka.
	if (alive=true)
	{ 
	myWindow.draw(Sprites);
	}
}
void Player::PlayerTakingDamage(int amount)
{
	int currentHealth = Health - amount;
	currentHealth = Health;
}
void Player::PlayerIncreaseHealth(int heal)
{
	int newHealth = Health + heal;
	Health = newHealth;
	if (Health < 100)
	{
		Health = 100;
	}
}
void Player::Death()
{
	Lives--;
	if (Lives <=0)
	{
		//t‰h‰n jotakin hauskaa
		std::cout << "Kuolit saatana" << std::endl;
	}
}
void Player::Collision()
{
	
}