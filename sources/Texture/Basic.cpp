#include "Texture/Basic.h"

#include <SFML/Graphics/Image.hpp>
#include <GL/glew.h>
#include <iostream>

namespace Texture
{
	void Basic::load(const std::string& fileName)
	{
		std::string file = BASE_PATH + fileName + ".png";

		std::cout << file << std::endl;
		sf::Image image;


		image.loadFromFile(file);

		std::cout << image.getSize().x << " || " << image.getSize().y << std::endl;

		glGenTextures(1, &_ID);
		bind();

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			image.getSize().x,
			image.getSize().y,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			image.getPixelsPtr()
		);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void Basic::bind()
	{
		glBindTexture(GL_TEXTURE_2D, _ID);
	}
	void Basic::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}