# include "Display.h"

# include <SFML/Graphics.hpp>
# include <SFML/Window/Keyboard.hpp>
# include <SFML/Window/Mouse.hpp>
# include <GL/glew.h>
# include <memory>

namespace Display
{
	std::unique_ptr<sf::RenderWindow> window;

	void init()
	{
		sf::ContextSettings settings;

		settings.depthBits = 24;
		settings.majorVersion = 3;
		settings.minorVersion = 3;

		window = std::make_unique<sf::RenderWindow>(
			sf::VideoMode(WIDTH, HEIGHT),
			"window",
			sf::Style::Close,
			settings
		);

		glEnable(GL_DEPTH_TEST);

		glewInit();
		glViewport(0, 0, WIDTH, HEIGHT);

		window->setMouseCursorVisible(false);
	}

	void close()
	{
		window->close();
	}

	void clear()
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void update()
	{
		window->display();
	}

	void checkForClose()
	{
		sf::Event event;

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				close();
		}
	}

	bool isOpen()
	{
		return window->isOpen();
	}

	const sf::Window& getWindow()
	{
		return (*window);
	}
}
