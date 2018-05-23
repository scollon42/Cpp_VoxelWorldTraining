#include "Shader/Program.h"
#include "Shader/Loader.h"

namespace Shader
{
	Program::Program(const std::string& vertexFile, const std::string& fragmentFile):
		_ID(load(vertexFile, fragmentFile))
	{
	}

	Program::~Program()
	{
		glDeleteProgram(_ID);
	}

	void	Program::bind()
	{
		glUseProgram(_ID);
	}

	void	Program::unbind()
	{
		glUseProgram(0);
	}

	GLuint	Program::getID() const
	{
		return (_ID);
	}

	void	Program::loadFloat(GLuint location, float value)
	{
		glUniform1f(location, value);
	}

	void Program::loadVector2(GLuint location, const Vector2 & vector)
	{
		glUniform2f(location, vector.x, vector.y);
	}

	void Program::loadMatrix4(GLuint location, const Matrix4 & matrix)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}