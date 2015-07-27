#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
	bool LuaInterface::keyboard_isDown(unsigned int key)
	{
		return mEventHandler.keyboard_isDown(key);
	}
}
