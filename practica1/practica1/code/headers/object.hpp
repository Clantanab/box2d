#pragma once


#include <SFML/Graphics.hpp>



namespace practica1
{
	class Object
	{



	public:
		

		virtual void Render(sf::RenderWindow& renderer, float window_height, float scale) {};
		virtual void Update() {};


	};


}
