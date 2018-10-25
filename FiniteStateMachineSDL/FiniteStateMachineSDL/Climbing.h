#ifndef CLIMBING_H
#define CLIMBING_H

#include "State.h"
#include "Jumping.h"
#include "Idle.h"

class Idle;
class Jumping;

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
};

#endif // !CLIMBING_H