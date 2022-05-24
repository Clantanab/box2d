#pragma once



#include <object.hpp>
#include <Box2D/Box2D.h>
#include <utils.hpp>


namespace practica1
{
	class Edge2D : public Object
	{
	protected:
		b2EdgeShape* shape;
		b2Body* body;
	public:
		bool active = true;

		Edge2D(b2World& physics_world, b2BodyType body_type, float x0, float y0, float x1, float y1);

		void Update() override {};
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override;
	};
}