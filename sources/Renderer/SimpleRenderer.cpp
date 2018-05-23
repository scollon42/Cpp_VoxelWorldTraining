# include "Renderer/SimpleRenderer.h"
# include "Quad.h"

# include "Math/Matrix.h"
# include "Camera.h"

namespace Renderer
{
	void SimpleRenderer::draw(const Quad& Quad)
	{
		_quads.push_back(&Quad);
	}

	void SimpleRenderer::update(const Camera& camera)
	{
		_shader.bind();
		_shader.setTime(_clock.getElapsedTime().asSeconds());

		_shader.setViewMatrix(Math::createViewMatrix(camera));

		for (auto& quad : _quads)
		{
			prepare(*quad);
			glDrawElements(GL_TRIANGLES, quad->getModel().getIndicesCount(), GL_UNSIGNED_INT, nullptr);
		}

		_quads.clear();
	}

	void SimpleRenderer::prepare(const Quad& quad)
	{
		quad.getModel().bind();
		_shader.setModelMatrix(Math::createModelMatrix(quad));
	}
}