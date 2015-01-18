#include "GameObject.hpp"
#include "Constants.hpp"

void GameObject::updateMovement()
{
	x += speedX;
	y += speedY;
}

void GameObject::wrap()
{
	if (x < -DEAD_ZONE)
	{
		x += WINDOW_WIDTH + DEAD_ZONE;
	}
	else if (x + width > WINDOW_WIDTH + DEAD_ZONE)
	{
		x -= WINDOW_WIDTH + DEAD_ZONE;
	}

	if (y < -DEAD_ZONE)
	{
		y += WINDOW_HEIGHT + DEAD_ZONE;
	}
	else if (y + height > WINDOW_HEIGHT + DEAD_ZONE)
	{
		y -= WINDOW_HEIGHT + DEAD_ZONE;
	}
}

void GameObject::draw(sf::RenderWindow &window)
{
	window.draw(*getImg());
#if SHOW_HIT_BOXES
	window.draw(getHitbox());
#endif
}

/*
 * naive way, assumes boxes are reasonably the same size
 */
bool GameObject::isCollidingWith(GameObject &other)
{
	bool intersectVertically = ((y >= other.y && y < other.y + other.height) || (other.y >= y && other.y < y + height));
	bool intersectHorizontally = ((x >= other.x && x < other.x + other.width) || (other.x >= x && other.x < x + width));
	return intersectVertically && intersectHorizontally;
}
