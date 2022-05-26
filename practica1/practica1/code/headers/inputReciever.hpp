#pragma once

#include <SFML/Window.hpp>

namespace practica1
{
	class InputReciever
	{
	public:

		virtual void RecieveInput(sf::Event event) {};
	};
}
