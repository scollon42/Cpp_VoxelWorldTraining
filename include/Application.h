#ifndef __APPLICATION_H__
# define __APPLICATION_H__

# include <stack>
# include <memory>

# include "Display.h"
# include "State/Base.h"
# include "Renderer/Master.h"
# include "Entity.h"
# include "Camera.h"

class Application
{
public:
	Application();

	void gameLoop();

	void pushState(std::unique_ptr<State::Base>);
	void popState();

private:
	std::stack<std::unique_ptr<State::Base>> _states;

	Renderer::Master	_renderer;
	Camera				_camera;
};

#endif
