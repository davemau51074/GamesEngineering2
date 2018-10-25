#include "Jumping.h"
#include "Animation.h"

void Jumping::idle(Animation* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
