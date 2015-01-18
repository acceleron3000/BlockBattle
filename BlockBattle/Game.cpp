#include "Game.hpp"


Game::Game(const KeyMan &keyman) :
p1(true), p2(false), keys(keyman), bullets()
{

}

void Game::onGameLoop()
{
	updateControls();
	updateMovement();
	resolvePlayerCollisions();
	resolveBulletCollisions();
	updateWrapAround();
}

void Game::updateControls()
{
	std::shared_ptr<Bullet> bullet;
	if (p1.isStunned())
	{
		//p1.brakeX();
		//p1.brakeY();
		p1.stunCoolDown();
	}
	else
	{
		if (keys.isKeyP1Right())
			p1.moveRight();
		else if (keys.isKeyP1Left())
			p1.moveLeft();
		else
			p1.brakeX();
		if (keys.isKeyP1Up())
			p1.moveUp();
		else if (keys.isKeyP1Down())
			p1.moveDown();
		else
			p1.brakeY();
		
		bullet = p1.toFire(keys.isKeyP1Fire());
		if (bullet != nullptr){
			bullets.push_front(bullet);
		}
	}

	if (p2.isStunned())
	{
		//p2.brakeX();
		//p2.brakeY();
		p2.stunCoolDown();
	}
	else
	{
		if (keys.isKeyP2Right())
			p2.moveRight();
		else if (keys.isKeyP2Left())
			p2.moveLeft();
		else
			p2.brakeX();
		if (keys.isKeyP2Up())
			p2.moveUp();
		else if (keys.isKeyP2Down())
			p2.moveDown();
		else
			p2.brakeY();
		
		bullet = p2.toFire(keys.isKeyP2Fire());
		if (bullet != nullptr){
			bullets.push_front(bullet);
		}
	}
}

void Game::updateMovement()
{
	p1.updateMovement();
	p2.updateMovement();
	for (auto i = bullets.begin(); i != bullets.end(); i++)
	{
		(**i).updateMovement();
	}
}

void Game::resolvePlayerCollisions()
{
	if (p1.isCollidingWith(p2))
	{
		p1.bump(p2);
		//p2.bump(p1);
	}
}

void Game::resolveBulletCollisions()
{
	
}

void Game::updateWrapAround()
{
	p1.wrap();
	p2.wrap();
	for (auto i = bullets.begin(); i != bullets.end(); i++)
	{
		(**i).wrap();
	}
}

void Game::draw(sf::RenderWindow &window)
{
	p1.draw(window);
	p2.draw(window);
	for (auto i = bullets.begin(); i != bullets.end(); i++)
	{
		(**i).draw(window);
	}
}