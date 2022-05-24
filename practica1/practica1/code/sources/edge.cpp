

#include <edge.hpp>

namespace practica1
{
	Edge2D::Edge2D(b2World& physics_world, b2BodyType body_type, float x0, float y0, float x1, float y1)
	{
		b2BodyDef body_definition;

		body_definition.type = body_type;
		body_definition.position.Set(0.f, 0.f);                        // Posición inicial absoluta

		this->body = physics_world.CreateBody(&body_definition);

		// Se añande una fixture:
		shape = new b2EdgeShape();


		shape->SetTwoSided(b2Vec2(x0, y0), b2Vec2(x1, y1));        // Coordenadas locales respecto al centro del body

		b2FixtureDef body_fixture;

		body_fixture.shape = shape;

		body->CreateFixture(&body_fixture);
	}
	void Edge2D::Render(sf::RenderWindow& renderer, float window_height, float scale)
	{
		b2Vec2   start = b2Mul(body->GetTransform(), shape->m_vertex1);
		b2Vec2    end = b2Mul(body->GetTransform(), shape->m_vertex2);

		sf::Vertex line[] =
		{
			sf::Vertex(Utils::box2d_position_to_sfml_position( start, window_height, scale), sf::Color::Green),
			sf::Vertex(Utils::box2d_position_to_sfml_position(end, window_height, scale), sf::Color::Green),
		};

		renderer.draw(line, 2, sf::Lines);
	}
}