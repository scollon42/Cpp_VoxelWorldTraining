#ifndef __STATE_BASE_H__
# define __STATE_BASE_H__

class Application;
class Camera;

namespace Renderer
{
	class Master;
}

namespace State
{
	class Base
	{
		public:
			Base(Application& application);

			virtual void input(Camera& entity) = 0;
			virtual void update(Camera& entity, float deltaTime) = 0;
			virtual void draw(Renderer::Master& renderer) = 0;

		protected:
			Application *_application;
	};
}

#endif
	