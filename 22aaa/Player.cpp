#include "Player.h"


Player::Player() :GameObjects()
{
	Textures.loadFromFile("Textures/Tankinalusta.png");
	Sprites.setTexture(Textures);
	Sprites.setPosition(300.f,150.f);

	TowerTexture.loadFromFile("Textures/Tankin_torni.png");
	TowerCannonSprite.setTexture(TowerTexture);
	TowerCannonSprite.setPosition(371.f,246.f);

	TowerCannonSprite.setOrigin(sf::Vector2f(TowerCannonSprite.getTexture()->getSize().x * 0.5f, TowerCannonSprite.getTexture()->getSize().y * 0.5f));
	std::cout << TowerCannonSprite.getTexture()->getSize().x << " " << TowerCannonSprite.getTexture()->getSize().y << std::endl;
	std::cout << TowerCannonSprite.getOrigin().x << " " <<  TowerCannonSprite.getOrigin().y<< std::endl;
	std::cout << Sprites.getTexture()->getSize().x << " " << Sprites.getTexture()->getSize().y << std::endl;

	Lives = 3;
	Fired = false;
	std::cout << "Pelaaja syntyi" << std::endl;
	
}

Player::~Player(void)
{}
void Player::update(sf::Time deltatime)
{
	
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
			moves.y = 0;
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
			moves.y = 0;
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
			moves.x = 0;
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
			moves.x = 0;
		}
	}
	
	

	Sprites.move(moves * deltatime.asSeconds());
	TowerCannonSprite.move(moves*deltatime.asSeconds());

	std::vector<Bullet>::iterator it = shots.begin();
	while (it!=shots.end())
	{
		it->update(deltatime);
		it++;
	}

}
void Player::PlayerInputs(sf::Keyboard::Key key, bool Pressed)
{


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
void Player::PlayerMouseInputs(sf::Mouse::Button button, bool Press)
{
	if (button == sf::Mouse::Left)
	{
		Fired = true;
		std::cout << "Painoit vasenta hiirennappainta" << std::endl;
		fire();
	}
}
void Player::fire()
{
	if (Fired==true)
	{
	Bullet newshot (getPos(),200);
	shots.push_back(newshot); 
	Fired = false;
	}

}
void Player::draw(sf::RenderWindow& myWindow)
{
	std::vector<Bullet>::iterator it = shots.begin();
	while (it != shots.end())
	{
		it->loadTexture();
		it->draw(myWindow);
		it++;
	}
myWindow.draw(Sprites);
myWindow.draw(TowerCannonSprite);
}
void Player::CannonRotation(sf::RenderWindow& myWindow)
{
	sf::Vector2f curPos = TowerCannonSprite.getPosition();
	sf::Vector2f position = myWindow.mapPixelToCoords(sf::Mouse::getPosition(myWindow));
	//std::cout << position.x << " "<<position.y<< std::endl;
	const float PI = 3.14159265;
	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;
	float rotation = (atan2(dy, dx)) * 180 / PI;
	TowerCannonSprite.setRotation(rotation + 90);
}
sf::Vector2f Player::BulletPosition()
{
	std::vector<Bullet>::iterator it = shots.begin();
	while (it != shots.end())
	{
		return it->getPos();
		it++;
	}

}
bool Player::CheckShots(GameObjects& a)
{
	std::vector<Bullet>::iterator it = shots.begin();
	while (it!=shots.end())
	{
		if (it->getPos().y < 0)
		{
			std::cout << "Sasdad";
			it = shots.erase(it);
		}
		else if (it->bounds().intersects(a.bounds()))
		{
			it = shots.erase(it);
			return true;
		}
		else
		{
			it++;
		}
	}
	return false;
}

void Player::Death()
{
	Lives--;
	if (Lives <=0)
	{
		//tähän jotakin hauskaa
		std::cout << "Kuolit saatana" << std::endl;
	}
}

