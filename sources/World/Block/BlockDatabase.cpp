#include "World/Block/BlockDatabase.h"
#include "World/Block/BlockID.h"
#include "World/Block/BlockTypes/Air.h"
#include "World/Block/BlockTypes/Grass.h"

#include <vector>
#include <memory>

namespace Block
{
    namespace Database
    {
        std::vector<std::unique_ptr<Type>> blocks ((int)ID::NUM_BLOCK_TYPES);

        void init()
        {
            blocks[(int)ID::Air]    = std::make_unique<Air>();
            blocks[(int)ID::Grass]  = std::make_unique<Grass>();
        }

        const Type&     get(uint8_t id)
        {
            return *blocks[id];
        }

        const Type&     get(ID id)
        {
            return *blocks[(int)id];
        }

    }
}