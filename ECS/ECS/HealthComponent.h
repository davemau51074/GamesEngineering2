#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : m_health(100) { setType("H"); }

		int health() { return m_health; }
		void setHealth(int h) { this->m_health = h; }
		void update() {
			this->m_health++;
				std::cout << "Health: " << m_health << std::endl;
		}
		std::string getType() { return m_type; }

private:
	int m_health;
	//std::string m_type;

};



#endif
