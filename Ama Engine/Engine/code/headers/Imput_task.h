/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once
#include "Task.hpp"
#include "Window.hpp"

#include "Kernel.hpp"

#include <functional>
#include <map>

#include "iostream"

namespace engine {

	class Imput_task : public Task 
	{
	public:
		Window *window;
		Kernel *kernel;
		Window::Event event;

		//list of keys and lambda functions
		std::map<Keyboard::Key_Code, const std::function<void()>* > KeyActions;

		//function defined on main
		const std::function<void()>& lambada = nullptr;

		//Call function that gets defined in main
		void EventTest(const std::function<void()> func) { func(); };


		Imput_task(Window &Rwindow,Kernel &Rkernel) : window(&Rwindow),kernel(&Rkernel) {};

		void run() override {

			while (window->poll(event))
			{
				switch (event.type)
				{
				case Window::Event::KEY_PRESSED:
				{
					for (auto i : KeyActions) 
					{
						if (i.second != NULL && event.data.keyboard.key_code == i.first )
						{
							EventTest(*i.second);
							
						}
					}

					break;
				}
				}
			}		
		}
	};
}