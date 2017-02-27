#include "dynplot/model.h"

Model::Model(const std::string& folderPath, const std::string& modelName) :
	m_pos(glm::vec3()),
	m_rot(glm::vec3()),
	m_scale(glm::vec3(1.0f, 1.0f, 1.0f))
{
	std::string objPath = folderPath + modelName + ".obj";
	std::vector<glm::vec3> t_vertices;
	std::vector<glm::vec2> t_uvs;
	std::vector<glm::vec3> t_normals;
	bool res = loadOBJ(objPath.c_str(), vertices, uvs, normals);
	indexVBO(vertices, uvs, normals, indices, t_vertices, t_uvs, t_normals);

	vertices = t_vertices;
	uvs = t_uvs;
	normals = t_normals;

	modelMesh = new Mesh(indices, vertices, uvs, normals);

	modelTex = new Texture(folderPath + modelName + ".png");
}

Model::Model() {}

Model::~Model ()
{
	delete modelTex;
	delete modelMesh;
}

glm::mat4 Model::GetModel() const
{
    glm::mat4 posMatrix = glm::translate(m_pos);
    glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1,0,0));
    glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0,1,0));
    glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0,0,1));
    glm::mat4 scaleMatrix = glm::scale(m_scale);

    glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
    return posMatrix * rotMatrix * scaleMatrix;
}

void Model::Draw()
{
	modelTex->Bind(0);
	modelMesh->Draw();
}