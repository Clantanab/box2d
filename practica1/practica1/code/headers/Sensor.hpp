#pragma once


#include <vector>
#include <activers.hpp>
#include <object.hpp>
#include <Box2D/Box2D.h>

namespace practica1
{
 
	class Sensor : Object
	{
	protected:
		std::vector<Activer*> activers;

		Object* target;

		float minDistanceToActivate;

	public:
		b2Body* body;
		
		Sensor(b2Body* body, Object* target, float distanceToActivate );
		void Update() override;
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override {};
		void AddActiver(Activer* activer);
	};

}