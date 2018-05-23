#ifndef __RENDERER_MASTER_H__
# define __RENDERER_MASTER_H__

# include "Renderer/SimpleRenderer.h"

class Quad;
class Camera;

namespace Renderer
{
	class Master
	{
	public:
		void clear();
		void update(const Camera& camera);

		void draw(const Quad& quad);

	private:
		SimpleRenderer		_simpleRenderer;
	};
}

#endif