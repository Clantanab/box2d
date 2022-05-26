

#include <copa.hpp>


namespace practica1
{
	Copa::Copa(float posX, float posY, float altura, b2World& physics_world)
	{


	
		box = new Box2d(physics_world, b2_dynamicBody, posX, posY, 0.1f, 0.7f);
		box->body->SetTransform({posX, posY}, 0.7f);

		box1 = new Box2d(physics_world, b2_dynamicBody, posX, posY, 0.1f, 0.7f);
		box1->body->SetTransform({ posX+1.f, posY }, -.7f);

		sujetador = new Box2d(physics_world, b2_kinematicBody, posX + 0.5f, posY - 1.5f, 0.1f, 1.f);


		b2RevoluteJointDef* joint = new b2RevoluteJointDef();
		b2Vec2 vec{ 0.45f, -0.45f };

		joint->Initialize(sujetador->body, box->body, box->body->GetPosition() + vec);
		joint->enableMotor = true;
		joint->maxMotorTorque = 10.f;
		joint->motorSpeed = -1.0f;
		
		joint->collideConnected = false;
		joint1 = dynamic_cast<b2RevoluteJoint*>    (physics_world.CreateJoint(joint));

		b2RevoluteJointDef* a = new b2RevoluteJointDef();
		b2Vec2 vec1{ -0.45f, -0.45f };

		a->Initialize(sujetador->body, box1->body, box1->body->GetPosition() + vec1);
		a->enableMotor = true;
		a->maxMotorTorque = 10.f;
		a->motorSpeed = -1.0f;
		
		a->collideConnected = false;
		joint2 = dynamic_cast<b2RevoluteJoint*>    (physics_world.CreateJoint(a));

       /* shape1 = new b2PolygonShape();
        b2Vec2 vertices1[4];
        vertices1[0] = { posX - 0.3f, posY + 0.3f };
        vertices1[1] = { posX - 0.25f, posY + 0.35f };
        vertices1[2] = { posX, posY + 0.05f };
        vertices1[3] = { posX, posY - 0.05f };
        shape1->Set(vertices1, vertices1->Length());

        body->CreateFixture(shape1, 1);*/

	
	}
	void Copa::Render(sf::RenderWindow& renderer, float window_height, float scale)
	{
		box->Render(renderer, window_height, scale);
		box1->Render(renderer, window_height, scale);
		sujetador->Render(renderer, window_height, scale);
	}



}