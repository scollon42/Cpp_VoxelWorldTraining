#include "Application.h"
#include "State/Playing.h"
#include "Camera.h"
#include <memory>

Application::Application()
{
	pushState(std::make_unique<State::Playing>(*this));
	_camera.position.y = 2;
	_camera.rotation.x = -1;
}

void Application::gameLoop()
{
	sf::Clock clock;

	while (Display::isOpen())
	{
		auto deltaTime = clock.restart().asSeconds();

		_renderer.clear();

		_states.top()->input(_camera);
		_states.top()->update(_camera, deltaTime);
		_states.top()->draw(_renderer);

		_renderer.update(_camera);
		Display::checkForClose();
	}
}

void Application::pushState(std::unique_ptr<State::Base> state)
{
	_states.push(std::move(state));
}

void Application::popState()
{
	_states.pop();
}
