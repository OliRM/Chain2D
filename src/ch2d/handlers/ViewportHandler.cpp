// ch2d
#include <ch2d/handlers/ViewportHandler.hpp>

namespace ch2d
{
	unsigned int ViewportHandler::create(float x, float y, float width, float height)
	{
		unsigned int id = 0;

		std::shared_ptr<sf::FloatRect> viewport = std::make_shared<sf::FloatRect>(x, y, width, height);

		id = mPointerStorage.add(viewport);

		return id;
	}
}
