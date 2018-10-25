#ifndef STATE_H
#define STATE_H

#include <iostream>

using namespace std;

class Animation;

class State
{
public:
	virtual void idle(Animation* a);
	virtual void jumping(Animation* a);
	virtual void climbing(Animation* a);
};

#endif // !STATE_H