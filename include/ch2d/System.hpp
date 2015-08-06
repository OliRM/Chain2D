#ifndef CH2D_SYSTEM_H
#define CH2D_SYSTEM_H

// Standard
#include <memory>
#include <chrono>
#include <cmath>

// ch2d
#include <ch2d/handlers/TextureHandler.hpp>
#include <ch2d/handlers/SpriteHandler.hpp>
#include <ch2d/handlers/EventHandler.hpp>
#include <ch2d/handlers/ViewHandler.hpp>

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
    class System
    {
    public:
        // Constructor
        System(void);

        // Functions
        void processArguments(int argc, char* argv[]);
        int  run(void);
        bool isRunning(void) const;
        void quit(void);

    private:
        // General variables
        bool mRunning;

        // General functions
        void cleanup(void);

        // Render window
        sf::RenderWindow mRenderWindow;

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

        // Asset handlers
        TextureHandler  mTextureHandler;
        SpriteHandler   mSpriteHandler;
        EventHandler    mEventHandler;
        ViewHandler     mViewHandler;

        // Lua State
        sel::State mLuaState;

        // System Lua bindings
        void system_quit(void);

        // Window Lua bindings
        void window_setView(unsigned int);

        // Sprite Lua bindings
        unsigned int sprite_create(void);
        bool         sprite_draw(unsigned int);
        bool         sprite_remove(unsigned int);
        bool         sprite_setPosition(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         sprite_setOrigin(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         sprite_setRotation(unsigned int, LUA_NUMBER);
        bool         sprite_setScale(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         sprite_setTexture(unsigned int, unsigned int);
        bool         sprite_setTextureRect(unsigned int, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);
        std::tuple<LUA_NUMBER, LUA_NUMBER> sprite_getPosition(unsigned int);
        std::tuple<LUA_NUMBER, LUA_NUMBER> sprite_getOrigin(unsigned int);
        LUA_NUMBER                         sprite_getRotation(unsigned int);
        std::tuple<LUA_NUMBER, LUA_NUMBER> sprite_getScale(unsigned int);

        // Texture Lua bindings
        bool         texture_remove(unsigned int);
        unsigned int texture_load(std::string);

        // Keyboard Lua bindings
        bool keyboard_isDown(unsigned int);

        // Mouse Lua bindings
        LUA_NUMBER mouse_x(void);
        LUA_NUMBER mouse_y(void);
        bool       mouse_isDown(unsigned int);

        // View Lua bindings
        unsigned int view_create(LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);
        bool         view_remove(unsigned int);
        bool         view_setCenter(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         view_setSize(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         view_setRotation(unsigned int, LUA_NUMBER);
        bool         view_setViewport(unsigned int, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);
        std::tuple<LUA_NUMBER, LUA_NUMBER>  view_getCenter(unsigned int);
        std::tuple<LUA_NUMBER, LUA_NUMBER>  view_getSize(unsigned int);
        LUA_NUMBER                          view_getRotation(unsigned int);
        std::tuple<LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER> view_getViewport(unsigned int);
    };
}

#endif
