

#include <Sensor.hpp>
#include <Box2D/Box2D.h>

namespace practica1
{
	Sensor::Sensor(b2Body* body, Object* target, float distanceToActivate)
	{
		this->body = body;
		this->target = target;
		this->minDistanceToActivate = distanceToActivate;
	}

	void Sensor::AddActiver(Activer* activer)
	{
		activers.push_back(activer);
	}


	void Sensor::Update()
	{
		b2Vec2 vec = target->body->GetPosition() - this->body->GetPosition();

		if (vec.LengthSquared() < (minDistanceToActivate * minDistanceToActivate))
		{
			for (auto aciver : activers)
			{
				aciver->Activate();
			}
		}


	}

}