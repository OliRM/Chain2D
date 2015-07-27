// ch2d
#include <ch2d/handlers/ViewHandler.hpp>

namespace ch2d
{
	unsigned int ViewHandler::create(float x, float y, float width, float height)
	{
		unsigned int id = 0;

		std::shared_ptr<sf::View> view = std::make_shared<sf::View>(sf::FloatRect(x, y, width, height));

		id = mPointerStorage.add(view);

		return id;
	}
}
