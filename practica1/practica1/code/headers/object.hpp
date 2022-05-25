#pragma once


#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


namespace practica1
{
	class Object
	{



	public:



		b2Body* body;

		virtual void Render(sf::RenderWindow& renderer, float window_height, float scale) {};
		virtual void Update() {};


	};


}
