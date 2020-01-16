#pragma once
#include "meshresource.h"
#include "shaderresource.h"
#include "texture.h"
#include "transform.h"
#include "cam.h"
#include <memory>
#include "pointlight.h"
class GraphicNode
{
private:
	std::shared_ptr<MeshResource> p_Mesh;
	std::shared_ptr<Texture> p_Texture;
	std::shared_ptr<ShaderResource> p_Shader;
	std::shared_ptr<Transform> p_Transform;
	std::shared_ptr<Cam> p_Cam;
	static PointLight *lightsrc;
public:
	GraphicNode();
	GraphicNode(MeshResource mesh, Texture tex, ShaderResource shader, Transform trans, Cam cam);
	~GraphicNode();
	GraphicNode(std::shared_ptr<MeshResource> mesh, std::shared_ptr<Texture> texture, std::shared_ptr<ShaderResource> shader, std::shared_ptr<Transform> transform, std::shared_ptr<Cam> cam);
	void Draw();

	void SetMesh(MeshResource& newmesh);
	void SetShader(ShaderResource& newshad);
	void SetTexture(Texture& newtex);
	void SetTransform(Transform& newtrans);

	std::shared_ptr<MeshResource> GetMesh() const;
	std::shared_ptr<ShaderResource> GetShader();
	std::shared_ptr<Texture> GetTexture() const;
	std::shared_ptr<Transform> GetTransform() const;
	
	static void SetLight(PointLight light);
};