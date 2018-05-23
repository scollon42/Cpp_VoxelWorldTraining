#include "Display.h"
#include "Application.h"
#include "Utils/Random.h"
#include <iostream>

int	main()
{
	Random::init();
	Display::init();

	Application app;

	app.gameLoop();

	return (0);
}
