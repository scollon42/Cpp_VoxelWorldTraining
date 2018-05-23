//
// Created by scollon on 5/22/18.
//

#ifndef MINECRAFT_BLOCKTEXTURE_H
#define MINECRAFT_BLOCKTEXTURE_H

#include "Texture/Atlas.h"
#include "GLMCommon.h"

#include <string>
#include <vector>

namespace Block
{
    class BlockTexture {
        public:
            BlockTexture(const std::string& name, const GLuint size, const GLuint blockSize);

            std::vector<GLfloat> getTextureCoords(const Vector2 textCoords);

        private:
            Texture::Atlas _texture_atlas;

    };
}

#endif //MINECRAFT_BLOCKTEXTURE_H
