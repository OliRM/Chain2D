#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
	unsigned int LuaInterface::viewport_create(LUA_NUMBER x, LUA_NUMBER y, LUA_NUMBER width, LUA_NUMBER height)
	{
		return mViewportHandler.create(x, y, width, height);
	}

	bool LuaInterface::viewport_remove(unsigned int id)
	{
		return mViewportHandler.remove(id);
	}
}
