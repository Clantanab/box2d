
#include <plataformaElevadora.hpp>


namespace practica1
{



	PlataformaElevadora::PlataformaElevadora(b2World& world, float x, float y, float width, float height, float speed, float maxAltura): Box2d( world, b2_kinematicBody,  x,  y,  width,  height)
	{
		this->orginalYposition = y;
		this->active = false;
		this->speed = speed;
		this->maxAltura = maxAltura;
	}

	void PlataformaElevadora::Activate()
	{
		if (active == true) segundaActivacion = true;
		this->active = true;

	}

	void PlataformaElevadora::Update()
	{
		if (segundaActivacion == true)
		{
			if (body->GetPosition().y < this->orginalYposition + maxAltura)
			{
				this->body->SetLinearVelocity({0,+1});
			}
			else
			{
				this->body->SetLinearVelocity({ 0,0 });
				segundaActivacion = false;
			}

		}
	}


}