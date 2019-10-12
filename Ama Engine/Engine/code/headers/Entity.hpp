/*Amadeo Delgado Casado
14/01/2019
*/



#pragma once

#include "Component.hpp"

#include <map>


namespace engine 
{
	class Component;
	

	class Entity
	{
		

	public:

		//Types of component
		typedef enum {} Mesh_Component;

		//Returns a Map with name and component of the entity
		std::map< const char*, Component*> GetMapComponets() { return components; };
		
		//Returns component of the map
		Component* getcomponent(const char*);
		
		

		
		//Returns name of the componet
		inline const char* getName() { return Name; }

		//Deletes Component from the map 
		void DeleteComponent(const const char*);
		
		//Creates component
		//Overload for Mesh_Component
		void CreateComponent
		(Mesh_Component,const char*name, const char* file,bool MeshType=0,float radious=0,float width=0,float height=0,float depht=0);

		
		Entity(const char * name,int id) :Name(name),Id(id) {};


	private:

		//Map of components
		std::map< const char*, Component* > components;
		
		const char * Name;
		int Id;
		

	};

	

}
