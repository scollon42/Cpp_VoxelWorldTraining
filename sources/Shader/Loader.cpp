#include "Shader/Loader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace Shader
{
	GLuint		compile(const GLchar *src, GLenum type)
	{
		auto id = glCreateShader(type);

		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		GLint success;
		GLchar infoLog[512];

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, 512, nullptr, infoLog);
			std::runtime_error("Error compiling shader : " + std::string(infoLog));
		}
		return (id);
	}

	std::string source(const std::string& path)
	{
		auto pathTest = SHADER_PATH + path + ".glsl";

		std::cout << pathTest << std::endl;
		std::ifstream file(pathTest);
		std::stringstream stream;

		if (!file.is_open())
			throw std::runtime_error("Could not open file:" + path);

		stream << file.rdbuf();

		return (stream.str());
	}

	GLuint		program(GLuint vertexID, GLuint fragmentID)
	{
		auto id = glCreateProgram();

		glAttachShader(id, vertexID);
		glAttachShader(id, fragmentID);

		glLinkProgram(id);

		return (id);
	}

	GLuint		load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		auto vertexSrc = source(vertexFile);
		auto fragmentSrc = source(fragmentFile);

		auto vertex = compile(vertexSrc.c_str(), GL_VERTEX_SHADER);
		auto fragment = compile(fragmentSrc.c_str(), GL_FRAGMENT_SHADER);

		auto programID = program(vertex, fragment);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return (programID);
	}
}