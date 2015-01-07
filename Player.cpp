#include "Player.hpp"
#include <iostream>

void imageError()
{
	std::cout << "Images not found." << std::endl;
}

Player::Player(bool isPlayer1):
isP1(isPlayer1)
{
	width = PLAYER_WIDTH;
	height = PLAYER_HEIGHT;
	//shape.setSize(sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
	sf::Texture texture;
	if (isPlayer1)
	{
		x = P1_START_X;
		y = P1_START_Y;

		if (!texture.loadFromFile(P1_FACE_D1))
			imageError();
		faceDown1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_D2))
			imageError();
		faceDown2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_U1))
			imageError();
		faceUp1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_U2))
			imageError();
		faceUp2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_R1))
			imageError();
		faceRight1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_R2))
			imageError();
		faceRight2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_L1))
			imageError();
		faceLeft1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P1_FACE_L2))
			imageError();
		faceLeft2 = sf::Sprite(texture);
		//shape.setPosition(x, y);
		//shape.setFillColor(sf::Color::Color(P1_COLOR));
	}
	else
	{
		x = P2_START_X;
		y = P2_START_Y;

		if (!texture.loadFromFile(P2_FACE_D1))
			imageError();
		faceDown1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_D2))
			imageError();
		faceDown2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_U1))
			imageError();
		faceUp1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_U2))
			imageError();
		faceUp2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_R1))
			imageError();
		faceRight1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_R2))
			imageError();
		faceRight2 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_L1))
			imageError();
		faceLeft1 = sf::Sprite(texture);

		if (!texture.loadFromFile(P2_FACE_L2))
			imageError();
		faceLeft2 = sf::Sprite(texture);
		//shape.setPosition(x, y);
		//shape.setFillColor(sf::Color::Color(P2_COLOR));
	}
	currentFace = &faceDown1;
}

void Player::moveRight()
{
	speedX = MOVE_SPEED;
	dir = RIGHT;
}
void Player::moveLeft()
{
	speedX = -MOVE_SPEED;
	dir = LEFT;
}
void Player::moveUp()
{
	speedY = -MOVE_SPEED;
	dir = UP;
}
void Player::moveDown()
{
	speedY = MOVE_SPEED;
	dir = DOWN;
}
void Player::brakeX()
{
	speedX = 0;
}
void Player::brakeY()
{
	speedY = 0;
}

sf::Drawable &Player::getImg(){
	//currentFace->setPosition(sf::Vector2f(x, y));
	//return currentFace;
	faceDown1.setPosition(sf::Vector2f(x, y));
	return faceDown1;
}

/*
* called when collision between players
*/
void Player::bump(Player &other)
{
	bool hasSet = false;

	stun();
	other.stun();

	//position-based bumping
	if (x < other.x)
	{
		speedX = -PLAYER_BUMP_SPEED;
		other.speedX = PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	else if (x > other.x)
	{
		speedX = PLAYER_BUMP_SPEED;
		other.speedX = -PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	if (y < other.y)
	{
		speedY = -PLAYER_BUMP_SPEED;
		other.speedY = PLAYER_BUMP_SPEED;
		hasSet = true;
	}
	else if (y > other.y)
	{
		speedY = PLAYER_BUMP_SPEED;
		other.speedY = -PLAYER_BUMP_SPEED;
		hasSet = true;
	}

	//if same position, speed-based bumping
	if (!hasSet)
	{
		hasSet = false;
		if (speedX > 0 || other.speedX < 0)
		{
			speedX = -PLAYER_BUMP_SPEED;
			other.speedX = PLAYER_BUMP_SPEED;
			hasSet = true;
		}
		else if (speedX < 0 || other.speedX > 0)
		{
			speedX = PLAYER_BUMP_SPEED;
			other.speedX = -PLAYER_BUMP_SPEED;
			hasSet = true;
		}

		if (speedY > 0 || other.speedY < 0)
		{
			speedY = -PLAYER_BUMP_SPEED;
			other.speedY = PLAYER_BUMP_SPEED;
			hasSet = true;
		}
		else if (speedY < 0 || other.speedY > 0)
		{
			speedY = PLAYER_BUMP_SPEED;
			other.speedY = -PLAYER_BUMP_SPEED;
			hasSet = true;
		}

		//if same position and no speeds, bump vertically
		if (!hasSet)
		{
			speedY = PLAYER_BUMP_SPEED;
			other.speedY = -PLAYER_BUMP_SPEED;
		}
	}
}
