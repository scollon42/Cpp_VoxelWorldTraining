#ifndef __RENDERER_SIMPLE_H__
# define __RENDERER_SIMPLE_H__

# include "Shader/SimpleShader.h"

# include <vector>
# include <SFML/System/Clock.hpp>

class Quad;
class Camera;

namespace Renderer
{
	class SimpleRenderer
	{
		public:
			void draw(const Quad& quad);
			void update(const Camera& camera);

		private:
			void prepare(const Quad& quad);

			std::vector<const Quad *>	_quads;
			Shader::SimpleShader		_shader;
			sf::Clock					_clock;
	};
}

#endif