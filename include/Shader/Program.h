#ifndef __SHADER_PROGRAM_H__
# define __SHADER_PROGRAM_H__

# include <GL/glew.h>
# include <string>

# include "GLMCommon.h"

namespace Shader
{
	class Program
	{
		public:
			Program(const std::string& vertexFile, const std::string& fragmentFile);
			~Program();

			void bind();
			void unbind();

		protected:
			virtual void	getUniformLocation() = 0;

			GLuint			getID() const;
			void			loadFloat(GLuint location, const float value);
			void			loadVector2(GLuint location, const Vector2& vector);
			void			loadMatrix4(GLuint location, const Matrix4& matrix);

		private:
			GLuint _ID;
	};
}

#endif