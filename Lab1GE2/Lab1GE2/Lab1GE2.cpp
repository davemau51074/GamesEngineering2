// Lab1GE2.cpp : Defines the entry point for the console application.
//By David O'Gorman
//17th of September 2018

#include "stdafx.h"
#include "objects.h"
#include "Factory.h"
#include "BDCharacter.h"
#include "ProxyD.h"
#include "Proxy.h"
#include "HInterface.h"
#include "RS.h"
#include "ProxyR.h"
#include <vector>

//
//int main()
//{ 
//	Factory* factory = new ObjectFactory;
//	vector<Object*> objects;
//	objects.push_back(factory ->
//		CreatePlayer());
//	objects.push_back(factory->CreateOpponents());
//
//	for (int i = 0; i < objects.size(); i++)
//	{
//		objects[i]->draw();
//	}
//	system("PAUSE");
//}
//
int main()
{
	HandleToCharacter handle; handle->Print();
	system("PAUSE");
}
//
//int main(void)
//{
//	GraphicProxy gp;
//	gp.Draw();
//
//	system("Pause");
//}