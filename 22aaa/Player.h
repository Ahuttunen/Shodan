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
private:
	bool Up;
	bool Down;
	bool Left;
	bool Right;
};
