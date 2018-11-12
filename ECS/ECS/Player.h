#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Component.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void update();
	void addComponent(Component *);
private:
};


#endif
