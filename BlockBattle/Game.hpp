#pragma once
#include <SFML\Graphics.hpp>
#include "KeyMan.hpp"
#include "Player.hpp"
#include "Bullet.h"
#include <list>
#include <memory>

class Game
{
public:
	Game(const KeyMan &keyman);
	void draw(sf::RenderWindow &window);
	void onGameLoop();

private:
	const KeyMan &keys;
	Player p1;
	Player p2;

	//gameloop functions
	void updateControls();
	void updateMovement();
	void resolveBulletCollisions();
	void resolvePlayerCollisions();
	void updateWrapAround();
	std::list<std::shared_ptr<Bullet>> bullets;
};