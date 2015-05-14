#pragma once
#include "GameObjects.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include "GameObjects.h"
#include <utility>
class Player : public GameObjects
{
public:
	Player();
	~Player(void);
	void update(sf::Time deltatime);
	void PlayerInputs(sf::Keyboard::Key key, bool Pressed);
	void PlayerMouseInputs(sf::Mouse::Button button, bool Press);
	void draw(sf::RenderWindow& myWindow);
	float CannonRotation(sf::RenderWindow& myWindow);
	void fire(sf::RenderWindow& myWindow);
	sf::Vector2f GetMouseDirection(sf::RenderWindow& myWindow);
	sf::Vector2f BulletPosition();
	sf::Vector2f BulletPositionForPlayer();
	sf::Vector2f GetBulletForCannon();
	float GeRot(){ return TowerCannonSprite.getRotation();}
	sf::Vector2f GetDirection(sf::RenderWindow& myWindow);
	void Damage();
	bool CheckShots(GameObjects&a);
	bool CheckPlayerStatus();
private:
	bool Fired;
	std::vector<Bullet>shots;
	bool MouseLeft;
	float rotation;
	bool Up;
	bool Down;
	bool Left;
	bool Right;
	int Lives;
	int Health;
	bool Death;
	sf::Clock clock;
};
