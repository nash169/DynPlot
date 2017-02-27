#ifndef MESH_H
#define MESH_H

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Mesh
{
public:
	Mesh(std::vector<unsigned short>& indices, 
		   std::vector<glm::vec3>& vertices, 
		   std::vector<glm::vec2>& uvs, 
		   std::vector<glm::vec3>& normals);

	Mesh();

	virtual ~Mesh();

	virtual void Draw();

	virtual void Update();

protected:
	enum
	{
		VERTEX,

		UV,

		NORMAL,

		INDEX,

		NUM_BUFFERS		
	};

	GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];

    int m_drawCount;

private:

};

#endif // MESH_H