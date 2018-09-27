#pragma once
#include <iostream>
using namespace std;

class Character
{
public: 
	Character() { }
				void Print() { cout << "Printing Character outputs" << endl; }

};

class HandleToCharacter
{
public: 
	HandleToCharacter() : character(new Character()) {}
	Character* operator->() { return character; } //overload -> 
private: 
	Character * character;

};
