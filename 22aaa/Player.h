#include "GameObjects.h"
#include <SFML/Graphics.hpp>
class Player : public GameObjects
{
public:
	Player();
	~Player(void);
	void update(sf::Time deltatime);
	void PlayerInputs(sf::Keyboard::Key key, bool Pressed);
	void draw(sf::RenderWindow& myWindow);
	void PlayerTakingDamage(int amount);
	void PlayerIncreaseHealth(int heal);
	void Death();
	int gethealth(){ return Health; }
	bool alive;
	void Collision();
private:
	bool Up;
	bool Down;
	bool Left;
	bool Right;
	bool MouseLeft;
	int Health;
	int Lives;

};
