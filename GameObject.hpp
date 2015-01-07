#pragma once
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
	void wrap();

protected:
	float x;
	float y;
	int width;
	int height;
	float speedX = 0;
	float speedY = 0;
	virtual sf::Drawable &getImg() = 0;
};
