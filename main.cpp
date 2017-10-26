#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "GameWindow");
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	
	sf::Clock gameTime;
	sf::Mouse::setPosition(sf::Vector2i(400, 300),window);
	
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		game.Update(gameTime.restart().asSeconds(),event,sf::Vector2f(sf::Mouse::getPosition(window)));
		window.clear();
		window.draw(game);
		window.display();
	}


	return 0;
}