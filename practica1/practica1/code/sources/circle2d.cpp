

#include <circle2d.hpp>



namespace practica1
{
	Circle2D::Circle2D(b2World& world, b2BodyType bodytype, float x, float y, float radius)
	{
        b2BodyDef body_definition;

        body_definition.type = bodytype;
        body_definition.position.Set(x, y);                            // Posición inicial absoluta

        this-> body = world.CreateBody(&body_definition);

        // Se añande una fixture:

        this->shape = new b2CircleShape();


        shape->m_radius = radius;

        b2FixtureDef body_fixture;

        body_fixture.shape = shape;
        body_fixture.density = 1.00f;
        body_fixture.restitution = 0.75f;
        body_fixture.friction = 0.50f;

        body->CreateFixture(&body_fixture);
	}


    void Circle2D::Render(sf::RenderWindow& renderer, float window_height, float scale)
    {
        sf::CircleShape sfmlCircle;
        float radius = shape->m_radius;
        radius *= scale;

        sfmlCircle.setPosition(Utils::box2d_position_to_sfml_position(b2Mul(body->GetTransform(), shape->m_p ), window_height, scale) - sf::Vector2f(radius, radius));
        sfmlCircle.setRadius(radius);
        sfmlCircle.setFillColor(sf::Color::Blue);

        renderer.draw(sfmlCircle);
    }
}