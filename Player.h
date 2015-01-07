#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "Direction.h"

class Player : public GameObject
{
public:
	Player(bool isPlayer1);
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void brakeX();
	void brakeY();
	void bump(Player &other);
	bool isStunned(){ return stunTime > 0; }
	void stunCoolDown() { --stunTime; }
	void stun() { stunTime = PLAYER_STUN_TIME; }

protected:
	sf::Drawable &getImg();

private:
	bool isP1;
	int stunTime = 0;
	//sf::RectangleShape shape;
	Direction dir = DOWN;
	sf::Sprite faceDown1;
	sf::Sprite faceDown2;
	sf::Sprite faceUp1;
	sf::Sprite faceUp2;
	sf::Sprite faceRight1;
	sf::Sprite faceRight2;
	sf::Sprite faceLeft1;
	sf::Sprite faceLeft2;
	sf::Sprite *currentFace;
};
