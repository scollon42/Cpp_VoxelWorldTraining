# include "State/Playing.h"
# include "Camera.h"
# include "Renderer/Master.h"

# include <iostream>
# include <SFML/System/Clock.hpp>
# include "Quad.h"


namespace State
{
	sf::Clock clock;

	Playing::Playing(Application& application) :
		Base(application),
		_texture("texture", 512, 16),
		_quad1(0, _texture),
		_quad2(1, _texture),
		_quad3(2, _texture),
		_quad4(3, _texture),
		_quad5(4, _texture),
		_quad6(5, _texture),
		_quad7(6, _texture)
	{
		_texture.bind();

		_quad1.position.z = -2.0f;
		_quad2.position.z = -2.0f;
		_quad3.position.z = -2.0f;
		_quad4.position.z = -2.0f;
		_quad5.position.z = -2.0f;
		_quad6.position.z = -2.0f;
		_quad7.position.z = -2.0f;

		_quad1.position.x = -1.0f;
		_quad2.position.x = 0.0f;
		_quad3.position.x = 1.0f;
		_quad4.position.x = 2.0f;
		_quad5.position.x = 3.0f;
		_quad6.position.x = 4.0f;
		_quad7.position.x = 5.0f;
	}

	void Playing::input(Camera& entity)
	{
	}

	void Playing::update(Camera& entity, float deltaTime)
	{
		//_quad.rotation += .1;
		entity.input(deltaTime);
	}

	void Playing::draw(Renderer::Master& renderer)
	{
			renderer.draw(_quad1);
			renderer.draw(_quad2);
			renderer.draw(_quad3);
			renderer.draw(_quad4);
			renderer.draw(_quad5);
			renderer.draw(_quad6);
			renderer.draw(_quad7);
	}
}
