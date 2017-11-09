#include "player.h"



void player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect,states);
}

player::player()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
}


void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));
	}

	counterWalking++;

	if (counterWalking == 2)
	{
		counterWalking = 0;
	}
}

player::~player()
{
}
