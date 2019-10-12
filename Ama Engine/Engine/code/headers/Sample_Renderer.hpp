
// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// Use it at your own risk. It might have bugs.
// angel.rodriguez@esne.edu

/*Edited by Amadeo Delgado Casado
14/01/2019
*/


#pragma once

#include <memory>
#include <string>
#include <list>
#include <internal/declarations.hpp>





namespace engine
{
	//Foward declarations
    class Window;
	class Entity;
	class Component;

    class Sample_Renderer
    {

        // Se crea un puntero a Render_Node porque al usar una declaración adelantada
        // para no exportar dependencias con esta cabecera, solo se pueden definir
        // punteros o referencias a los tipos declarados de modo adelantado.

        std::unique_ptr< glt::Render_Node > renderer;
		std::list<Entity> * RenderEntityList;
		
		

        Window * window;

    public:

        Sample_Renderer(Window & given_window,std::list<Entity> &);

        /** En este caso es necesario definir explícitamente el destructor en el archivo
          * de implementación (CPP) para que el compilador pueda destruir el Render_Node.
          * Si se deja que el compilador cree un destructor por defecto en el programa
          * que use el engine, como solo tendrá una declaración adelantada, no sabrá cómo
          * destruirlo y ello dará lugar a un error de compilación.
          */
       ~Sample_Renderer();

		//Renders scene
        void render ();

		//Updates de list of entities
		void UpdateEntityRenderList(std::list<Entity> &);

		//Creates a node and adds it to the renderes
		void AddEntityRender();

		//Updates all componets location and rotation
		void Update();

		//Set Camera Pos/Rot
		//Returns nullptr or Collided mesh name
		const char* SetCamera(float xPosition, float yPosition, float zPosition,float xRotation,float yRotation,float zRotation);

		void setVisibility(bool, const char*);

		void ResetCamera();
    };



}
