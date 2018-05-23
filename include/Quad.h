#ifndef __QUAD_H__
# define __QUAD_H__

# include "Entity.h"
# include "Model.h"

namespace Texture
{
	class Atlas;
}

class Quad : public Entity
{


	public:

		static constexpr	GLuint DIRTGRASS	= 0;
		static constexpr	GLuint STONE		= 1;
		static constexpr	GLuint DIRT			= 2;
		static constexpr	GLuint WALL			= 3;
		static constexpr	GLuint WOOD			= 4;
		static constexpr	GLuint SAND			= 5;
		static constexpr	GLuint BRICK		= 6;

		Quad(const GLuint& type, Texture::Atlas& texture);

		const Model& getModel() const;

	private:
		Model _model;
		GLuint _type;
};

#endif 