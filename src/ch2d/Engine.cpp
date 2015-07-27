// ch2d
#include <ch2d/Engine.hpp>

namespace ch2d
{
	Engine::Engine(void) :
		mRunning {false},

		// Lua interface
		mLuaInterface{mRenderWindow},

		// Default render window settings
		mWidth {640},
		mHeight {480},
		mBitsPerPixel {32},
		mVideoMode {mWidth, mHeight, mBitsPerPixel},
		mTitle {"Untitled"},
		mStyle {sf::Style::Default}
	{
		// Create the render window
		mRenderWindow.create(mVideoMode, mTitle, mStyle);

		// Set framerate limit
		mRenderWindow.setFramerateLimit(120);
	}

	void Engine::processArguments(int argc, char* argv[])
	{

	}

	int Engine::run(void)
	{
		mRunning = {true};
		mCurrentTime = std::chrono::high_resolution_clock::now();

		while(mRunning)
		{
			if(!mLuaInterface.isRunning())
			{
				mRunning = {false};
			}

			// Update times
			mNextTime = std::chrono::high_resolution_clock::now();
			mDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(mNextTime - mCurrentTime);
			mCurrentTime = mNextTime;

			// Clear render window
			mRenderWindow.clear();

			// Call interface to update with delta time
			mLuaInterface.update((LUA_NUMBER)mDeltaTime.count());

			// Display screen
			mRenderWindow.display();
		}

		return 1;
	}

	bool Engine::isRunning(void) const
	{
		return mRunning;
	}

	void Engine::quit(void)
	{
		mRunning = false;
	}
}
