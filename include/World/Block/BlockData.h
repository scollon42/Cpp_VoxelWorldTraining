//
// Created by scollon on 5/22/18.
//

#ifndef MINECRAFT_BLOCKDATA_H
#define MINECRAFT_BLOCKDATA_H

# include <string>
# include "BlockID.h"
# include "GLMCommon.h"

namespace Block
{
    class Data
    {
        public:
            Data(const std::string& filename);

        private:
            ID          _ID;
            std::string _name;
            bool        _is_opaque;
            Vector2     _topTextureCoords;
            Vector2     _sideTextureCoords;
            Vector2     _bottomTextureCoords;
    };
}


#endif //MINECRAFT_BLOCKDATA_H
