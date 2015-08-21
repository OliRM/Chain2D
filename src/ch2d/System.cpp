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
        mFramerate    {120},
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
        mRenderWindow.setFramerateLimit(mFramerate);

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
            "setScale",       &System::sprite_setScale,
            "remove",         &System::sprite_remove,
            "setTexture",     &System::sprite_setTexture,
            "setTextureRect", &System::sprite_setTextureRect,
            "getPosition",    &System::sprite_getPosition,
            "getOrigin",      &System::sprite_getOrigin,
            "getRotation",    &System::sprite_getRotation,
            "getScale",       &System::sprite_getScale
        );

        // Shape interface bindings
        mLuaState["ch2d"]["shape"].SetObj(*this,
            "setTexture",          &System::shape_setTexture,
            "setTextureRect",      &System::shape_setTextureRect,
            "setFillColor",        &System::shape_setFillColor,
            "setOutlineColor",     &System::shape_setOutlineColor,
            "setOutlineThickness", &System::shape_setOutlineThickness,
            "setPosition",         &System::shape_setPosition,
            "setOrigin",           &System::shape_setOrigin,
            "setRotation",         &System::shape_setRotation,
            "setScale",            &System::shape_setScale,
            "getTextureRect",      &System::shape_getTextureRect,
            "getFillColor",        &System::shape_getFillColor,
            "getOutlineColor",     &System::shape_getOutlineColor,
            "getOutlineThickness", &System::shape_getOutlineThickness,
            "getPosition",         &System::shape_getPosition,
            "getOrigin",           &System::shape_getOrigin,
            "getRotation",         &System::shape_getRotation,
            "getScale",            &System::shape_getScale
        );

        // Texture interface bindings
        mLuaState["ch2d"]["texture"].SetObj(*this,
            "create",         &System::texture_create,
            "loadFromFile", &System::texture_loadFromFile,
            "setRepeated",  &System::texture_setRepeated,
            "setSmooth",    &System::texture_setSmooth,
            "isRepeated",   &System::texture_isRepeated,
            "isSmooth",     &System::texture_isSmooth,
            "remove",       &System::texture_remove
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
            "create",      &System::view_create,
            "remove",      &System::view_remove,
            "setCenter",   &System::view_setCenter,
            "setSize",     &System::view_setSize,
            "setRotation", &System::view_setRotation,
            "setViewport", &System::view_setViewport,
            "getCenter",   &System::view_getCenter,
            "getSize",     &System::view_getSize,
            "getRotation", &System::view_getRotation,
            "getViewport", &System::view_getViewport
        );
    }

    void System::processArguments(int argc, char* argv[])
    {
        if(argc != 2)
        {
            std::cout << "Usage: " << argv[0] << " <lua filename>" << std::endl;

            return;
        }

        if(!mLuaState.Load(argv[1]))
        {
            std::cout << "Unable to load file: \"" << argv[1] << "\"" << std::endl;

            return;
        }

        mRunning = {true};
    }

    int System::run(void)
    {
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
        mRunning = {false};
    }
}
