/*Amadeo Delgado Casado
14/01/2019
*/



#pragma once

#include "Task.hpp"
#include <set>

namespace engine
{
	class Kernel
	{
		bool exit;
		std::multiset< Task * > tasks;


	public:

		Kernel() = default;


	public:
		
		//Add task to the kernel
		inline void add(Task & task) 
		{
			tasks.insert(&task);
		};

		//Executes run of all tasks
		void run()
		{
			exit = false;
			
			do {
				for (auto task : tasks)
				{
					task->run();
				}

			} while (!exit);
		};
		
		//Stops the aplication
		inline void stop() { exit = true; }
	};

}