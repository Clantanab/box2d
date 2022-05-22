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

#include <2dBox.hpp>
#include <scene.hpp>




using namespace practica1;

int main ()
{
    constexpr auto window_width = 800u;
    constexpr auto window_height = 600u;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Box2D Forces", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));

    window.setVerticalSyncEnabled(true);

    // Se crea y se configura la escena física (de 8 x 6 metros):





    Scene s("prueba", &window);
    auto* box = new Box2d(*s.physicsWorld, b2_kinematicBody, 4, 3, 1, 0.2f);
    s.AddObject(box);
    s.Init(60);

    return 0;
}
