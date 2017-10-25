#include "Game.h"

Game::Game()
{
	//initialise all game variables here
	rect = sf::RectangleShape(sf::Vector2f(60.0, 60.0));
	bool wasWPressed, wasAPressed, wasSPressed, wasDPressed = false;
	movement = sf::Vector2f(0.0f, 0.0f);
}


Game::~Game()
{
	//Clean up game
}

void Game::Update(float dt)
{
	//All logic goes here with input handling

	isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	isAPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	isSpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	isDPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	if (isAPressed&&!wasAPressed)
	{
		movement.x = -1.0f;

	}
	if (isSpressed&&!wasSPressed)
	{
		movement.y = 1.0f;

	}
	if (isDPressed&&!wasDPressed)
	{
		movement.x = 1.0f;
	
	}
	if (isWPressed&&!wasWPressed)
	{
		movement.y = -1.0f;
	
	}
	else
	{
		movement.x = 0.0f;
		movement.y = 0.0f;
	}


	wasSPressed = isSpressed;
	wasDPressed = isDPressed;
	wasWPressed = isWPressed;
	wasAPressed = isAPressed;
	rect.move(movement*dt);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//draw everyting in the game
	target.draw(rect, states);
	
}
