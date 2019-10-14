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

		std::vector<unsigned int> vertexIndices, uvIndices, normIndices;
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
				float vert;
				std::cout << tokens[0] << std::endl;

					for (size_t i = 2; i < 5; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &vert);
						std::cout << vert << " ";
					}
					std::cout << "\n";
					break;
				}
			case vt:
				{
					float uv;
					std::cout << tokens[0] << std::endl;
					for (size_t i = 1; i < 3; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &uv);
						std::cout << uv << " ";
					}
					std::cout << "\n";
					break;
				}
			case vn:
				{
					float norm;
					std::cout << tokens[0] << std::endl;

					for (size_t i = 1; i < 4; i++)
					{
						sscanf_s(tokens[i].c_str(), "%f", &norm);
						std::cout << norm << " ";
					}
					std::cout << "\n";
					break;
				}
			case f:
			{
				unsigned int verts, uvs, norms;
				std::cout << tokens[0] << std::endl;

				if (tokens.size() == 4) //triangle
				{
					for (size_t i = 1; i < 4; i++)
					{
						sscanf_s(tokens[i].c_str(), "%d/%d/%d", &verts, &uvs, &norms);
						std::cout << verts << "\\" << uvs << "\\" << norms << "\\ ";
					}
					std::cout << "\n";
				}
				else if (tokens.size() == 5)
				{
					for (size_t i = 1; i < 5; i++)
					{
						sscanf_s(tokens[i].c_str(), "%d/%d/%d", &verts, &uvs, &norms);
						std::cout << verts << "\\" << uvs << "\\" << norms << "\\ ";
					}
					std::cout << "\n";
				}
				
				
					break;
				}
			default:
				break;
			}
			
		}
		


		/*FILE * objfile = fopen(filepath,"r");
		if (objfile == NULL) {
			std::cout<<"FAILED TO LOAD OBJ FILE"<<std::endl;
			return false;
		}
		*/
		/*
		char head[128];
		while (true)
		{
			int reader = fscanf(objfile, "%s",head);
			if (reader==EOF) //if reaidng END OF FILE, break
				break;
			
			if (strcmp(header, "v") == 0){
				Vector4D vert;
				fscanf(objfile, "%f %f %f\n", &vert[0],&vert[1],&vert[2]); //3 floats and newline, insert into temp vertex
				t_verts.push_back(vert);
			}
			else if (strcmp(header, "vt") == 0){
				Vector4D uv;
				fscanf(objfile, "%f %f\n", &uv[0], &uv[1]);
				t_uvs.push_back(uv);
			}
			else if (strcmp(header, "vn") == 0){
				Vector4D norm;
				fscanf(objfile, "%f %f %f\n", &norm[0], &norm[1], &norm[2]);
				t_norms.push_back(norm);
			}
			else if (strcmp(header, "f") == 0){
				std::string vert1, vert2, vert3;
				unsigned int vertex[3], uv[3], norm[3];
				int match_nr = fscanf(objfile,
				"%d/%d/%d %d/%d/%d %d/%d/%d\n",
				&vertex[0], &uv[0], &norm[0],
				&vertex[1], &uv[1], &norm[1],
				&vertex[2], &uv[2], &norm[2]);

				if (match_nr != 9){
					//TRIANGULATE THAT SHIT LUDDE
					int count = fscanf_s(objfile,
					"%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n",)
					return false;
				}
				
				for (unsigned int i = 0; i < 3; i++)
				{
					vertexIndices.push_back(vertex[i]);
					uvIndices.push_back(uv[i]);
					normIndices.push_back(norm[i]);	
				}
			}
			
			for (unsigned int i = 0; i < vertexIndices.size(); i++)
			{
				unsigned int vertexIndex = vertexIndices[i];
				Vector4D vertex = t_verts[vertexIndex-1];
			}
			
		}
		*/
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
