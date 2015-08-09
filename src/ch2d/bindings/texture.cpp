// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::texture_create(void)
    {
        unsigned int id = mTextureHandler.create();

        return id;
    }

    bool System::texture_loadFromFile(unsigned int id, std::string filename)
    {
        auto texture = mTextureHandler.get(id);

        if(nullptr == texture)
        {
            return false;
        }

        if(!texture->loadFromFile(filename))
        {
            return false;
        }

        return true;
    }

    bool System::texture_setRepeated(unsigned int id, bool repeated)
    {
        auto texture = mTextureHandler.get(id);

        if(nullptr == texture)
        {
            return false;
        }

        texture->setRepeated(repeated);

        return true;
    }

    bool System::texture_setSmooth(unsigned int id, bool smooth)
    {
        auto texture = mTextureHandler.get(id);

        if(nullptr == texture)
        {
            return false;
        }

        texture->setSmooth(smooth);

        return true;
    }

    bool System::texture_isRepeated(unsigned int id)
    {
        auto texture = mTextureHandler.get(id);

        if(nullptr == texture)
        {
            return false;
        }

        return texture->isRepeated();
    }

    bool System::texture_isSmooth(unsigned int id)
    {
        auto texture = mTextureHandler.get(id);

        if(nullptr == texture)
        {
            return false;
        }

        return texture->isSmooth();
    }

    bool System::texture_remove(unsigned int id)
    {
        return mTextureHandler.remove(id);
    }
}
