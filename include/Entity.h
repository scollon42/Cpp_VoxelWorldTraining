#ifndef __ENTITY_H__
# define __ENTITY_H__

# include "GLMCommon.h"

struct Entity
{
	Vector3 position = { 0.0f, 0.0f, 0.0f };
	Vector3 rotation = { 0.0f, 0.0f, 0.0f };
};

#endif 