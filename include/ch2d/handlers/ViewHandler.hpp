#ifndef CH2D_VIEWHANDLER_H
#define CH2D_VIEWHANDLER_H

// Standard
#include <memory>

// ch2d
#include <ch2d/general/Handler.hpp>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace ch2d
{
	class ViewHandler : public Handler<sf::View>
	{
	public:
		unsigned int create(float, float, float, float);
	};
}

#endif