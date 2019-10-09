#include "graphicnode.h"


//GraphicNode::GraphicNode(MeshResource mesh, Texture tex, ShaderResource shader, Transform trans, Cam cam)
//{
//	p_Mesh = std::make_shared<MeshResource>(mesh);
//	p_Shader = std::make_shared<ShaderResource>(shader);
//	p_Texture = std::make_shared<Texture>(tex);
//	p_Transform = std::make_shared<Transform>(trans);
//	p_Cam = std::make_shared<Cam>(cam);
//	
//}


GraphicNode::GraphicNode() :
	p_Mesh(nullptr), p_Texture(nullptr), p_Shader(nullptr), p_Transform(nullptr), p_Cam(nullptr)
{
}

GraphicNode::~GraphicNode()
{
}

GraphicNode::GraphicNode(std::shared_ptr<MeshResource> mesh, std::shared_ptr<Texture> texture,
	std::shared_ptr<ShaderResource> shader, std::shared_ptr<Transform> transform, std::shared_ptr<Cam> cam)
{

	p_Mesh = std::move(mesh);
	p_Texture = std::move(texture);
	p_Shader = std::move(shader);
	p_Transform = std::move(transform);
	p_Cam = std::move(cam);
}

void GraphicNode::Draw()
{
	p_Mesh->DrawCube(1);
	p_Texture->Bind(0);
	p_Shader->Bind();
	p_Shader->SetUniformMatrix4fv("m", p_Transform->MakeModel());
	p_Shader->SetUniformMatrix4fv("vp", p_Cam->GetProj() * p_Cam->GetView());

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	p_Mesh->UnBindIbo();
	p_Mesh->UnBindVbo();
	p_Texture->Unbind();
	p_Shader->UnBind();
}



void GraphicNode::SetMesh(MeshResource& newmesh)
{
	p_Mesh = std::make_shared<MeshResource>(newmesh);
}

void GraphicNode::SetShader(ShaderResource& newshad)
{
	p_Shader = std::make_shared<ShaderResource>(newshad);
}

void GraphicNode::SetTexture(Texture& newtex)
{
	p_Texture = std::make_shared<Texture>(newtex);
}

void GraphicNode::SetTransform(Transform& newtrans)
{
	p_Transform = std::make_shared<Transform>(newtrans);
}

std::shared_ptr<MeshResource> GraphicNode::GetMesh() const
{
	return p_Mesh;
}

std::shared_ptr<ShaderResource> GraphicNode::GetShader() const
{
	return p_Shader;
}

std::shared_ptr<Texture> GraphicNode::GetTexture() const
{
	return p_Texture;
}

std::shared_ptr<Transform> GraphicNode::GetTransform() const
{
	return p_Transform;
}
