#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");
	sf::Clock gameTime;
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
		game.Update(gameTime.restart().asSeconds());
		window.clear();
		window.draw(game);
		window.display();
	}


	return 0;
}