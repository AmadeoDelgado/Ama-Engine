/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once

#include "Kernel.hpp"
#include "Window.hpp"
#include "Sample_Renderer.hpp"
#include "Entity.hpp"

#include "Imput_task.h"
#include "Renderer_task.hpp"

#include <list>

namespace engine {

	class Scene
	{

	public:
		Scene();
		~Scene();

		//Adds task and runs kernel
		void run();

		//Add entity to the list
		void AddEntities(Entity);

		//Return lambda functions for imputs
		Imput_task& ReturnImputTask() { return imput_task; }

		//Moves character
		const char* Move(float x, float y, float z, float xRotation, float yRotation, float zRotation);
		
		//Stop Kernel
		void Stop();

		void SetVisibility(bool vis, const char* name);
		void resetCamera();
	private:

		

		std::list <Entity> EntityList;

		Kernel kernel;
		Window window_scene{ "window",1280,720 };
		Sample_Renderer  scene_render = { window_scene,EntityList };

		Imput_task imput_task{ window_scene,kernel };
		Renderer_task render_tarea{scene_render};

	};

	
}