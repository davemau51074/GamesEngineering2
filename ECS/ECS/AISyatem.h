#ifndef AISYSTEM_H
#define AISYSTEM_H

#include "System.h"
#include <iostream>
#include "Component.h"
#include "PositionComponent.h"
#include <SDL.h>

class AISystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	bool moving = false;
	bool posTaken = false;
	std::pair<int, int> tmp_pos;
	PositionComponent * posCom = new PositionComponent();

	void update()
	{
		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{

				if (c->getType() == "POSITION")
				{
					posCom = dynamic_cast<PositionComponent*>(c);

					posCom->setPos(std::make_pair<int, int>(posCom->getPosition().first + 1, posCom->getPosition().second + 1));
				}

			}
		}
	}
};




#endif // !AISYSTEM_H

