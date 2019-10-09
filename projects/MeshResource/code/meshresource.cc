#include "meshresource.h"
#include <utility>


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

    GLuint buffer_size = size * sizeof(Vertex);
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
