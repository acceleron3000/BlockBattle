#pragma once
#include "GameObject.hpp"
#include <SFML\Graphics.hpp>
#include "Constants.hpp"
#include "Direction.hpp"
#include "Bullet.h"
#include <memory>

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
	bool isStunned() const { return stunTime > 0; }
	void stunCoolDown() { --stunTime; }
	void stun() { stunTime = PLAYER_STUN_TIME; }
	std::shared_ptr<Bullet> toFire(bool key);

protected:
	sf::Drawable *getImg();
#if SHOW_HIT_BOXES
	sf::Drawable &getHitbox();
#endif

private:
	bool isP1;
	int stunTime = 0;
	Direction dir = DOWN;
	bool isAnimating = false;
	int animStep = 0;
	bool useFrameOne = true;
	bool isFiring = false;
	sf::Sprite faceDown1;
	sf::Texture faceDown1t;
	sf::Sprite faceDown2;
	sf::Texture faceDown2t;
	sf::Sprite faceUp1;
	sf::Texture faceUp1t;
	sf::Sprite faceUp2;
	sf::Texture faceUp2t;
	sf::Sprite faceRight1;
	sf::Texture faceRight1t;
	sf::Sprite faceRight2;
	sf::Texture faceRight2t;
	sf::Sprite faceLeft1;
	sf::Texture faceLeft1t;
	sf::Sprite faceLeft2;
	sf::Texture faceLeft2t;
	sf::Sprite *currentFace;
#if SHOW_HIT_BOXES
	sf::RectangleShape hitboxShape;
#endif
};
