#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
class player :
	public entity
{

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	player();
	int movementSpeed = 100;
	int attackDamage = 5;
	int counterWalking = 0;

	void update();
	void updateMovement();
	~player();
};

#endif // !PLAYER_H