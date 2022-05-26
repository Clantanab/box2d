

#include <car2D.hpp>

#include <iostream>
namespace practica1
{
	Car2D::Car2D(float r1Radius, float r2Radius, float heightR1, float heightR2, float separationR1, float separationR2, float x, float y, float width, float height, float speed, b2World& world)
	{
		//creacion de las otras partes del coche 
		this->cuerpo = new Box2d(world, b2_dynamicBody, x, y, width, height);
		body = cuerpo->body;
		this->dir = 0;

		this->rueda1 = new Circle2D(world, b2_dynamicBody, x + (width ) + separationR1, y + heightR1, r1Radius);
		this->rueda2 = new Circle2D(world, b2_dynamicBody, x - separationR2 - (width), y + heightR2, r2Radius);

		this->speed = speed;
		

		//creacion de las joint
		b2Vec2 axis(0.f, 1.0f);
		b2WheelJointDef* joint1 = new b2WheelJointDef();
		joint1->Initialize(cuerpo->body, rueda1->body,  rueda1->body->GetPosition(), axis);

		//EL MOTOR ESTA APAGADO AL EMPEZAAR
		joint1->enableMotor = true;
		joint1->maxMotorTorque = 100.f;
		joint1->motorSpeed = 0.0f;
		joint1->lowerTranslation = heightR1;
		joint1->stiffness = 7.0f;
		joint1->enableLimit = false;

		joint1->damping = 80.0f;
		joint1->collideConnected = true;
		

		joint = dynamic_cast<b2WheelJoint*>  (world.CreateJoint(joint1));


		b2WheelJointDef* joint2 = new b2WheelJointDef();
		joint2->Initialize(cuerpo->body, rueda2->body,  rueda2->body->GetPosition(), axis);

		joint2->enableMotor = false;
		joint2->motorSpeed = 0.0f;
		joint2->enableLimit = false;

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
		//if (rueda1->body-> GetAngularVelocity() < +10.f) rueda1->body->ApplyTorque(speed * 2.f, true);

	}

	void Car2D::RecieveInput(sf::Event event)
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:

				switch (event.key.code)
				{
					case sf::Keyboard::Left:
						joint->SetMotorSpeed(50.0f);
						break;
					case sf::Keyboard::Right:
						joint->SetMotorSpeed(-50.0f);
						break;
				}
				break;

			case sf::Event::KeyReleased:

				switch (event.key.code)
				{
					case sf::Keyboard::Left:
						joint->SetMotorSpeed(0.0f);
						break;
					case sf::Keyboard::Right:
						joint->SetMotorSpeed(0.0f);
						break;
				}

				break;

		}
	}
}