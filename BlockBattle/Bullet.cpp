#include "Constants.hpp"
#include "Bullet.h"

Bullet::Bullet(Direction dir, bool isPlayer1, float pX, float pY) :
isP1(isPlayer1)
{
	switch (dir)
	{
	case UP:
		speedY = -BULLET_SPEED;
		x = pX + (PLAYER_WIDTH - BULLET_WIDTH) / 2;
		y = pY - BULLET_HEIGHT - BULLET_SPAWN_DISTANCE;
		break;
	case RIGHT:
		speedX = BULLET_SPEED;
		x = pX + PLAYER_WIDTH + BULLET_SPAWN_DISTANCE;
		y = pY + (PLAYER_HEIGHT - BULLET_HEIGHT) / 2;
		break;
	case LEFT:
		speedX = -BULLET_SPEED;
		x = pX - BULLET_WIDTH - BULLET_SPAWN_DISTANCE;
		y = pY + (PLAYER_HEIGHT - BULLET_HEIGHT) / 2;
		break;
	case DOWN:
		speedY = BULLET_SPEED;
		x = pX + (PLAYER_WIDTH - BULLET_WIDTH) / 2;
		y = pY + PLAYER_HEIGHT + BULLET_SPAWN_DISTANCE;
		break;
	}
	width = BULLET_WIDTH;
	height = BULLET_HEIGHT;

	if (isP1)
		shape.setFillColor(sf::Color(P1_BULLET_COLOR));
	else
		shape.setFillColor(sf::Color(P2_BULLET_COLOR));
	shape.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
}

sf::Drawable *Bullet::getImg()
{
	shape.setPosition(sf::Vector2f(x, y));
	return &shape;
}