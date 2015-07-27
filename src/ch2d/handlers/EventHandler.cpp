// ch2d
#include <ch2d/handlers/EventHandler.hpp>

namespace ch2d
{
	EventHandler::EventHandler(sf::RenderWindow& renderWindow) :
		mRenderWindow {renderWindow},
		mKeys {0},
		mMouse {0}
	{

	}

	void EventHandler::update(void)
	{
		sf::Event event;

		sf::Vector2i pixelPos;
		sf::Vector2f worldPos;

		while(mRenderWindow.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::EventType::MouseMoved:
					pixelPos.x = event.mouseMove.x;
					pixelPos.y = event.mouseMove.y;
					worldPos = mRenderWindow.mapPixelToCoords(pixelPos);
					mMouse.x = worldPos.x;
					mMouse.y = worldPos.y;
					break;
				case sf::Event::EventType::MouseButtonPressed:
					mMouse.buttons[event.mouseButton.button] = true;
					break;
				case sf::Event::EventType::MouseButtonReleased:
					mMouse.buttons[event.mouseButton.button] = false;
					break;
				case sf::Event::EventType::KeyPressed:
					mKeys[event.key.code] = true;
					break;
				case sf::Event::EventType::KeyReleased:
					mKeys[event.key.code] = false;
					break;
				default:
					break;
			}
		}
	}

	bool EventHandler::keyboard_isDown(unsigned int key)
	{
		return mKeys[key];
	}

	LUA_NUMBER EventHandler::mouse_x(void)
	{
		return mMouse.x;
	}

	LUA_NUMBER EventHandler::mouse_y(void)
	{
		return mMouse.y;
	}

	bool EventHandler::mouse_isDown(unsigned int button)
	{
		return mMouse.buttons[button];
	}
}
