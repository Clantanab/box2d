#pragma once



#include <object.hpp>
#include <Box2D/Box2D.h>
#include <utils.hpp>

namespace practica1
{
	class Circle2D : public Object
	{
	private:

		b2CircleShape* shape;
	public:

		bool active = true;
		void Update() override {};
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override;

		Circle2D(b2World& world, b2BodyType bodytype, float x, float y, float radius);
	};
}