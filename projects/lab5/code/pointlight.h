#pragma once

class Vector4D;
class Transform;

class PointLight 
{
public:
	PointLight();
	~PointLight();
	
	void SetColor(Vector4D color);
	Transform GetTrans();
	void SetIntensity();
private:
	Vector4D color;
	Transform trans;
	float intensity;
	MeshResource mesh;
};

inline void PointLight::SetColor(Vector4D color)
{
}

inline Transform PointLight::GetTrans()
{
}

inline void PointLight::SetIntensity()
{
}
