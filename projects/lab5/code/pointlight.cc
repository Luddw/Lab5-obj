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

Vector4D PointLight::GetPos() const
{
	return pos;
}

Vector4D PointLight::GetColor() const
{
	return color;
}

float PointLight::GetAmbient() const
{
	return ambient;
}

float PointLight::GetIntensity() const
{
	return intensity;
}

