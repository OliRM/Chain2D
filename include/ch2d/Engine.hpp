#ifndef CH2D_ENGINE_H
#define CH2D_ENGINE_H

// Standard
#include <memory>
#include <chrono>

// ch2d
#include <ch2d/LuaInterface.hpp>

// SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Selene
#include "selene/selene.h"

// Lua
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

namespace ch2d
{
    class Engine
    {
    public:
        // Constructor
        Engine(void);

        // Functions
        void processArguments(int argc, char* argv[]);
        int  run(void);
        bool isRunning(void) const;
        void quit(void);

    private:
        // Render window
        sf::RenderWindow mRenderWindow;

        // Variables
        bool mRunning;

        // Lua Interface
        LuaInterface mLuaInterface;

        // Default render window settings
        unsigned int  mWidth;
        unsigned int  mHeight;
        unsigned int  mBitsPerPixel;
        sf::VideoMode mVideoMode;
        std::string   mTitle;
        uint32_t      mStyle;

        // Time storage
        std::chrono::high_resolution_clock::time_point mCurrentTime, mNextTime;
        std::chrono::nanoseconds mDeltaTime;

        // Functions
        void cleanup(void);
    };
}

#endif
