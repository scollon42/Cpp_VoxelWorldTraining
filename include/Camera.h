#ifndef __CAMERA_H__
# define __CAMERA_H__

# include "Entity.h"

class Camera : public Entity
{
	public:
		void input(float deltaTime);
		void mouseInput();
};

#endif