

#include <car2D.hpp>

#include <iostream>
namespace practica1
{
	Car2D::Car2D(float r1Radius, float r2Radius, float heightR1, float heightR2, float separationR1, float separationR2, float x, float y, float width, float height, float speed, b2World& world)
	{
		//Parte principal del coche 
		
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
		joint1->maxMotorTorque = 500.f;
		joint1->motorSpeed = 0.0f;
		joint1->lowerTranslation = heightR1;
		joint1->stiffness = 1.0f;
		joint1->damping = 1.f;
		joint1->enableLimit = true;

		joint1->damping = 1.0f;
		joint1->collideConnected = true;
		

		joint = dynamic_cast<b2WheelJoint*>  (world.CreateJoint(joint1));


		b2WheelJointDef* joint2 = new b2WheelJointDef();
		joint2->Initialize(cuerpo->body, rueda2->body,  rueda2->body->GetPosition(), axis);

		joint2->enableMotor = false;
		joint2->motorSpeed = 0.0f;
		joint2->enableLimit = true;

		joint2->stiffness = 1.0f;
		joint2->damping = 1.f;
		joint2->collideConnected = true;
		joint22 = dynamic_cast<b2WheelJoint*>  (world.CreateJoint(joint2));

		//caja 


		this->base = new Box2d(world, b2_dynamicBody, x , y + height + 0.1f, width , height/4);

		this->lado1 = new Box2d(world, b2_dynamicBody, x - width, y + height + (width/2), width / 3, height / 4);
		lado1->body->SetTransform({ x - width, y + height + (width / 2)  }, 1.6f);

		b2RevoluteJointDef* rj1 = new b2RevoluteJointDef();
		rj1->Initialize(base->body, lado1->body, {x-width, y + height});
		rj1->enableMotor = true;
		rj1->maxMotorTorque = 400.f;
		rj1->motorSpeed = 0.0f;
		rj1->collideConnected = false;
		rj1->enableLimit = true;
		world.CreateJoint(rj1);


		this->lado2 = new Box2d(world, b2_dynamicBody, x+ width, y + height + (width / 2), width / 3, height / 4);
		lado2->body->SetTransform({ x + width, y + height + (width / 2) }, 1.6f);


		b2RevoluteJointDef* rj2 = new b2RevoluteJointDef();
		rj2->Initialize(base->body, lado2->body, { x + width, y + height });
		rj2->enableMotor = true;
		rj2->maxMotorTorque = 400.f;
		rj2->motorSpeed = 0.0f;
		rj2->collideConnected = false;  
		rj2->enableLimit = true;
		world.CreateJoint(rj2);

		b2Vec2 axis3(0.f, 1.0f);
		b2WheelJointDef* joint3 = new b2WheelJointDef();
		joint3->Initialize(cuerpo->body, base->body, { x - width, y + height }, axis3);
		joint3->enableMotor = true;
		joint3->maxMotorTorque = 400.f;
		joint3->motorSpeed = 0.0f;
		joint3->lowerTranslation = 1;
		joint3->stiffness = 1.0f;
		joint3->enableLimit = false;
		joint3->collideConnected = true; 
		joint3->damping = 1;
		
		world.CreateJoint(joint3);
		cajaJoint = dynamic_cast<b2WheelJoint*>  (world.CreateJoint(joint3));


	}


	void Car2D::Render(sf::RenderWindow& renderer, float window_height, float scale)
	{
		this->cuerpo->Render(renderer, window_height, scale);
		this->rueda1->Render(renderer, window_height, scale);
		this->rueda2->Render(renderer, window_height, scale);
		this->base->Render(renderer, window_height, scale);
		this->lado1->Render(renderer, window_height, scale);
		this->lado2->Render(renderer, window_height, scale);
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
						joint22->SetMotorSpeed(50.f);
						break;
					case sf::Keyboard::Right:
						joint->SetMotorSpeed(-50.0f);
						joint22->SetMotorSpeed(-50.f);
						break;

					case sf::Keyboard::Space:
						cajaJoint->SetMotorSpeed(10.0f);
						break;
					case sf::Keyboard::C:
						cajaJoint->SetMotorSpeed(-10.0f);
						break;
				}
				break;

			case sf::Event::KeyReleased:

				switch (event.key.code)
				{
					case sf::Keyboard::Left:
						joint->SetMotorSpeed(0.0f);
						joint22->SetMotorSpeed(0.f);
						break;
					case sf::Keyboard::Right:
						joint->SetMotorSpeed(0.0f);
						joint22->SetMotorSpeed(0.f);
						break;
					case sf::Keyboard::Space:
						cajaJoint->SetMotorSpeed(0.0f);
						break;
					case sf::Keyboard::C:
						cajaJoint->SetMotorSpeed(0.0f);
						break;
				}

				break;

		}
	}
}