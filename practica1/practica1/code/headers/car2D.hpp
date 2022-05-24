#pragma once

#include <object.hpp>
#include <circle2d.hpp>
#include <2dBox.hpp>

namespace practica1
{
	class Car2D : public Object
	{
	protected:
		Box2d* cuerpo;
		Circle2D* rueda1;
		Circle2D* rueda2;
		float speed;
		int dir;

	public:
		bool active = true;


		Car2D(float r1Radius, float r2Radius, float heightR1, float heightR2, float separationR1, float separationR2, float x, float y, float width, float height, float speed, b2World& world);

		void Update() override;
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override;

	};
}