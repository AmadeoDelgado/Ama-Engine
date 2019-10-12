/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once
#include "Task.hpp"
#include "Sample_Renderer.hpp"

namespace engine {

	class Renderer_task : public Task
	{
		

		Sample_Renderer *sample_REND;

	public:

		Renderer_task(Sample_Renderer & sample) { sample_REND = &sample; }

		void run() override;
		

	};




}
