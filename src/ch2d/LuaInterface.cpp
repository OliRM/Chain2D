#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
	LuaInterface::LuaInterface(sf::RenderWindow& renderWindow) :
		mLuaState {true},
		mRenderWindow {renderWindow},
		mEventHandler {renderWindow},
		mRunning {true}
	{
		// Load the config file
		mLuaState.Load("lua/ch2d/ch2d.lua");

		// System interface bindings
		mLuaState["ch2d"]["system"].SetObj(*this,
			"quit", &LuaInterface::system_quit
		);

		// Window interface bindings
		mLuaState["ch2d"]["window"].SetObj(*this,
			"setView", &LuaInterface::window_setView
		);

		// Sprite interface bindings
		mLuaState["ch2d"]["sprite"].SetObj(*this,
			"create", 		   	&LuaInterface::sprite_create,
			"draw",			   	&LuaInterface::sprite_draw,
			"remove",		   	&LuaInterface::sprite_remove,
			"setPosition",	  	&LuaInterface::sprite_setPosition,
			"setOrigin",		&LuaInterface::sprite_setOrigin,
			"setRotation",		&LuaInterface::sprite_setRotation,
			"remove", 		  	&LuaInterface::sprite_remove,
			"setTexture",	   	&LuaInterface::sprite_setTexture,
			"setTextureRect",   &LuaInterface::sprite_setTextureRect
		);

		// Texture interface bindings
		mLuaState["ch2d"]["texture"].SetObj(*this,
			"load",   &LuaInterface::texture_load,
			"remove", &LuaInterface::texture_remove
		);

		// Keyboard interface bindings
		mLuaState["ch2d"]["keyboard"].SetObj(*this,
			"isDown", &LuaInterface::keyboard_isDown
		);

		// Mouse interface bindings
		mLuaState["ch2d"]["mouse"].SetObj(*this,
			"x", &LuaInterface::mouse_x,
			"y", &LuaInterface::mouse_y,
			"isDown", &LuaInterface::mouse_isDown
		);

		// View interface bindings
		mLuaState["ch2d"]["view"].SetObj(*this,
			"create",    &LuaInterface::view_create,
			"remove",    &LuaInterface::view_remove,
			"setCenter", &LuaInterface::view_setCenter
		);

		// Viewport interface bindings
		mLuaState["ch2d"]["viewport"].SetObj(*this,
			"create", &LuaInterface::viewport_create,
			"remove", &LuaInterface::viewport_remove
		);

		mLuaState.Load("game/game.lua");
	}

	void LuaInterface::update(LUA_NUMBER dt)
	{
		mEventHandler.update();

		mLuaState["ch2d"]["update"](dt * pow(10, -9));
	}

	bool LuaInterface::isRunning(void) const
	{
		return mRunning;
	}
}
