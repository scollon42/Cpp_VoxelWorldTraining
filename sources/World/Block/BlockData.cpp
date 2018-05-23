#include "World/Block/BlockData.h"

#include <fstream>

namespace Block
{
    Data::Data(const std::string& name)
    {
        std::ifstream File;

        File.open("./data/Blocks/" + name + ".block");

        std::string line;

        while (std::getline(File, line))
        {
            if (line == "" || line[0] == '#') continue;
            else if (line == "Name")
                File >> _name;
            else if (line == "ID")
            {
                int tmpID;

                File >> tmpID;
                _ID = static_cast<ID>(tmpID);
            }
            else if (line == "Opaque")
                File >> _is_opaque;
            else if (line == "TextureTop")
                File >> _topTextureCoords.x >> _topTextureCoords.y;
            else if (line == "TextureSide")
                File >> _sideTextureCoords.x >> _sideTextureCoords.y;
            else if (line == "TextureBottom")
                File >> _bottomTextureCoords.x >> _bottomTextureCoords.y;
        }
    }
}