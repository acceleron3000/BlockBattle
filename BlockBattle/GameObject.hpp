#pragma once
#include "Constants.hpp"
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class GameObject
{
public:
	GameObject(){}
	~GameObject(){}
	void updateMovement();
	void draw(sf::RenderWindow &window);
	bool isCollidingWith(GameObject &other);
	void bump(GameObject &other);
	void wrap();

protected:
	float x;
	float y;
	int width;
	int height;
	float speedX = 0;
	float speedY = 0;
	virtual sf::Drawable *getImg() = 0;
#if SHOW_HIT_BOXES
	virtual sf::Drawable &getHitbox() = 0;
#endif
};
