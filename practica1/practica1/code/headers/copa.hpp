#pragma once


#include <activers.hpp>
#include <2dBox.hpp>

namespace practica1 
{
	class Copa : public Object, public Activer
	{



		Box2d* box;
		Box2d* box1;
		Box2d* sujetador;

		b2RevoluteJoint* joint1;
		b2RevoluteJoint* joint2;

	public:
		Copa(float posX, float posY, float altura, b2World& physics_world);


		void Update() override {};
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override;
		void Activate() override;
	};
}