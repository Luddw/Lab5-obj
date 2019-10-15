//------------------------------------------------------------------------------
// Lab5.cc
// (C) 2015-2018 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "lab5.h"
#include <sstream>
#include <GL/glew.h>
#include <iostream>
#include <fstream>

using namespace Display;

namespace Example
{
	//------------------------------------------------------------------------------
	/**
	*/
	Lab5::Lab5()
	{
		// empty
	}
	
	//------------------------------------------------------------------------------
	/**
	*/
	Lab5::~Lab5()
	{
		// empty
	}
	void Lab5::keyEvent(int key, int action, int modifier)
	{

	}
	void Lab5::MousePos(float xpos, float ypos)
	{

	}
	//------------------------------------------------------------------------------
	/**
	*/
	bool ObjLoad(const char* filepath)
	{
		//std::vector<Vector4D> &file_verts;
		//std::vector<Vector4D> &file_uvs;
		//std::vector<Vector4D> &file_norms;

		std::vector<GLuint> vertexIndices, uvIndices, normIndices;
		std::vector<Vector4D> t_verts;
		std::vector<Vector4D> t_uvs;
		std::vector<Vector4D> t_norms;

		std::ifstream stream(filepath);
		std::string line;

		enum type
		{
			v, vt, vn, f, none
		};
		while (getline(stream,line))
		{
			std::string tmp;
			std::stringstream ss(line);
			std::vector<std::string> tokens;
			while (getline(ss,tmp, ' '))
			{
				tokens.push_back(tmp);
			}
			if (tokens.empty())
				continue;

			type t = none;
			if (tokens[0] == "v")
				t = v;
			else if (tokens[0] == "vt")
				t = vt;
			else if (tokens[0] == "vn")
				t = vn;
			else if (tokens[0] == "f")
				t = f;
			else if (tokens[0] ==  "#")
				continue;
			
			//std::cout << tokens[0] << std::endl;
			
			switch (t)
			{
			case v:
				{
					Vector4D vert;
					for (size_t i = 2; i < 5; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &vert[i-1]);
						std::cout << vert[i - 1] << " ";
					}
					std::cout << "\n";
					t_verts.push_back(vert);
					break;
				}
			case vt:
				{	
					Vector4D uv;
					for (size_t i = 1; i < 3; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &uv[i-1]);
						std::cout << uv[i-1] << " ";
					}
					
					std::cout << "\n";
					t_uvs.push_back(uv);
					break;
				}
			case vn:
				{
					Vector4D norm;
					for (size_t i = 1; i < 4; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &norm[i-1]);
						std::cout << norm[i-1] << " ";
					}
					std::cout << "\n";
					t_norms.push_back(norm);
					break;
				}
			case f:
			{
				unsigned int verts, uvs, norms;
				

				if (tokens.size() == 4) //triangle
				{
					for (size_t i = 1; i < 4; i++)
					{
						//sscanf_s(tokens[i].c_str(), "%d/%d/%d", &verts, &uvs, &norms);
						sscanf_s(tokens[i].c_str(), "%d/", &verts);
						std::cout << verts << " ";
						
						vertexIndices.push_back(verts);
						
					}
					std::cout << "\n";
					
				}
				else if (tokens.size() == 5) //quad
				{
					std::vector<GLuint> tempquad;
					for (size_t i = 1; i < 5; i++)
					{
						sscanf_s(tokens[i].c_str(), "%d/", &verts);
						
						tempquad.push_back(verts);
					}
					vertexIndices.push_back(tempquad[0]);
					std::cout << tempquad[0] << " ";
					vertexIndices.push_back(tempquad[1]);
					std::cout << tempquad[1] << " ";
					vertexIndices.push_back(tempquad[3]);
					std::cout << tempquad[3] << " \n";

					vertexIndices.push_back(tempquad[2]);
					std::cout << tempquad[2] << " ";
					vertexIndices.push_back(tempquad[3]);
					std::cout << tempquad[3] << " ";
					vertexIndices.push_back(tempquad[1]);
					std::cout << tempquad[1] << " \n";

					
				}
				
				
					break;
				}
			default:
				break;
			}
			
		}
		std::vector<Vertex> vertexbuff;
		for (size_t i = 0; i <vertexIndices.size(); i++)
		{
			/// TO DO , create buffs and shit;
			vertexbuff.push_back(Vertex(t_verts[i], t_uvs[i]));
		}
		
		return false;
	}
	bool
	Lab5::Open()
	{
		App::Open();
		
		this->window = new Window;
		int w, h;
		this->window->GetSize(w, h);
		window->SetKeyPressFunction([this](int32 key, int32, int32 action, int32 mod)
		{
			this->keyEvent(key, action, mod);
			std::cout <<"Key: "<< key << " action: "<<action << std::endl;
			if (action == 1)
			{
				
				switch (key)
				{
				case GLFW_KEY_D: {cubenode.GetTransform()->Move(-0.1f, 0, 0); break; }
				case GLFW_KEY_A: {cubenode.GetTransform()->Move(0.1f, 0, 0); break; }
				case GLFW_KEY_S: {cubenode.GetTransform()->Move(0, 0, 0.1f); break; }
				case GLFW_KEY_W: {cubenode.GetTransform()->Move(0, 0, -0.1f); break; }
				default: break;
				}
			}
		
			
		}
		);
		
		window->SetMousePressFunction([this](int32 key, int32 action, int32 mod)
		{
			this->keyEvent(key, action, mod);
			std::cout << "Key: " << key << " action: " << action << std::endl;

			if (key == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
			{
				leftButtonPressed = true;		
			}
			if (key == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
			{
				leftButtonPressed = false;
			}
		}
		);


		
		window->SetMouseMoveFunction([this](float64 xpos, float64 ypos)
			{
				this->MousePos(xpos, ypos);
				
				//std::cout << xpos << "  :  " << ypos << std::endl;
				if (leftButtonPressed && dx < xpos)
				{
					cubenode.GetTransform()->RotY(0.01f);
				}
				else if (leftButtonPressed && dx > xpos)
				{
					cubenode.GetTransform()->RotY(-0.01f);
				}
				else if (leftButtonPressed && dy < ypos)
				{
					cubenode.GetTransform()->RotX(0.01f);
				}
				if (leftButtonPressed && dy > ypos)
				{
					cubenode.GetTransform()->RotX(-0.01f);
				}
				dx = xpos;
				dy = ypos;
			}
			
		);
		



		if (this->window->Open())
		{
			glClearColor(0.1f, 0.1f, 0.4f, 1.0f);
			glEnable(GL_DEPTH_TEST);
			glDepthFunc(GL_LESS);

			Matrix4D m;
			Matrix4D rot;
			Matrix4D rot2;
			
			Vector4D startcam(0, 0.8f, 2, 1);
			const auto mesh = std::make_shared<MeshResource>();
			const auto tex = std::make_shared<Texture>("../texture1.png");
			const auto shad = std::make_shared<ShaderResource>("../shader.glsl");
			const auto tran = std::make_shared<Transform>(m, m, m);
			const auto cam = std::make_shared<Cam>(startcam, Vector4D(0, 0, 0, 1));
			cubenode = GraphicNode(mesh, tex, shad, tran, cam);
			ObjLoad("../../test.obj");

			return true;
		}
		
		return false;
	}

	//------------------------------------------------------------------------------
	/**
	*/

	void
	Lab5::Run()
	{
		while (this->window->IsOpen())
		{

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			cubenode.Draw();
			this->window->Update();
			this->window->SwapBuffers();
		}
	}
} // namespace Example
