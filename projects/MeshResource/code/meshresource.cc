#include "meshresource.h"
#include <utility>
#include <fstream>
#include <sstream>


MeshResource::MeshResource(Vertex verts[], std::vector<GLuint> indices)
{
    this->verts = verts;
    this->indices = std::move(indices);
}

MeshResource::~MeshResource()
{
	glDeleteBuffers(1,&ibo);
	glDeleteBuffers(1, &vbo);
	

}


MeshResource::MeshResource(): verts(nullptr)
{
	this->verts = verts;
	this->indices = indices;
}

void MeshResource::SetupIndexBuffer(unsigned int size)
{
    glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    const GLuint buffer_size = size *sizeof(GLuint);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,buffer_size, &indices[0], GL_STATIC_DRAW);
}

void MeshResource::SetupVertexBuffer(unsigned int size)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	const GLuint buffer_size = size * sizeof(Vertex);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, &verts[0].pos, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE, sizeof(Vertex), NULL);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,uvPos));

}
void MeshResource::SetupVertexArray()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindVertexArray(0);
}

void MeshResource::BindVao() const
{
    glBindVertexArray(vao);
}

void MeshResource::BindIbo() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}
void MeshResource::BindVbo() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
void MeshResource::UnBindVao()
{
	glBindVertexArray(0);
}

void MeshResource::UnBindIbo()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void MeshResource::UnBindVbo()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MeshResource::DrawCube(float size) 
{
	size /= 2;
	Vertex vertz[] = {

		


		// Left
		Vertex(Vector4D(-size, -size, -size),Vector4D(1.0f, 0.75f)),
		Vertex(Vector4D(-size, -size, size), Vector4D(0.75f, 0.75f)),
		Vertex(Vector4D(-size, size, size),  Vector4D(0.75f, 0.5f)),
		Vertex(Vector4D(-size, size, -size),  Vector4D(1.0f, 0.5f)),
		// Front
		Vertex(Vector4D(-size,-size,size), Vector4D(0.25f, 0.75f)),
		Vertex(Vector4D(size, -size, size),Vector4D(0.0f, 0.75f)),
		Vertex(Vector4D(size, size, size), Vector4D(0.0f, 0.5f)),
		Vertex(Vector4D(-size, size, size), Vector4D(0.25f, 0.5f)),



		// Back
		Vertex(Vector4D(size, -size, -size), Vector4D(0.75f, 0.75f)),
		Vertex(Vector4D(-size, -size, -size),Vector4D(0.5f, 0.75f)),
		Vertex(Vector4D(-size, size, -size), Vector4D(0.5f, 0.5f)),
		Vertex(Vector4D(size, size, -size),   Vector4D(0.75f, 0.5f)),



		// Right
		Vertex(Vector4D(size, -size, size),Vector4D(0.5f, 0.75f)),
		Vertex(Vector4D(size, -size, -size),Vector4D(0.25f, 0.75f)),
		Vertex(Vector4D(size, size, -size),Vector4D(0.25f, 0.5f)),
		Vertex(Vector4D(size, size, size),  Vector4D(0.5f, 0.5f)),

		// Top
		Vertex(Vector4D(-size, size, size), Vector4D(0.75f, 0.5f)),
		Vertex(Vector4D(size, size, size),  Vector4D(0.5f, 0.5f)),
		Vertex(Vector4D(size, size, -size), Vector4D(0.5f, 0.25f)),
		Vertex(Vector4D(-size, size, -size), Vector4D(0.75f, 0.25f)),

		// Bottom
		Vertex(Vector4D(size, -size, size),  Vector4D(0.75f, 1.0f)),
		Vertex(Vector4D(-size, -size, size), Vector4D(0.5f, 1.0f)),
		Vertex(Vector4D(-size, -size, -size),Vector4D(0.5f, 0.75f)),
		Vertex(Vector4D(size, -size, -size),  Vector4D(0.75f, 0.75f)),

		//// Left
		//Vertex(Vector4D(-size, -size, -size), Vector4D(0.75f, 0.25f)),
		//Vertex(Vector4D(-size, -size, size), Vector4D(1.0f, 0.25f)),
		//Vertex(Vector4D(-size, size, size), Vector4D(1.0f, 0.5f)),
		//Vertex(Vector4D(-size, size, -size), Vector4D(0.75f, 0.5f)),
		//// Front
		//Vertex(Vector4D(-size,-size,size), Vector4D(0, 0.25f)),
		//Vertex(Vector4D(size, -size, size), Vector4D(0.25f, 0.25f)),
		//Vertex(Vector4D(size, size, size), Vector4D(0.25f, 0.5f)),
		//Vertex(Vector4D(-size, size, size), Vector4D(0.0f, 0.5f)),



		//// Back
		//Vertex(Vector4D(size, -size, -size), Vector4D(0.5f, 0.25f)),
		//Vertex(Vector4D(-size, -size, -size), Vector4D(0.75f, 0.25f)),
		//Vertex(Vector4D(-size, size, -size), Vector4D(0.75f, 0.5f)),
		//Vertex(Vector4D(size, size, -size), Vector4D(0.5f, 0.5f)),



		//// Right
		//Vertex(Vector4D(size, -size, size), Vector4D(0.25f, 0.25f)),
		//Vertex(Vector4D(size, -size, -size), Vector4D(0.5f, 0.25f)),
		//Vertex(Vector4D(size, size, -size), Vector4D(0.5f, 0.5f)),
		//Vertex(Vector4D(size, size, size), Vector4D(0.25f, 0.5f)),

		//// Top
		//Vertex(Vector4D(-size, size, size), Vector4D(0.5f, 0.5f)),
		//Vertex(Vector4D(size, size, size), Vector4D(0.75f, 0.5f)),
		//Vertex(Vector4D(size, size, -size), Vector4D(0.75f, 0.75f)),
		//Vertex(Vector4D(-size, size, -size), Vector4D(0.5f, 0.75f)),

		//// Bottom
		//Vertex(Vector4D(size, -size, size), Vector4D(0.5f, 0.0f)),
		//Vertex(Vector4D(-size, -size, size), Vector4D(0.75f, 0.0f)),
		//Vertex(Vector4D(-size, -size, -size), Vector4D(0.75f, 0.25f)),
		//Vertex(Vector4D(size, -size, -size), Vector4D(0.5f, 0.25f)),
		
	};

	const std::vector<GLuint> indices = {
	0,1,3,		//triangle 1 //front
	2,3,1,		//triagnle 2

	4,5,7,		//triangle 1 //back		
	6,7,5,		//triagnle 2

	8,9,11,		//triangle 1 //right		
	10,11,9,		//triagnle 2

	12,13,15,		//triangle 1				
	14,15,13,		//triagnle 2

	16,17,19,	//triangle 1				
	18,19,17,		//triagnle 2

	20,21,23,		//triangle 1				
	22,23,21,	//triagnle 2



	};

	verts = vertz;
	this->indices = indices;
	SetupVertexBuffer(24);
	SetupIndexBuffer(36);
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	/*m.UnBindIbo();
	m.UnBindVbo();*/
}


void MeshResource::ObjLoad(const char* filepath) const
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
	while (getline(stream, line))
	{
		std::string tmp;
		std::stringstream ss(line);
		std::vector<std::string> tokens;
		while (getline(ss, tmp, ' '))
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
		else if (tokens[0] == "#")
			continue;

		//std::cout << tokens[0] << std::endl;

		switch (t)
		{
		case v:
		{
			Vector4D vert;
			for (size_t i = 1; i < 4; i++)
			{
				sscanf_s(tokens[i].c_str(), "%f", &vert[i - 1]);

			}

			t_verts.push_back(vert);
			break;
		}
		case vt:
		{
			Vector4D uv;
			for (size_t i = 1; i < 3; i++)
			{
				sscanf_s(tokens[i].c_str(), "%f", &uv[i - 1]);

			}


			t_uvs.push_back(uv);
			break;
		}
		case vn:
		{
			Vector4D norm;
			for (size_t i = 1; i < 4; i++)
			{
				sscanf_s(tokens[i].c_str(), "%f", &norm[i - 1]);

			}

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
					sscanf_s(tokens[i].c_str(), "%d/%d/%d ", &verts, &uvs, &norms);


					vertexIndices.push_back(verts);
					uvIndices.push_back(uvs);
					normIndices.push_back(norms);
				}


			}
			else if (tokens.size() == 5) //quad
			{
				std::vector<GLuint> tempverts, tempuvs, tempnorms;
				for (size_t i = 1; i < 5; i++)
				{
					sscanf_s(tokens[i].c_str(), "%d/d%/d%", &verts, &uvs, &norms);


					tempverts.push_back(verts);
					tempuvs.push_back(uvs);
					tempnorms.push_back(norms);
				}
				vertexIndices.push_back(tempverts[0]);
				vertexIndices.push_back(tempverts[1]);
				vertexIndices.push_back(tempverts[3]);
				vertexIndices.push_back(tempverts[2]);
				vertexIndices.push_back(tempverts[3]);
				vertexIndices.push_back(tempverts[1]);

				uvIndices.push_back(tempuvs[0]);
				uvIndices.push_back(tempuvs[1]);
				uvIndices.push_back(tempuvs[3]);
				uvIndices.push_back(tempuvs[2]);
				uvIndices.push_back(tempuvs[3]);
				uvIndices.push_back(tempuvs[1]);

				normIndices.push_back(tempnorms[0]);
				normIndices.push_back(tempnorms[1]);
				normIndices.push_back(tempnorms[3]);
				normIndices.push_back(tempnorms[2]);
				normIndices.push_back(tempnorms[3]);
				normIndices.push_back(tempnorms[1]);

			}


			break;
		}
		default:
			break;
		}

	}
	std::vector<Vertex> buf;
	for (size_t i = 0; i < vertexIndices.size(); i++)
	{
		unsigned int vertIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		unsigned int normIndex = normIndices[i];

		Vector4D vertex = t_verts[vertIndex - 1];
		Vector4D uv = t_uvs[uvIndex - 1];
		Vector4D norm = t_norms[normIndex - 1];
		

		buf.emplace_back(vertex, uv, norm);

	}
	glBufferData(GL_ARRAY_BUFFER, buf.size() * sizeof(Vertex), &buf[0].pos, GL_STATIC_DRAW);



	// FIXA SKITEN F�R ATT SKAPPA BUFFS N SHIT
}
