#ifndef __STATE_PLAYING_H__
# define __STATE_PLAYING_H__

# include "Base.h"
# include "Model.h"
# include "Shader/SimpleShader.h"
# include "Texture/Atlas.h"
# include "Quad.h"

# include <vector>

class Application;
class Camera;

namespace State
{
	class Playing : public Base
	{
		public:
			Playing(Application& application);

			void    input(Camera& entity) override;
			void    update(Camera& entity, float deltaTime) override;
			void    draw(Renderer::Master& renderer) override;
		private:
			Texture::Atlas			_texture;
			Shader::SimpleShader	_shader;
			Quad					_quad1;
			Quad					_quad2;
			Quad					_quad3;
			Quad					_quad4;
			Quad					_quad5;
			Quad					_quad6;
			Quad					_quad7;
	};
}

#endif
