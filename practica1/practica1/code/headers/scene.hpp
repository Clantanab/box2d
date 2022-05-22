#pragma once


#include <iostream>
#include <vector>
#include <object.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
//#include <entity.hpp>
//#include<RendererSystem.hpp>
//#include<updateSystem.hpp>
//#include <InputSystem.hpp>
//#include <kernel.hpp>
//#include <sceneManager.hpp>


namespace practica1 
{


	class Window;

	class  Scene
	{


	private:
		std::string id;
		std::vector<Object*> objects;
		sf::RenderWindow* window;



	public:
		
		std::unique_ptr <b2World> physicsWorld;
		bool active = false;
		 Scene(const std::string& id, sf::RenderWindow* window);


		//std::unique_ptr <InputSystem>    inputSystem;

		void Init(float targetFps);
		void Update(float time);

		std::string GetName() {	return id;}

		void AddObject(Object* object);
		


	private:

	};


}