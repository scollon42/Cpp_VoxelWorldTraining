//
// Created by scollon on 5/22/18.
//

#ifndef MINECRAFT_BLOCKDATABASE_H
#define MINECRAFT_BLOCKDATABASE_H

#include "BlockTypes/BlockTypes.h"
#include "BlockID.h"

namespace Block
{
    namespace Database
    {
        void init();
        const Type& get(uint8_t id);
        const Type& get(ID blockID);
    }
}
#endif //MINECRAFT_BLOCKDATABASE_H
