#include "Game.h"
#include "SFML/OpenGL.hpp"
#include <iostream>
#include "entity.h"
#include "player.h"

Game::Game()
{
	//initialise all game variables here
	crossHair = sf::CircleShape(20.0f);
	crossHair.setPosition(sf::Vector2f(sf::Mouse::getPosition()));
	if (!texturePlayer.loadFromFile("Assets/spriteWalk.png")) {
		std::cout << "ERROR" << std::endl;
	}
	sf::Sprite spritePlayer(texturePlayer);
	spritePlayer.setTextureRect(sf::IntRect(0, 0, 32, 32));

}


Game::~Game()
{
	//Clean up game
}

void Game::Update(float dt,sf::Event event,sf::Vector2f mousePos)
{
	//All logic goes here with input handling

	if (event.type == sf::Event::MouseMoved)
	{
		crossHair.setPosition(mousePos);
	}
}


void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//draw everyting in the game

	target.draw(player1, states);
	target.draw(crossHair, states);
	
}


sf::Vector2f Game::movement()
{
	bool isWPressed, isAPressed, isSpressed, isDPressed;
	sf::Vector2f movement;
	isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	isAPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	isSpressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	isDPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	//Horizontal player movement
	if (isWPressed)
	{
		movement.y = -100.0f;
	}

	else if (isSpressed)
	{
		movement.y = 100.0f;
	}

	else
	{
		movement.y = 0.0f;
	}

	//Vertical player movement
	if (isAPressed)
	{
		movement.x = -100.0f;

	}

	else if (isDPressed)
	{
		movement.x = 100.0f;

	}

	else
	{
		movement.x = 0.0f;
	}
	return movement;
}