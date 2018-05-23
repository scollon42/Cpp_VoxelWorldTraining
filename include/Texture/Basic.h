#ifndef __TEXTURE_BASIC_H__
# define __TEXTURE_BASIC_H__

#include <GL/glew.h>
#include <string>

namespace Texture
{
	class Basic
	{
		const std::string BASE_PATH = "./data/Textures/";

		public:
			void load(const std::string& path);

			void bind();
			void unbind();

		private:
			GLuint _ID;
	};
}

#endif