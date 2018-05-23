#ifndef __MODEL_H__
# define __MODEL_H__

#include <GL/glew.h>
#include <vector>

class Model
{
	public: 
		Model() = default;

		Model(
			const std::vector<GLfloat>& vertex,
			const std::vector<GLfloat>& texture,
			const std::vector<GLuint>& indices
		);
		~Model();

		void bind() const;
		void unbind() const;

		void addData(
			const std::vector<GLfloat>& vertex,
			const std::vector<GLfloat>& texture,
			const std::vector<GLuint>& indices
		);

		GLuint getIndicesCount() const;

	private:
		void addVBO(int dim, const std::vector<GLfloat>& data);
		void addEBO(const std::vector<GLuint>& indices);


		std::vector<GLuint> _buffers;

		GLuint				_vao = 0;

		GLuint				_vboCount = 0;
		GLuint				_indicesCount = 0;
};

#endif