# include "Texture/Atlas.h"
# include "iostream"
# include <iostream>

namespace Texture
{
	Atlas::Atlas(const std::string &name, const GLuint size, const GLuint textureSize):
		_size(size), _textureSize(textureSize)
	{
		load(name);
		std::cout << _size << " || || " << _textureSize << std::endl;
	}

	std::vector<GLfloat> Atlas::getTextureCoords(const Vector2& location)
	{
		static auto texturesPerRow = _size / _textureSize;
		static auto unitSize = 1.0f / (float)texturesPerRow;

		auto xMin = location.x * unitSize;
		auto yMin = location.y * unitSize;

		auto xMax = xMin + unitSize;
		auto yMax = yMin + unitSize;

		return
		{
			xMax, yMax,
			xMin, yMax,
			xMin, yMin,
			xMax, yMin
		};
	}
}