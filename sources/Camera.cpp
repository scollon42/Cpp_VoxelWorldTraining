# include "Camera.h"
# include "Display.h"

# include <SFML/Window/Keyboard.hpp>
# include <SFML/Window/Mouse.hpp>
# include <cmath>

void Camera::input(float deltaTime)
{
	Vector3 change = { 0.0f, 0.0f, 0.0f };
	float speed = 2.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		change.x -= cos(glm::radians(rotation.y + 90)) * speed;
		change.z -= sin(glm::radians(rotation.y + 90)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		change.x += cos(glm::radians(rotation.y + 90)) * speed;
		change.z += sin(glm::radians(rotation.y + 90)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		change.x += -cos(glm::radians(rotation.y)) * speed;
		change.z += -sin(glm::radians(rotation.y)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		change.x += cos(glm::radians(rotation.y)) * speed;
		change.z += sin(glm::radians(rotation.y)) * speed;
	}

	position += change * deltaTime;
	
	mouseInput();
}

void Camera::mouseInput()
{
	static sf::Vector2i lastMousePosition = { 0, 0 };

	auto mouseChange = sf::Mouse::getPosition()  - lastMousePosition;

	rotation.y += mouseChange.x;
	rotation.x += mouseChange.y;

	if (rotation.x > 80)
		rotation.x = 80;
	else if (rotation.x < -80)
		rotation.x = -80;

	if (rotation.y < 0)
		rotation.y = 360;
	else if (rotation.y > 360)
		rotation.y = 0;

	auto centerX = Display::WIDTH / 2;
	auto centerY = Display::HEIGHT / 2;

	sf::Mouse::setPosition({ centerX, centerY }, Display::getWindow());

	lastMousePosition = sf::Mouse::getPosition();
}