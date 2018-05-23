# include "Renderer/Master.h"
# include "Display.h"
# include "Camera.h"

namespace Renderer
{
	void Master::clear()
	{
		Display::clear();
	}

	void Master::update(const Camera& camera)
	{
		_simpleRenderer.update(camera);
		Display::update();
	}

	void Master::draw(const Quad& quad)
	{
		_simpleRenderer.draw(quad);
	}

}