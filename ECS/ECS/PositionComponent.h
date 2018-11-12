#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include <string>
#include <iostream>

#include "Component.h"

class PositionComponent : public Component
{
	public:
		PositionComponent() : m_pos(std::make_pair(100, 100)) { setType("POS"); }

		void update() {
			//this->m_pos.first++;
			//this->m_pos.second++;
			std::cout << "Pos X: " << this->m_pos.first <<
				"Pos Y: " << this->m_pos.second << std::endl;
		}
		std::string getType() { return this->m_type; }
		std::pair<int, int>getPosition() { return m_pos; }
		void setPos(std::pair<int, int>p) { m_pos = p; }
		
private:
	std::pair<int, int> m_pos;
};

#endif