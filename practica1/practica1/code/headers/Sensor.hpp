#pragma once


#include <vector>
#include <activers.hpp>
#include <object.hpp>
#include <Box2D/Box2D.h>

namespace practica1
{
 
	class Sensor : public Object
	{
	protected:
		std::vector<Activer*> activers;

		Object* target;
		b2Vec2 vec{ 0,0 };
		float minDistanceToActivate;

	public:
		b2Body* body;
		
		Sensor( b2Body* body, Object* target, float distanceToActivate, b2Vec2 vec);
		void Update() override;
		void Render(sf::RenderWindow& renderer, float window_height, float scale) override {};
		void AddActiver(Activer* activer);
	};

}