

#include <car2D.hpp>


namespace practica1
{
	Car2D::Car2D(float r1Radius, float r2Radius, float heightR1, float heightR2, float separationR1, float separationR2, float x, float y, float width, float height, float speed, b2World& world)
	{
		//creacion de las otras partes del coche 
		this->cuerpo = new Box2d(world, b2_dynamicBody, x, y, width, height);

		this->dir = 0;
		this->rueda1 = new Circle2D(world, b2_dynamicBody, heightR1, separationR1, r1Radius);
		this->rueda2 = new Circle2D(world, b2_dynamicBody, heightR2, separationR2, r2Radius);

		this->speed = speed;


		//creacion de las joint
		b2DistanceJointDef* joint1 = new b2DistanceJointDef();

		joint1->bodyA = rueda1->body;
		joint1->bodyB = cuerpo->body;
		joint1->length = separationR1;
		joint1->stiffness = 3.0f;
		joint1->damping = 0.1f;
		world.CreateJoint(joint1);

		b2DistanceJointDef* joint2 = new b2DistanceJointDef();

		joint1->bodyA = cuerpo->body;
		joint1->bodyB = rueda2->body;
		joint1->length = separationR2;
		joint1->stiffness = 3.0f;
		joint1->damping = 0.1f;
		world.CreateJoint(joint2);

	}


	void Car2D::Render(sf::RenderWindow& renderer, float window_height, float scale)
	{
		this->cuerpo->Render(renderer, window_height, scale);
		this->rueda1->Render(renderer, window_height, scale);
		this->rueda2->Render(renderer, window_height, scale);
	}

	void Car2D::Update()
	{
		if (rueda1->body-> GetAngularVelocity() < +10.f) rueda1->body->ApplyTorque(5.0f * dir, true);

	}
}