#include "pointlight.h"

PointLight::PointLight() {
	

}
PointLight::PointLight(Vector4D pos, Vector4D color, float intensity, float ambient)
{
	this->pos = pos;
	this->color = color;
	this->intensity = intensity;
	this->ambient = ambient;
}

