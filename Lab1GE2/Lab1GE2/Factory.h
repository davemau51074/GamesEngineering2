#pragma once
#include "objects.h"


class Factory {
public: 
	virtual Object* CreatePlayer() = 0;
	virtual Object* CreateOpponents() = 0;


};

class ObjectFactory : public Factory {
public:
	Object * CreatePlayer() {
		return new Player;
	}
	Object* CreateOpponents() {
		return new Enemy;
	}
};