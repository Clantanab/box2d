//
// Este código es de dominio público.
// angel.rodriguez@esne.edu
// 2021.03+
//
// Controles:
//
//   Espacio: aplicar impulso hacia arriba.
//   Izquierda/derecha: aplicar fuerza de giro.
//   Click->Arrastrar->soltar: aplicar impulso en la dirección seleccionada.
//

#include <ciso646>
#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <edge.hpp>
#include <2dBox.hpp>
#include <car2D.hpp>
#include <scene.hpp>
#include <Sensor.hpp>
#include <copa.hpp>
#include <copa.hpp>
#include <plataformaElevadora.hpp>



using namespace practica1;

int main ()
{
    constexpr auto window_width = 1000u;
    constexpr auto window_height = 800u;

    constexpr float left = 0.01f;
    constexpr float right = 10.00f;
    constexpr float top = 8.00f;
    constexpr float bottom = 0.01f;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Box2D Forces", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));

    window.setVerticalSyncEnabled(true);

    // Se crea y se configura la escena física (de 8 x 6 metros):





    Scene s("prueba", &window);
   // auto* box = new Box2d(*s.physicsWorld, b2_kinematicBody, 4, 3, 1, 0.2f);
    //auto* circle = new Circle2D(*s.physicsWorld, b2_dynamicBody, 1.6, 6, 0.5f);

    Edge2D e(*s.physicsWorld, b2_staticBody, left, bottom, right, bottom);
    Edge2D e1(*s.physicsWorld, b2_staticBody, left, bottom, left, top);
    Edge2D e2(*s.physicsWorld, b2_staticBody, left, bottom, left, top);
    Edge2D e3(*s.physicsWorld, b2_staticBody, right, bottom, right, top);
    Edge2D e4(*s.physicsWorld, b2_staticBody, left, 4.0f, 1.50f, 4.0f);
    Edge2D e5(*s.physicsWorld, b2_staticBody, 1.50f, 4.0f, 2.5f, 3.0f);
    Edge2D e6(*s.physicsWorld, b2_staticBody, 2.5f, 3.0f, 3.5f, 2.50f);
    Edge2D e7(*s.physicsWorld, b2_staticBody, 3.5f, 2.50f, 4.5f, 2.25f);
    Edge2D e8(*s.physicsWorld, b2_staticBody, 4.5f, 2.25f, 5.5f, 2.25f);
    Edge2D e9(*s.physicsWorld, b2_staticBody, 7.5f, 1.25f, 10.f, 1.25f);
    //Edge2D e10(*s.physicsWorld, b2_staticBody, 5.75f, 0.75f, 7.25f, 0.75f);


    Copa c(7.5f,6,1, *s.physicsWorld);
 

    Car2D car(0.15f, 0.15f, -0.35f, -0.35f, 0.02f, 0.02f, 1.0f, 5.5f, 0.5f, 0.1f, -6, *s.physicsWorld);

    PlataformaElevadora pla(*s.physicsWorld, 6.5f, 0.75f, 1.f, 0.1f, 1, 6.f);

    Sensor sas(e9.body, &car, 1.f, {7.50f, 1.25f});
    Sensor ses(e9.body, &car, 1.f, {6.5f, 0.75f});

    ses.AddActiver(&pla);
    sas.AddActiver(&c);
    sas.AddActiver(&pla);
    //s.AddObject(circle);

    s.AddReceiver(&car);

    s.AddObject(&car);
    s.AddObject(&e);
    s.AddObject(&e1);
    s.AddObject(&e2);
    s.AddObject(&e3);
    s.AddObject(&e4);
    s.AddObject(&e5);
    s.AddObject(&e6);
    s.AddObject(&e7);
    s.AddObject(&e8);
    s.AddObject(&e9);
    s.AddObject(&c);
    s.AddObject(&pla);
    s.AddObject(&sas);
    s.AddObject(&ses);
   // s.AddObject(&e10);


    s.Init(60);

    return 0;
}
