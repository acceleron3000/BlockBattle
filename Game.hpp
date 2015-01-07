#pragma once
#include <SFML\Graphics.hpp>
#include "KeyMan.hpp"
#include "Player.hpp"

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
};