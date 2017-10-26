#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>

class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	void Update(float dt,sf::Event event ,sf::Vector2f mousePos);


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::RectangleShape player;
	sf::CircleShape crossHair;
	sf::Vector2f movement();
};

#endif
