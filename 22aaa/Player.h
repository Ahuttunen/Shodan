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
	void CannonRotation(sf::RenderWindow& myWindow);
	void fire();
	sf::Vector2f BulletPosition();
	void Death();
	bool CheckShots(GameObjects&a);
private:
	std::vector<Bullet>shots;
	std::vector<PlayerBullet>_shots;
	bool MouseLeft;
	float rotation;
	bool Up;
	bool Down;
	bool Left;
	bool Right;
	int Lives;
	bool Fired;
	sf::Clock clock;
};
