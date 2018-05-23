#ifndef __MATH_MATRIX_H__
# define __MATH_MATRIX_H__

# include "GLMCommon.h"

class Camera;
struct Entity;

namespace Math
{
	Matrix4		createViewMatrix(const Camera& camera);
	Matrix4		createModelMatrix(const Entity& entity);
	Matrix4		createProjectionMatrix();
}

#endif