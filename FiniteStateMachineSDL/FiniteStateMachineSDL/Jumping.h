#ifndef JUMPING_H
#define JUMPING_H

#include "State.h"

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
};

#endif // !JUMPING_H