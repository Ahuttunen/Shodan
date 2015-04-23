//#include "Bullet.h"
//#include "Game.h"
//
//Bullet::Bullet(sf::Vector2f position, int speed) :BulletSpeed(speed)
//{
////	Sprites.setPosition(position-sf::Vector2f(0,position.y*0.05));
//
//}
//
//
//Bullet::~Bullet()
//{
//}
//void Bullet::LoadBulletTexture()
//{
//	Textures.loadFromFile("Textures/BulletPlaceHolder.png");
//	Sprites.setTexture(Textures);
//}
//void Bullet::update(sf::Time deltatime)
//{
//	sf::Vector2f moveTo(0.f,0.f);
//	moveTo.y -= BulletSpeed;
//	moveTo.x -= BulletSpeed;
//	Sprites.move(moveTo*deltatime.asSeconds());
//}