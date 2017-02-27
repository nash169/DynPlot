#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <string>
#include <string.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "objloader.hpp"
#include "vboindexer.hpp"

#include "mesh.h"
#include "texture.h"

class Model
{
public:
	Model(const std::string& folderPath, const std::string& modelName);
	
	Model();

	virtual ~Model();

	inline glm::vec3& GetPos() { return m_pos; }
    inline glm::vec3& GetRot() { return m_rot; }
    inline glm::vec3& GetScale() { return m_scale; }

    inline void SetPos(const glm::vec3& pos) { m_pos = pos; }
    inline void SetRot(const glm::vec3& rot) { m_rot = rot; }
    inline void SetScale(const glm::vec3& scale) { m_scale = scale; }

    glm::mat4 GetModel() const;

    void Draw();

protected:	


private:
	// Model Mesh
	Mesh *modelMesh;
	std::vector<unsigned short> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	// Model Texture
	Texture *modelTex;

	// Model Position
	glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;

};

#endif // MODEL_H