

#include <Sensor.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

namespace practica1
{
	Sensor::Sensor(b2Body* body, Object* target, float distanceToActivate, b2Vec2 vec)
	{
		this->body = body;
		this->target = target;
		this->minDistanceToActivate = distanceToActivate;
		this->vec = vec;
	}

	void Sensor::AddActiver(Activer* activer)
	{
		activers.push_back(activer);
	}


	void Sensor::Update()
	{
		if (usado) return;
		
		b2Vec2 aux = target->body->GetPosition() - vec;
		

		if (aux.LengthSquared() < (minDistanceToActivate * minDistanceToActivate))
		{
			
			for (auto aciver : activers)
			{
				aciver->Activate();

			}
			usado = true;
		}


	}

}