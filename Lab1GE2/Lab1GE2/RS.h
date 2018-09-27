#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "HInterface.h"

class Graphic : public
	IGraphic
{
public: 
	Graphic();
	~Graphic();
	void Draw();
};

#endif
