#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include "Backround.h"
#include "Spawner.h"
#include "Explosion.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Boss.h"
#include "SFML/Audio.hpp"
=======
#include "SFML\Audio.hpp"
>>>>>>> origin/master
=======
>>>>>>> 060978ccc3c01caf335b79130b1b821768eae778
class Game
{
public:
Game(void);
void run();
~Game(void);
private:

	void processEvents();
	void update(sf::Time deltatime);
	void render();
	void CollisionChecker();
private:
	sf::RenderWindow myWindow;
	Spawner spawner;
	Player player;
	Boss boss;
	Backround background;
	sf::Clock clock;
	sf::Clock clock2;
<<<<<<< HEAD
<<<<<<< HEAD
	sf::Music music;
=======
	/*sf::Music music;*/
>>>>>>> origin/master
=======
>>>>>>> 060978ccc3c01caf335b79130b1b821768eae778
};
