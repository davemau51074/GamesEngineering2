#pragma once
#include <iostream>
using namespace std;

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void draw() = 0;
};

class Player : public Object
{
public:
	void draw() {
		cout << "Draw Player" << endl;
	}

};

class Enemy : public Object {
public: 
	void draw() {
		cout << "Draw Enemy" << endl;
	}
};