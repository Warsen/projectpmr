#include "Engine.h"

Engine::Engine()
{
	resources.LoadAll();

	//Initialize the scenes
	map_scene = new MapScene();
	
	SwitchState(States::OVERWORLD);
}

Engine::~Engine()
{
	if (map_scene)
		delete map_scene;
}

void Engine::Update()
{
	active_scene->Update();
}

void Engine::Render(sf::RenderWindow* window)
{
	active_scene->Render(window);
}

void Engine::SwitchState(States s)
{
	game_state = s;
	switch (game_state)
	{
	case States::OVERWORLD:
		active_scene = (Scene*)map_scene;
		break;
	}

	active_scene->NotifySwitchedTo();
}