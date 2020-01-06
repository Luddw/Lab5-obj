#pragma once
#include "matlib.h"

class PointLight 
{
public:

	PointLight(const Vector4D pos) : p(pos) {};

private:
	Vector4D p;

};

