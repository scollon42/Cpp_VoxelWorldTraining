#ifndef DISPLAY_H
# define DISPLAY_H

namespace sf
{
	class Window;
}

namespace Display
{

	constexpr static int WIDTH = 1280;
	constexpr static int HEIGHT = 720;

	void init();
	void close();
	void clear();
	void update();

	void checkForClose();
	bool isOpen();

	const sf::Window& getWindow();
}

#endif