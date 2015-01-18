#pragma once
#include "GameObject.hpp"
#include "Direction.hpp"
#include <SFML\Graphics.hpp>

class Bullet : public GameObject
{
public:
	Bullet(Direction dir, bool isPlayer1, float pX, float pY);
	//~Bullet();
	bool const isDestroyed(){ return isDead; }
	void die(){ isDead = true; }

protected:
	sf::Drawable *getImg();

private:
	bool isDead;
	bool isP1;
	sf::RectangleShape shape;
};
