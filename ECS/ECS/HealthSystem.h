#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include "System.h"
#include "Component.h"
#include <iostream>
#include "HealthComponent.h"

class HealthSystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	void update()
	{
		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{
				if (c->getType() == "H")
				{
					dynamic_cast<HealthComponent*>(c)->update();
				}
				
			}
		}
	}
};





#endif