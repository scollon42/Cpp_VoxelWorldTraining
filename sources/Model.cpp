#include "Model.h"
#include <iostream>

Model::Model(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLfloat>& textureCoordinates,
	const std::vector<GLuint>&  indices)
	: _indicesCount(indices.size())
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	addVBO(3, vertexPositions);
	addVBO(2, textureCoordinates);
	addEBO(indices);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Model::~Model()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(_buffers.size(), _buffers.data());
}

void Model::bind() const
{
	glBindVertexArray(_vao);
}

void Model::unbind() const
{
	glBindVertexArray(0);
}

void Model::addData(
	const std::vector<GLfloat>& vertex,
	const std::vector<GLfloat>& texture,
	const std::vector<GLuint>& indices
)
{

	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(_buffers.size(), _buffers.data());

	_indicesCount = indices.size();

	glGenVertexArrays(1, &_vao);
	bind();
	addVBO(3, vertex);
	addVBO(2, texture);
	addEBO(indices);
	unbind();
}

GLuint Model::getIndicesCount() const
{
	return _indicesCount;
}

void Model::addVBO(int vertexDimension, const std::vector<GLfloat>& data)
{
	GLuint VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
		GL_ARRAY_BUFFER,
		data.size() * sizeof(GLfloat),
		data.data(),
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(_vboCount, vertexDimension, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

	glEnableVertexAttribArray(_vboCount);

	_vboCount += 1;

	_buffers.push_back(VBO);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Model::addEBO(const std::vector<GLuint>& indices)
{
	GLuint	EBO;

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(indices[0]),
		indices.data(),
		GL_STATIC_DRAW
	);


}
