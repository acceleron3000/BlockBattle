#pragma once
class KeyMan
{
public:
	KeyMan(){}
	~KeyMan(){}

	void keyPressed(const sf::Keyboard::Key &code);
	void keyReleased(const sf::Keyboard::Key &code);

	//p1 getters
	bool isKeyP1Right() const { return p1Right; }
	bool isKeyP1Left() const { return p1Left; }
	bool isKeyP1Up() const { return p1Up; }
	bool isKeyP1Down() const { return p1Down; }
	
	//p2 getters
	bool isKeyP2Right() const { return p2Right; }
	bool isKeyP2Left() const { return p2Left; }
	bool isKeyP2Up() const { return p2Up; }
	bool isKeyP2Down() const { return p2Down; }

private:
	bool p1Right = false;
	bool p1Left = false;
	bool p1Up = false;
	bool p1Down = false;

	bool p2Right = false;
	bool p2Left = false;
	bool p2Up = false;
	bool p2Down = false;
};
