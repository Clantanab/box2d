

#include <car2D.hpp>

#include <iostream>
namespace practica1
{
	Car2D::Car2D(float r1Radius, float r2Radius, float heightR1, float heightR2, float separationR1, float separationR2, float x, float y, float width, float height, float speed, b2World& world)
	{
		//creacion de las otras partes del coche 
		this->cuerpo = new Box2d(world, b2_dynamicBody, x, y, width, height);

		this->dir = 0;

		this->rueda1 = new Circle2D(world, b2_dynamicBody, x + (width ) + separationR1, y + heightR1, r1Radius);
		this->rueda2 = new Circle2D(world, b2_dynamicBody, x - separationR2 - (width), y + heightR2, r2Radius);

		this->speed = speed;
		

		//creacion de las joint
		b2DistanceJointDef* joint1 = new b2DistanceJointDef();
		joint1->Initialize(cuerpo->body, rueda1->body, cuerpo->body->GetPosition(), rueda1->body->GetPosition());
		joint1->bodyA = cuerpo->body;
		joint1->bodyB = rueda1->body;
		joint1->length = separationR1;
		joint1->stiffness = 7.0f;

		joint1->damping = 80.f;
		joint1->collideConnected = true;

	    world.CreateJoint(joint1);

		b2DistanceJointDef* joint2 = new b2DistanceJointDef();
		joint2->Initialize(cuerpo->body, rueda2->body, cuerpo->body->GetPosition(), rueda2->body->GetPosition());
		joint2->bodyA = cuerpo->body;
		joint2->bodyB = rueda2->body;
		joint2->length = separationR2;
		joint2->stiffness = 7.0f;
		joint2->damping = 80.f;
		joint2->collideConnected = true;
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
		if (rueda1->body-> GetAngularVelocity() < +10.f) rueda1->body->ApplyTorque(5.0f * 2.f, true);

	}
}