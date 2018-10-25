#include "State.h"
#include "Animation.h"

void State::idle(Animation* a)
{
	cout << "State::Idling" << endl;
}

void State::jumping(Animation* a)
{
	cout << "State::Jumping" << endl;
}

void State::climbing(Animation* a)
{
	cout << "State::Climbing" << endl;
}