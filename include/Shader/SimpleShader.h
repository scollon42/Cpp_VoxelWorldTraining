#ifndef __SHADER_SIMPLE_H__
# define __SHADER_SIMPLE_H__

# include "Shader/Program.h"
# include "GLMCommon.h"

namespace Shader
{
	class SimpleShader : public Program
	{
		public:
			SimpleShader();
			void setTime(float time);
			void setViewMatrix(const Matrix4& matrix);
			void setModelMatrix(const Matrix4& matrix);
			void setProjectionMatrix(const Matrix4& matrix);

		private:
			void getUniformLocation() override;

			GLuint _locationTime = 0;
			GLuint _locationViewMatrix = 0;
			GLuint _locationModelMatrix = 0;
			GLuint _locationProjectionMatrix = 0;
	};
}

#endif