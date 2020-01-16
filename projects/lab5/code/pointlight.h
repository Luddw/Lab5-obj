#pragma once
#include "matlib.h"
#include "graphicnode.h"

class PointLight 
{
public:
	PointLight();
	PointLight(Vector4D pos, Vector4D color, float intensity, float ambient);
private:
	Vector4D pos;
	Vector4D color;
	float ambient;
	float intensity;
};