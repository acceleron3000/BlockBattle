#include <SFML\Graphics.hpp>
#include "KeyMan.hpp"

void KeyMan::keyPressed(const sf::Keyboard::Key &code){
	switch (code){
	case sf::Keyboard::Right:
		p1Right = true;
		break;
	case sf::Keyboard::Left:
		p1Left = true;
		break;
	case sf::Keyboard::Up:
		p1Up = true;
		break;
	case sf::Keyboard::Down:
		p1Down = true;
		break;
	case sf::Keyboard::W:
		p2Up = true;
		break;
	case sf::Keyboard::D:
		p2Right = true;
		break;
	case sf::Keyboard::A:
		p2Left = true;
		break;
	case sf::Keyboard::S:
		p2Down = true;
		break;
	}
}
void KeyMan::keyReleased(const sf::Keyboard::Key &code){
	switch (code){
	case sf::Keyboard::Right:
		p1Right = false;
		break;
	case sf::Keyboard::Left:
		p1Left = false;
		break;
	case sf::Keyboard::Up:
		p1Up = false;
		break;
	case sf::Keyboard::Down:
		p1Down = false;
		break;
	case sf::Keyboard::W:
		p2Up = false;
		break;
	case sf::Keyboard::D:
		p2Right = false;
		break;
	case sf::Keyboard::A:
		p2Left = false;
		break;
	case sf::Keyboard::S:
		p2Down = false;
		break;
	}
}
