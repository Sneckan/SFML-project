#pragma once
#include <SFML\Graphics.hpp>

class entity
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	entity();
	~entity();
};

