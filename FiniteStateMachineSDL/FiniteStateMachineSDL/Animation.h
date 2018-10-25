#ifndef ANIMATION_H
#define ANIMATION_H

#include "State.h"
#include "Idle.h"

class Animation
{
public:
	Animation();
	State * current;
	void setCurrent(State* s)
	{
		current = s;
	}
	void idle();
	void jumping();
	void climbing();
};

#endif // !ANIMATION_H