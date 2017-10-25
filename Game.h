#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>

class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	void Update(float dt);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape rect;
	sf::Vector2f movement;
	bool wasWPressed, wasAPressed, wasSPressed, wasDPressed;
	bool isWPressed, isAPressed, isSpressed, isDPressed;
};

#endif
