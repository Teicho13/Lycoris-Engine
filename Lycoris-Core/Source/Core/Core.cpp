#include "Core.h"
#include "Graphics/Renderer.h"
#include <iostream>

namespace Core {

	void PrintHelloWorld()
	{
		std::cout << "Hello World!\n";
	}

	void PrintRenderer()
	{
		Lycoris::Renderer::Initialise();
		std::cin.get();
	}

}