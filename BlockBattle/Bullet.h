#pragma once
#include "GameObject.hpp"
#include "Direction.hpp"
#include <SFML\Graphics.hpp>

class Bullet : public GameObject
{
public:
	Bullet(Direction dir, bool isPlayer1, float pX, float pY);

protected:
	sf::Drawable *getImg();

private:
	bool isP1;
	sf::RectangleShape shape;
};
