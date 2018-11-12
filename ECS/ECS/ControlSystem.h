#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include "System.h"
#include "Component.h"
#include <iostream>
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlComponent.h"
#include <SDL.h>

class ControlSystem : public System
{
public:
	void addEntity(Entity * e) { this->m_entities.push_back(e); }
	bool moving = false;
	bool posTaken = false;
	std::pair<int, int> tmp_pos;
	PositionComponent * posCos = new PositionComponent();
	ControlComponent * comCos = new ControlComponent();

	void update(SDL_Event &ev)
	{
		for (auto e : m_entities)
		{
			std::vector<Component*> tmp_components = e->getComponents();

			for (auto c : tmp_components)
			{
				if (c->getType() == "CONTROL")
				{
					comCos = dynamic_cast<ControlComponent*>(c);
				}

				if (c->getType() == "POS")
				{
					posCos = dynamic_cast<PositionComponent*>(c);
				}

			}
			comCos->update(ev);
 			if (comCos->move)
			{
				posCos->setPos(std::make_pair<int, int>(posCos->getPosition().first + 10, posCos->getPosition().second + 10));
				comCos->move = false;
			}
		}

	}
};



#endif // !CONTROLSYSTEM_H

