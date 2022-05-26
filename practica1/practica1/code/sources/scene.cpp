

#include <scene.hpp>


namespace practica1
{


	Scene::Scene(const std::string& id, sf::RenderWindow* window)
	{
		this->id = id;

		//SceneManager::Instance().AddScene(this);


		physicsWorld.reset(new b2World(b2Vec2{ 0, -7.f }));
		this->window = window;

	}

	void Scene::Init(float targetFps)
	{
		this->active = true;
		float targetTime = 1.f / targetFps;

		float deltaTime = targetTime;

		sf::Clock timer;

		do
		{
			timer.restart();

			Update(deltaTime);

			float elapsed = timer.getElapsedTime().asSeconds();

			if (elapsed < targetTime)
			{
				sf::sleep(sf::seconds(targetTime - elapsed));
			}
			deltaTime = timer.getElapsedTime().asSeconds();

		} while (this->active);

	}

	void Scene::Update(float time) 
	{
		
		window->clear();


		//render y updates
		physicsWorld->Step(time, 8, 4);
		
		for (auto& object : objects)
		{
			object->Update();
			object->Render(*window, window->getSize().y, 100.f);
		}

		window->display();


		sf::Event a;
		while (window->pollEvent(a))
		{
			for (auto& recierver : recievers)
			{
				recierver->RecieveInput(a);
			}
		}
	}





	void Scene::AddObject(Object* object)
	{
		objects.push_back(object);
	}

	void Scene::AddReceiver(InputReciever* reciever)
	{
		recievers.push_back(reciever);
	}
}