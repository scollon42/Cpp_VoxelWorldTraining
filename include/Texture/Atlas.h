#ifndef __TEXTURE_ATLAS_H__
# define __TEXTURE_ATLAS_H__

# include "Texture/Basic.h"
# include "GLMCommon.h"

# include <string>
# include <vector>

namespace Texture
{
	class Atlas : public Basic
	{
		public:
			Atlas(const std::string &name, const GLuint size, const GLuint textureSize);

			std::vector<GLfloat> getTextureCoords(const Vector2& location);

		private:
			GLuint _size;
			GLuint _textureSize;

	};
}

#endif