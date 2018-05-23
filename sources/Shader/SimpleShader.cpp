#include "Shader/SimpleShader.h"

#include "Math/Matrix.h"

namespace Shader
{
	SimpleShader::SimpleShader() :
		Program("Simple_Vertex", "Simple_Fragment")
	{
		getUniformLocation();

		bind();

		loadMatrix4(_locationProjectionMatrix, Math::createProjectionMatrix());

		unbind();
	}

	void SimpleShader::setTime(float time)
	{
		loadFloat(_locationTime, time);
	}

	void SimpleShader::setViewMatrix(const Matrix4& matrix)
	{
		loadMatrix4(_locationViewMatrix, matrix);
	}

	void SimpleShader::setModelMatrix(const Matrix4& matrix)
	{
		loadMatrix4(_locationModelMatrix, matrix);
	}

	void SimpleShader::setProjectionMatrix(const Matrix4& matrix)
	{
		loadMatrix4(_locationProjectionMatrix, matrix);
	}


	void SimpleShader::getUniformLocation()
	{
		_locationTime				= glGetUniformLocation(getID(), "time");
		_locationProjectionMatrix	= glGetUniformLocation(getID(), "projection");
		_locationModelMatrix		= glGetUniformLocation(getID(), "model");
		_locationViewMatrix			= glGetUniformLocation(getID(), "view");
	}
}