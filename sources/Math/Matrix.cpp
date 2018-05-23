#include "Math/Matrix.h"
#include "Entity.h"
#include "Display.h"
#include "Camera.h"

#include "GLMCommon.h"

namespace Math
{
	Matrix4 createViewMatrix(const Camera & entity)
	{
		Matrix4 matrix;

		matrix = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};

		matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), { 1, 0, 0 });
		matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), { 0, 1, 0 });
		matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), { 0, 0, 1 });

		matrix = glm::translate(matrix, -entity.position);
		return (matrix);
	}

	Matrix4 createModelMatrix(const Entity & entity)
	{
		Matrix4 matrix;

		matrix = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};

		matrix = glm::translate(matrix, entity.position);

		matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), { 1, 0, 0 });
		matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), { 0, 1, 0 });
		matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), { 0, 0, 1 });

		return (matrix);
	}

	Matrix4 createProjectionMatrix()
	{
		return glm::perspective(glm::radians(90.0f), (float)Display::WIDTH / (float)Display::HEIGHT, 0.001f, 1000.0f);
	}
}
