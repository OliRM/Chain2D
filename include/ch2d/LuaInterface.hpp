#ifndef CH2D_INTERFACE_H
#define CH2D_INTERFACE_H

// Standard
#include <cmath>

// ch2d
#include <ch2d/handlers/TextureHandler.hpp>
#include <ch2d/handlers/SpriteHandler.hpp>
#include <ch2d/handlers/EventHandler.hpp>
#include <ch2d/handlers/ViewHandler.hpp>
#include <ch2d/handlers/ViewportHandler.hpp>

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
    class LuaInterface
    {
    public:
        // Constructor
        LuaInterface(sf::RenderWindow&);

        // General methods
        void update(LUA_NUMBER);
        bool isRunning(void) const;

        // System methods
        void system_quit(void);

        // Window methods
        void window_setView(unsigned int);

        // Sprite methods
        unsigned int sprite_create(void);
        bool         sprite_draw(unsigned int);
        bool         sprite_remove(unsigned int);
        bool         sprite_setPosition(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         sprite_setOrigin(unsigned int, LUA_NUMBER, LUA_NUMBER);
        bool         sprite_setRotation(unsigned int, LUA_NUMBER);
        void         sprite_setTexture(unsigned int, unsigned int);
        void         sprite_setTextureRect(unsigned int, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);

        // Texture methods
        bool         texture_remove(unsigned int);
        unsigned int texture_load(std::string);

        // Keyboard methods
        bool keyboard_isDown(unsigned int);

        // Mouse methods
        LUA_NUMBER mouse_x(void);
        LUA_NUMBER mouse_y(void);
        bool       mouse_isDown(unsigned int);

        // View methods
        unsigned int view_create(LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);
        bool         view_remove(unsigned int);
        void         view_setCenter(unsigned int, LUA_NUMBER, LUA_NUMBER);

        // Viewport Methods
        unsigned int viewport_create(LUA_NUMBER, LUA_NUMBER, LUA_NUMBER, LUA_NUMBER);
        bool         viewport_remove(unsigned int);

    private:
        // Lua State
        sel::State mLuaState;

        // Render window
        sf::RenderWindow& mRenderWindow;

        // Asset handlers
        TextureHandler mTextureHandler;
        SpriteHandler  mSpriteHandler;

        // Event Handler
        EventHandler mEventHandler;

        // View Handler
        ViewHandler mViewHandler;

        // Viewport Handler
        ViewportHandler mViewportHandler;

        // Variables
        bool mRunning;
    };
}

#endif
