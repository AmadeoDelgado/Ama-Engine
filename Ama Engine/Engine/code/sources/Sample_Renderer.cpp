
// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

/*Edited by Amadeo Delgado Casado
14/01/2019
*/


#include <Cube.hpp>
#include <Model.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
#include <Sample_Renderer.hpp>
#include <Window.hpp>



#include "Mesh_component.hpp"

#include <Model_Obj.hpp>

#include "Entity.hpp"

#include <map>

using namespace std;
using namespace glt;

namespace engine
{

	Sample_Renderer::Sample_Renderer(Window & given_window, list<Entity>& lista)
	{
		window = &given_window;

		// Se crea el render node de OpenGL Toolkit:

		renderer.reset(new Render_Node);

		//Copy the entity list
		RenderEntityList = &lista;
		
		//Map of models with their file dirs
		map <const char*, shared_ptr<Model>> ModelsMap;

		//Creates a camera an a light
		shared_ptr< Camera > camera(new Camera(20.f, 0.1f, 500.f, 1.77f));
		shared_ptr< Light  > light(new Light);
		
		light->set_intensity(0.5f);
		
		renderer->add("camera", camera);

		renderer->add("light", light);
		renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));

	}

	Sample_Renderer::~Sample_Renderer()
	{
		// En este caso es necesario definir explícitamente el destructor en el archivo
		// de implementación (CPP) para que el compilador pueda destruir el Render_Node
		// pese a que no hay código explícito.
	}

	void Sample_Renderer::render()
	{
		
		Update();

		// Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

		GLsizei width = GLsizei(window->get_width());
		GLsizei height = GLsizei(window->get_height());

		renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		// Se rota el objeto:


		window->clear();

		renderer->render();

		window->swap_buffers();
	}

	
	void Sample_Renderer::UpdateEntityRenderList(std::list<Entity>& Elist)
	{
		*RenderEntityList = Elist;
	}

	void Sample_Renderer::AddEntityRender()
	{
		//Goes in all components and all enities
		for (auto i : *RenderEntityList)
		{
			for (auto j : i.GetMapComponets())
			{
				//If there is not a node with this name
				if (!renderer->get(j.first))
				{
					//Creates a mesh

					MeshComponent * old_child = dynamic_cast<MeshComponent*>(j.second);
					shared_ptr< Model  > model(new Model_Obj(old_child->getMesh()));
					renderer->add(j.first, model);

					renderer->get(j.first)->scale(old_child->scale);
					renderer->get(j.first)->translate(Vector3(old_child->xPos, old_child->yPos, old_child->zPos));

				}
			}
		}
	}

	void Sample_Renderer::Update()
	{


		for (auto i : *RenderEntityList)
		{
			for (auto j : i.GetMapComponets())
			{
				if (renderer->get(j.first))
				{
					//Rotates
					renderer->get(j.first)->rotate_around_x(j.second->xRot);
					renderer->get(j.first)->rotate_around_y(j.second->yRot);
					renderer->get(j.first)->rotate_around_z(j.second->zRot);

					//If the New position dosent match the actual position moves
					if (renderer->get(j.first)->get_transformation()[3][0] != j.second->xPos ||
						renderer->get(j.first)->get_transformation()[3][1] != j.second->yPos || 
						renderer->get(j.first)->get_transformation()[3][2] != j.second->zPos)
					{
						renderer->get(j.first)->translate(
							Vector3(
								renderer->get(j.first)->get_transformation()[3][0] - j.second->xPos, 
								renderer->get(j.first)->get_transformation()[3][1] - j.second->yPos,
								renderer->get(j.first)->get_transformation()[3][2] - j.second->zPos
							));
					}
					
					renderer->get(j.first)->scale(j.second->scale);
				}
			}
		}
	}

	const char* Sample_Renderer::SetCamera(float xpo, float ypo, float zpo, float xro, float yro, float zro)
	{
		bool move = true;
		const char *collisionMesh = nullptr;
		
		for (auto i : *RenderEntityList)
		{
			for (auto j : i.GetMapComponets())
			{
				if (renderer->get(j.first))
				{

					MeshComponent * old_child = dynamic_cast<MeshComponent*>(j.second);
					
					
					if (
						//Checks colision

						old_child->isInArea(
						renderer->get_active_camera()->get_transformation()[3][0] + xpo,
						renderer->get_active_camera()->get_transformation()[3][1] + ypo,
						renderer->get_active_camera()->get_transformation()[3][2] + zpo)
						)
					{
						collisionMesh = j.first;
						move = false;
					}
				}
			}
		}


		if (move) renderer->get_active_camera()->translate(Vector3(xpo, ypo, zpo));
		renderer->get_active_camera()->rotate_around_x(xro);
		renderer->get_active_camera()->rotate_around_y(yro);
		renderer->get_active_camera()->rotate_around_z(zro);

		//Returns nullptr or mesh colision name
		return collisionMesh;
		
	}


	void Sample_Renderer::setVisibility(bool visible, const char* name)
	{
		renderer->get(name)->set_visible(visible);
	}

	void Sample_Renderer::ResetCamera()
	{
		renderer->get_active_camera()->reset_transformation();
	}

}