#pragma once


#include <object.hpp>
#include <Box2D/Box2D.h>
#include <utils.hpp>

namespace practica1
{



	class Box2d : public Object
	{
	protected:
		b2PolygonShape* shape;



	public:
		b2Body* body;
		bool active = true;;

		Box2d(b2World& world, b2BodyType bodytype, float x, float y, float width, float height);

		void Update() override {};
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override;

		

	};
}