// Standard
#include <iostream>
#include <memory>

// ch2d
#include <ch2d/Engine.hpp>

int main(int argc, char* argv[])
{
	// Create engine
	std::shared_ptr<ch2d::Engine> app = std::make_shared<ch2d::Engine>();

	// Process command line arguments
	app->processArguments(argc, argv);

	// Start the engine
	app->run();

	// Clean up
	app.reset();

	return 0;
}
