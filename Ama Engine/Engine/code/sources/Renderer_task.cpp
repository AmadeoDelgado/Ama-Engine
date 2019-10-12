/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once
#include "Renderer_task.hpp"



namespace engine {

	
	void Renderer_task::run()
	{
		sample_REND->render();
	}
}