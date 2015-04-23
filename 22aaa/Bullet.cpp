#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(sf::Vector2f pos, int speed) : Bspeed(speed)
{
	Sprites.setPosition(pos - sf::Vector2f(0.f, pos.y*0.1f));
	Sprites.setOrigin(Sprites.getGlobalBounds().width / 2, Sprites.getGlobalBounds().height / 2);
}
void Bullet::loadTexture()
{
	Textures.loadFromFile("Textures/BulletPlaceHolder.png");
	Sprites.setTexture(Textures);
}

void Bullet::update(sf::Time deltatime)
{

	sf::Vector2f movement(0.f, 0.f);

	movement.y -= Bspeed;

	Sprites.move(movement * deltatime.asSeconds());
	
	
	
	//angle = 0;
	//sf::Vector2f target(sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);
	//angle = atan2(target.x - Sprites.getPosition().x, target.y - Sprites.getPosition().y);
	//angle = angle*(180 / 3.14159);
	//sf::Vector2f moves(0,0);
	//float velocityX = cos((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	//float velocityY = sin((angle)* 3.14159 / 180) * (Bspeed * deltatime.asSeconds());
	//moves.x += velocityX;
	//moves.y-= velocityY;
	//Sprites.move(moves);
	/*float BulletX = Sprites.getPosition().x;
	float BulletY = Sprites.getPosition().y;

	float angleX = sf::Mouse::getPosition().x- BulletX;
	float angleY = sf::Mouse::getPosition().y - BulletY;
	float length = sqrt(angleX*angleX+angleY*angleY);
	float dx = angleX / length;
	float dy = angleY / length;
	float SpeedX = cos(dx)*Bspeed;
	float SpeedY = sin(dy)*Bspeed;
	
	sf::Vector2f moves(0, 0);
	moves.x += SpeedX;
	moves.y += SpeedY;
	Sprites.move(moves*deltatime.asSeconds());*/
}




