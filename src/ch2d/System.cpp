// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    System::System(void) :
        mRunning {false},

        // Default render window settings
        mWidth        {640},
        mHeight       {480},
        mBitsPerPixel {32},
        mVideoMode    {mWidth, mHeight, mBitsPerPixel},
        mTitle        {"Untitled"},
        mStyle        {sf::Style::Default},

        // Initialize event handler with reference to render window
        mEventHandler {mRenderWindow},

        // Initialize the Lua State
        mLuaState {true}
    {
        // Create the render window
        mRenderWindow.create(mVideoMode, mTitle, mStyle);

        // Set framerate limit
        mRenderWindow.setFramerateLimit(120);

        // Load the config file, and initialize the environment
        mLuaState.Load("lua/ch2d/ch2d.lua");
        mLuaState["ch2d"]["init"]();

        // System interface bindings
        mLuaState["ch2d"]["system"].SetObj(*this,
            "quit", &System::system_quit
        );

        // Window interface bindings
        mLuaState["ch2d"]["window"].SetObj(*this,
            "setView", &System::window_setView
        );

        // Sprite interface bindings
        mLuaState["ch2d"]["sprite"].SetObj(*this,
            "create",         &System::sprite_create,
            "draw",           &System::sprite_draw,
            "remove",         &System::sprite_remove,
            "setPosition",    &System::sprite_setPosition,
            "setOrigin",      &System::sprite_setOrigin,
            "setRotation",    &System::sprite_setRotation,
            "remove",         &System::sprite_remove,
            "setTexture",     &System::sprite_setTexture,
            "setTextureRect", &System::sprite_setTextureRect
        );

        // Texture interface bindings
        mLuaState["ch2d"]["texture"].SetObj(*this,
            "load",   &System::texture_load,
            "remove", &System::texture_remove
        );

        // Keyboard interface bindings
        mLuaState["ch2d"]["keyboard"].SetObj(*this,
            "isDown", &System::keyboard_isDown
        );

        // Mouse interface bindings
        mLuaState["ch2d"]["mouse"].SetObj(*this,
            "x",      &System::mouse_x,
            "y",      &System::mouse_y,
            "isDown", &System::mouse_isDown
        );

        // View interface bindings
        mLuaState["ch2d"]["view"].SetObj(*this,
            "create",    &System::view_create,
            "remove",    &System::view_remove,
            "setCenter", &System::view_setCenter
        );

        // Viewport interface bindings
        mLuaState["ch2d"]["viewport"].SetObj(*this,
            "create", &System::viewport_create,
            "remove", &System::viewport_remove
        );

        mLuaState.Load("game/game.lua");
    }

    void System::processArguments(int argc, char* argv[])
    {

    }

    int System::run(void)
    {
        mRunning = {true};
        mCurrentTime = std::chrono::high_resolution_clock::now();

        while(mRunning)
        {
            // Update times
            mNextTime = std::chrono::high_resolution_clock::now();
            mDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(mNextTime - mCurrentTime);
            mCurrentTime = mNextTime;

            // Clear render window
            mRenderWindow.clear();

            // Update event manager
            mEventHandler.update();

            // Call ch2d.update(dt) with delta time (in seconds)
            mLuaState["ch2d"]["update"]((LUA_NUMBER) mDeltaTime.count() * pow(10, -9));

            // Display screen
            mRenderWindow.display();
        }

        return 1;
    }

    bool System::isRunning(void) const
    {
        return mRunning;
    }

    void System::quit(void)
    {
        mRunning = false;
    }
}
