#include "World/Block/BlockTextures/BlockTexture.h"

namespace Block
{
    BlockTexture::BlockTexture(const std::string& name, const GLuint size, const GLuint blockSize):
        _texture_atlas(name, size, blockSize)
    {
    }
}