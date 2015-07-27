#ifndef CH2D_VIEWPORTHANDLER_H
#define CH2D_VIEWPORTHANDLER_H

// Standard
#include <memory>

// ch2d
#include <ch2d/general/Handler.hpp>

// SFML
#include <SFML/Graphics.hpp>

namespace ch2d
{
	class ViewportHandler : public Handler<sf::FloatRect>
	{
	public:
		unsigned int create(float, float, float, float);
	};
}

#endif
