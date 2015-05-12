#include "Player.h"


Player::Player() :GameObjects()
{
	Textures.loadFromFile("Textures/Tankinalusta.png");
	Sprites.setTexture(Textures);
	Sprites.setPosition(300.f,150.f);
	Sprites.setScale(0.5,0.5);
	TowerTexture.loadFromFile("Textures/Tankin_torni.png");
	TowerCannonSprite.setTexture(TowerTexture);
	TowerCannonSprite.setPosition(335.5f,200.f);
	TowerCannonSprite.setScale(0.5, 0.5);
	TowerCannonSprite.setOrigin(sf::Vector2f(TowerCannonSprite.getTexture()->getSize().x * 0.5f, TowerCannonSprite.getTexture()->getSize().y * 0.5f));
	std::cout << TowerCannonSprite.getTexture()->getSize().x << " " << TowerCannonSprite.getTexture()->getSize().y << std::endl;
	std::cout << TowerCannonSprite.getOrigin().x << " " <<  TowerCannonSprite.getOrigin().y<< std::endl;
	std::cout << Sprites.getTexture()->getSize().x << " " << Sprites.getTexture()->getSize().y << std::endl;
	Lives = 3;
	Fired = false;
	std::cout << "Pelaaja syntyi" << std::endl;

}

Player::~Player(void)
{
}
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
	if (key == sf::Keyboard::W)
	{
		Up = Pressed;
	}
	if (key == sf::Keyboard::S)
	{
		Down = Pressed;
	}
	if (key == sf::Keyboard::A)
	{
		Left = Pressed;
	}
	if (key == sf::Keyboard::D)
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
	}
	else
	{
		Fired = false;
	}
}
void Player::fire(sf::RenderWindow& myWindow)
{
	if (Fired == true)
	{
		Bullet shot(300, GeRot(),GetBulletForCannon(),GetDirection(myWindow));
		shots.push_back(shot);
		Fired = false;
	}
	
}

sf::Vector2f Player::GetBulletForCannon()
{
	const float PI = 3.14159265;
	float rotation = GeRot();
	sf::Vector2f aa(-5.f,-75.f);
	sf::Vector2f aaa;
	aaa.x = aa.x*cos(rotation*PI / 180) - aa.y*sin(rotation*PI / 180);
	aaa.y = aa.x*sin(rotation*PI / 180) + aa.y*cos(rotation*PI / 180);
	sf::Vector2f RotationReturn = TowerCannonSprite.getPosition() + aaa;
	return RotationReturn;
}
sf::Vector2f Player::GetDirection(sf::RenderWindow& myWindow)
{
	sf::Vector2f Direc(0.0f, 0.0f);
	float BulletX = Sprites.getPosition().x;
	float BulletY = Sprites.getPosition().y;
	sf::Vector2f pos = myWindow.mapPixelToCoords(sf::Mouse::getPosition(myWindow));
	float AngleX = pos.x - BulletX;
	float AngleY = pos.y - BulletY;
	float Length = sqrt(AngleX*AngleX+AngleY+AngleY);
	sf::Vector2f Direc2(AngleX/Length,AngleY/Length);
	Direc = Direc2;
	return Direc;
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
float Player::CannonRotation(sf::RenderWindow& myWindow)
{
	sf::Vector2f curPos = TowerCannonSprite.getPosition();
	sf::Vector2f position = myWindow.mapPixelToCoords(sf::Mouse::getPosition(myWindow));
	//std::cout << position.x << " "<<position.y<< std::endl;
	const float PI = 3.14159265;
	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;
	rotation = (atan2(dy, dx)) * 180 / PI;
	TowerCannonSprite.setRotation(rotation + 90);
	return TowerCannonSprite.getRotation();
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
	while (it !=shots.end())
	{
		//Jos ammus ei osu Spriteen vaan menee yli laijan niin se poistetaan
		if (it->getPos().y < 0 || it->getPos().y>640 || it->getPos().x<0 || it->getPos().x>640)
		{
			std::cout << "Ammus" << std::endl;
			it = shots.erase(it);
		}
		else if (it ->bounds().intersects(a.bounds()))
		{
			//Jos ammus osuu spriteen niin silloin se myös poistetaan mutta myös lähetetään true value
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
	Sprites.setPosition(300.f,350.f);
	Lives--;
	if (Lives ==0)
	{
		//tähän jotakin hauskaa
		std::cout << "Kuolit saatana" << std::endl;
	}
}

