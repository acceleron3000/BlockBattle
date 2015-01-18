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

/*
	bumps "this" object, relative to the "other" object's position
*/
void GameObject::bump(GameObject &other)
{
	bool hasSet = false;

	//position-based bumping
	if (x < other.x)
	{
		speedX = -PLAYER_BUMP_SPEED;
		//other.speedX = PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	else if (x > other.x)
	{
		speedX = PLAYER_BUMP_SPEED;
		//other.speedX = -PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	if (y < other.y)
	{
		speedY = -PLAYER_BUMP_SPEED;
		//other.speedY = PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	else if (y > other.y)
	{
		speedY = PLAYER_BUMP_SPEED;
		//other.speedY = -PLAYER_BUMP_SPEED;
		hasSet = true;
	}

	//if same position, speed-based bumping
	if (!hasSet)
	{
		hasSet = false;
		if (speedX > 0 || other.speedX < 0)
		{
			speedX = -PLAYER_BUMP_SPEED;
			//other.speedX = PLAYER_BUMP_SPEED;
			hasSet = true;
		}
		else if (speedX < 0 || other.speedX > 0)
		{
			speedX = PLAYER_BUMP_SPEED;
			//other.speedX = -PLAYER_BUMP_SPEED;
			hasSet = true;
		}

		if (speedY > 0 || other.speedY < 0)
		{
			speedY = -PLAYER_BUMP_SPEED;
			//other.speedY = PLAYER_BUMP_SPEED;
			hasSet = true;
		}
		else if (speedY < 0 || other.speedY > 0)
		{
			speedY = PLAYER_BUMP_SPEED;
			//other.speedY = -PLAYER_BUMP_SPEED;
			hasSet = true;
		}

		//if same position and no speeds, bump vertically
		if (!hasSet)
		{
			speedY = PLAYER_BUMP_SPEED;
			//other.speedY = -PLAYER_BUMP_SPEED;
		}
	}
}

