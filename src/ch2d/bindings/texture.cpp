// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::texture_load(std::string filename)
    {
        unsigned int id = mTextureHandler.load(filename);

        return id;
    }

    bool System::texture_remove(unsigned int id)
    {
        return mTextureHandler.remove(id);
    }
}
