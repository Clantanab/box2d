#pragma once



#include <2dBox.hpp>
#include <activers.hpp>

namespace practica1
{
	class PlataformaElevadora : public Box2d, public Activer 
	{
	protected:
		float orginalYposition;
		float speed;
		float maxAltura;



	public:

		PlataformaElevadora(b2World& world, float x, float y, float width, float height, float speed, float maxAltura);
		void Activate() override;
		void Update() override ;


	};
}