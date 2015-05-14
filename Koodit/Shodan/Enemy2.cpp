#include "Enemy2.h"


Enemy2::Enemy2()
{
	srand((rand() & 740 + 75));
	Sprites.setPosition((rand() % 720 + 100), -Sprites.getGlobalBounds().height - 200.f);
	EnemyHealth = 2;
	srand(time(NULL));
}


Enemy2::~Enemy2()
{
}

void Enemy2::loadTextures()
{
	Textures.loadFromFile("Textures/Enemy2.png");
	Sprites.setTexture(Textures);
	Sprites.setOrigin(Textures.getSize().x*0.5, Textures.getSize().y*0.5);
}
void Enemy2::update(sf::Time deltatime)
{
	sf::Vector2f movement(0, 0);
	movement.y += 375;
	Sprites.move(movement * deltatime.asSeconds());
}
void Enemy2::GettingHit()
{
	EnemyHealth--;
}
int Enemy2::GetEnemyHealth()
{
	return EnemyHealth;
}
bool Enemy2::CheckEnemy()
{
	return EnemyisAlive;
}