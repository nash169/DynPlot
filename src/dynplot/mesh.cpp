#include "dynplot/mesh.hpp"
#include <iostream>

Mesh::Mesh(std::vector<unsigned short>& indices,
    std::vector<glm::vec3>& vertices,
    std::vector<glm::vec2>& uvs,
    std::vector<glm::vec3>& normals)
{
    m_drawCount = indices.size();

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

    // Vertex
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[VERTEX]);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // UV
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[UV]);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    //NORMAL
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL]);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    //INDEX
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}

Mesh::Mesh() {}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
    glBindVertexArray(m_vertexArrayObject);

    // Update();

    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_SHORT, (void*)0);

    // glDisableVertexAttribArray(0);
    // glDisableVertexAttribArray(1);
    // glDisableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Mesh::Update()
{
    // Vertex
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[VERTEX]);
    // glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // UV
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[UV]);
    // glBufferData(GL_ARRAY_BUFFER, uvs.size()*sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    //NORMAL
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL]);
    // glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    //INDEX
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX]);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned short), &indices[0] , GL_STATIC_DRAW);
}