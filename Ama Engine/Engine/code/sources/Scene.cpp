/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once
#include "Scene.hpp"

namespace engine {
	
	void Scene::Stop() {
		kernel.stop();
	}

	void Scene::SetVisibility(bool vis, const char * name)
	{
		scene_render.setVisibility(vis, name);

	}

	void Scene::resetCamera()
	{
		scene_render.ResetCamera();
	}


	void Scene::AddEntities(Entity  entity) {

		
		EntityList.push_back(entity);
		
		scene_render.UpdateEntityRenderList(EntityList);
		
		scene_render.AddEntityRender();

	}

	const char* Scene::Move(float x, float y, float z, float xRotation, float yRotation, float zRotation)
	{
		return scene_render.SetCamera(x, y, z, xRotation, yRotation, zRotation);

	}

	

	Scene::Scene() {
		window_scene.enable_vsync();

	}


	
	void Scene::run()
	{
		kernel.add(render_tarea);
		kernel.add(imput_task);
		kernel.run();
	}

	Scene::~Scene()
	{
	}


}