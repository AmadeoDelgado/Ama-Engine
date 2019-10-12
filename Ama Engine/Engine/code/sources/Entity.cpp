/*Amadeo Delgado Casado
14/01/2019
*/



#pragma once
#include "Entity.hpp"

#include "Mesh_component.hpp"

namespace engine {
	
	//Creates component mesh
	void Entity::CreateComponent(Mesh_Component, const char*name, const char* file,bool MeshType ,float radious,float width,float height,float depht)
	{
		switch (MeshType) {

		case (0): {
			//if collision is a box
			MeshComponent::Data data;
			data.boxData.depht = depht;
			data.boxData.height = height;
			data.boxData.width = width;
		
			components.emplace(name, new MeshComponent(file, MeshComponent::Box, data));
		}
		case (1): {
			//if collision is a sphere
			MeshComponent::Data data;
			data.radius = radious;
			components.emplace(name, new MeshComponent(file, MeshComponent::Sphere, data));
		}

		}
			
	}


	Component* Entity::getcomponent(const char* name)
	{
		return components.find(name)->second;

	}

	void Entity::DeleteComponent(const char* name)
	{

		components.erase(components.find(name));

	}




}