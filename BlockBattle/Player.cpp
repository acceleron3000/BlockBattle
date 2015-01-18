#include "Player.hpp"
#include <iostream>
#include "Bullet.h"

void imageError()
{
	std::cout << "Images not found." << std::endl;
}

Player::Player(bool isPlayer1):
isP1(isPlayer1)
{
	width = PLAYER_WIDTH;
	height = PLAYER_HEIGHT;
#if SHOW_HIT_BOXES
	hitboxShape.setFillColor(sf::Color(255,255,255,155));
	hitboxShape.setSize(sf::Vector2f(width, height));
#endif
	if (isPlayer1)
	{
		x = P1_START_X;
		y = P1_START_Y;

		if (!faceDown1t.loadFromFile(P1_FACE_D1))
			imageError();
		faceDown1.setTexture(faceDown1t);

		if (!faceDown2t.loadFromFile(P1_FACE_D2))
			imageError();
		faceDown2.setTexture(faceDown2t);

		if (!faceUp1t.loadFromFile(P1_FACE_U1))
			imageError();
		faceUp1.setTexture(faceUp1t);

		if (!faceUp2t.loadFromFile(P1_FACE_U2))
			imageError();
		faceUp2.setTexture(faceUp2t);

		if (!faceRight1t.loadFromFile(P1_FACE_R1))
			imageError();
		faceRight1.setTexture(faceRight1t);

		if (!faceRight2t.loadFromFile(P1_FACE_R2))
			imageError();
		faceRight2.setTexture(faceRight2t);

		if (!faceLeft1t.loadFromFile(P1_FACE_L1))
			imageError();
		faceLeft1.setTexture(faceLeft1t);

		if (!faceLeft2t.loadFromFile(P1_FACE_L2))
			imageError();
		faceLeft2.setTexture(faceLeft2t);
		//shape.setPosition(x, y);
		//shape.setFillColor(sf::Color::Color(P1_COLOR));
	}
	else
	{
		x = P2_START_X;
		y = P2_START_Y;

		if (!faceDown1t.loadFromFile(P2_FACE_D1))
			imageError();
		faceDown1.setTexture(faceDown1t);

		if (!faceDown2t.loadFromFile(P2_FACE_D2))
			imageError();
		faceDown2.setTexture(faceDown2t);

		if (!faceUp1t.loadFromFile(P2_FACE_U1))
			imageError();
		faceUp1.setTexture(faceUp1t);

		if (!faceUp2t.loadFromFile(P2_FACE_U2))
			imageError();
		faceUp2.setTexture(faceUp2t);

		if (!faceRight1t.loadFromFile(P2_FACE_R1))
			imageError();
		faceRight1.setTexture(faceRight1t);

		if (!faceRight2t.loadFromFile(P2_FACE_R2))
			imageError();
		faceRight2.setTexture(faceRight2t);

		if (!faceLeft1t.loadFromFile(P2_FACE_L1))
			imageError();
		faceLeft1.setTexture(faceLeft1t);

		if (!faceLeft2t.loadFromFile(P2_FACE_L2))
			imageError();
		faceLeft2.setTexture(faceLeft2t);
		//shape.setPosition(x, y);
		//shape.setFillColor(sf::Color::Color(P2_COLOR));
	}
	currentFace = &faceDown1;
}

void Player::moveRight()
{
	speedX = MOVE_SPEED;
	dir = RIGHT;
	isAnimating = true;
}
void Player::moveLeft()
{
	speedX = -MOVE_SPEED;
	dir = LEFT;
	isAnimating = true;
}
void Player::moveUp()
{
	speedY = -MOVE_SPEED;
	dir = UP;
	isAnimating = true;
}
void Player::moveDown()
{
	speedY = MOVE_SPEED;
	dir = DOWN;
	isAnimating = true;
}
void Player::brakeX()
{
	speedX = 0;
}
void Player::brakeY()
{
	speedY = 0;
}

std::shared_ptr<Bullet> Player::toFire(bool key)
{
	if (key && !isFiring)
	{
		isFiring = true;
		return std::make_shared<Bullet>(dir, isP1, x, y);
	}
	else if (!key)
	{
		isFiring = false;
	}
	return nullptr;
}

sf::Drawable *Player::getImg(){
	if (isAnimating)
	{
		animStep--;
		if (animStep <= 0){
			useFrameOne = !useFrameOne;
			animStep = PLAYER_ANIMATION_DELAY;
		}
	}
	switch (dir)
	{
	case UP:
		if (useFrameOne)
			currentFace = &faceUp1;
		else
			currentFace = &faceUp2;
		break;
	case DOWN:
		if (useFrameOne)
			currentFace = &faceDown1;
		else
			currentFace = &faceDown2;
		break;
	case LEFT:
		if (useFrameOne)
			currentFace = &faceLeft1;
		else
			currentFace = &faceLeft2;
		break;
	case RIGHT:
		if (useFrameOne)
			currentFace = &faceRight1;
		else
			currentFace = &faceRight2;
		break;
	}
	currentFace->setPosition(sf::Vector2f(x - (currentFace->getTexture()->getSize().x - PLAYER_WIDTH) / 2, y - (currentFace->getTexture()->getSize().y - PLAYER_HEIGHT) / 2));
	isAnimating = false;

	return currentFace;
}

#if SHOW_HIT_BOXES
sf::Drawable &Player::getHitbox(){
	hitboxShape.setPosition(sf::Vector2f(x, y));
	return hitboxShape;
}
#endif
