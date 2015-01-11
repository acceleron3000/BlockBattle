#include <SFML\Graphics.hpp>
#include "KeyMan.hpp"
#include "Game.hpp"
#include "Constants.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void handleEvents(sf::RenderWindow &window, KeyMan &keys)
{
	sf::Event evt;
	while (window.pollEvent(evt))
	{
		switch (evt.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			keys.keyPressed(evt.key.code);
			break;
		case sf::Event::KeyReleased:
			keys.keyReleased(evt.key.code);
			break;
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);

	KeyMan keys = KeyMan();
	Game game(keys);

	std::chrono::high_resolution_clock::time_point lastPoint = std::chrono::high_resolution_clock::now();
	while (window.isOpen())
	{
		//update game:
		handleEvents(window, keys);
		game.onGameLoop();

		//update screen:
		window.clear();
		game.draw(window);
		window.display();

		//update interval
		std::chrono::high_resolution_clock::time_point curPoint = std::chrono::high_resolution_clock::now();
		std::chrono::microseconds elapsed = std::chrono::duration_cast<std::chrono::microseconds>(curPoint - lastPoint);
		long long passed = elapsed.count();
		//std::cout << passed << " v " << FRAME_PERIOD << " period\n";
		//if (passed > 0)
			//std::cout << (1000000 / passed) << " v " << FRAME_RATE << " fps\n\n";
		lastPoint = curPoint;

		std::this_thread::sleep_for(std::chrono::microseconds(FRAME_PERIOD/2));
	}
	return EXIT_SUCCESS;
}