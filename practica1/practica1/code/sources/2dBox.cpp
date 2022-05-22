#include <2dBox.hpp>


namespace practica1
{
	Box2d::Box2d(b2World& world, b2BodyType bodytype, float x, float y, float width, float height)
	{


        b2BodyDef bodyDefinition;

        bodyDefinition.type = bodytype;
        bodyDefinition.position.Set(x, y);                            

        body = world.CreateBody(&bodyDefinition);

        //this->shape->SetAsBox(width, height);
        shape = new b2PolygonShape();
        shape->SetAsBox(width, height);




        b2FixtureDef body_fixture ;

        body_fixture.shape = shape;
        body_fixture.density = 1.00f;
        body_fixture.restitution = 0.50f;
        body_fixture.friction = 0.50f;

        body->CreateFixture(&body_fixture);
	}

    void Box2d::Render(sf::RenderWindow& renderer, float window_height, float scale)
    {
        sf::ConvexShape sfml_polygon;

        sfml_polygon.setPointCount(shape->m_count);
        sfml_polygon.setFillColor(sf::Color::Yellow);

        for (int index = 0; index < shape->m_count; index++)
        {
            sfml_polygon.setPoint
            (
                index,
                Utils::box2d_position_to_sfml_position(b2Mul(body->GetTransform(), shape->m_vertices[index]), window_height, scale)
            );
        }

        renderer.draw(sfml_polygon);
    }
}