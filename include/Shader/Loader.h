#ifndef __SHADER_LOADER_H__
# define __SHADER_LOADER_H__

#include <GL/glew.h>
#include <string>

namespace Shader
{
	const std::string SHADER_PATH = "./data/Shaders/";

	GLuint load(const std::string& vertexFile, const std::string& fragmentFile);
}

#endif