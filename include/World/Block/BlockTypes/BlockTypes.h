//
// Created by scollon on 5/22/18.
//

#ifndef MINECRAFT_BLOCKTYPES_H
#define MINECRAFT_BLOCKTYPES_H

# include <string>
# include <vector>
# include "World/Block/BlockData.h"

namespace Block
{
    class Type
    {
        public:
            Type(const std::string& name);

        private:
            Data _data;
    };

}


#endif //MINECRAFT_BLOCKTYPES_H
