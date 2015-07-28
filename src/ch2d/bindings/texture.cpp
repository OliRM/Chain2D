// ch2d
#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
    unsigned int LuaInterface::texture_load(std::string filename)
    {
        unsigned int id = mTextureHandler.load(filename);

        return id;
    }

    bool LuaInterface::texture_remove(unsigned int id)
    {
        return mTextureHandler.remove(id);
    }
}
