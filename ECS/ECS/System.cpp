#include "System.h"

System::System()
{

}


void System::addEntity(Entity * e)
{
	m_entities.push_back(e);
}


void System::update()
{
}