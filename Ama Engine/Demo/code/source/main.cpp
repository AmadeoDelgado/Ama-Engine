/*Amadeo Delgado Casado
14/01/2019
*/



#include "iostream"
#include <stdlib.h>


#include "Scene.hpp"
#include "Entity.hpp"





#include <functional>
#include <memory>


using namespace engine;

void DisapearComponet(Entity &entidad, const char* component)
{
	entidad.getcomponent(component)->setPosition(1, -1, -7);

}
//Makes a component of an entity not visible




int main(int number_of_arguments, char * arguments[]) {

	Scene es;
   
	Entity Room("Room", 1);
	Entity Numbers("Numbers", 2);

	int counter = 1;
	
	

	//Create the room with 4 wall & 1 floor
	
	Room.CreateComponent(Entity::Mesh_Component(), "wall1", "..\\..\\assets\\wall1.obj",0,0,5,50,50);
	Room.CreateComponent(Entity::Mesh_Component(), "wall2", "..\\..\\assets\\wall2.obj",0, 0, 5, 50, 50);
	Room.CreateComponent(Entity::Mesh_Component(), "wall3", "..\\..\\assets\\wall3.obj", 0, 0, 50, 50, 5);
	Room.CreateComponent(Entity::Mesh_Component(), "wall4", "..\\..\\assets\\wall4.obj",0, 0, 50, 50, 5);
	Room.CreateComponent(Entity::Mesh_Component(), "floor", "..\\..\\assets\\floor.obj");
	
	
	Room.getcomponent("wall1")->setPosition(-24,-1.5,0);
	Room.getcomponent("wall2")->setPosition(24, -1.5, 0);;
	Room.getcomponent("wall3")->setPosition(0, -1.5, 24);;
	Room.getcomponent("wall4")->setPosition(0, -1.5, -24);;
	Room.getcomponent("floor")->yPos = -5;

	//Add numbers

	Numbers.CreateComponent(Entity::Mesh_Component(), "1", "..\\..\\assets\\1.obj", 1,1.6f);
	Numbers.CreateComponent(Entity::Mesh_Component(), "2", "..\\..\\assets\\2.obj", 1, 1.1f);
	Numbers.CreateComponent(Entity::Mesh_Component(), "3", "..\\..\\assets\\3.obj", 1, 1.1f);
	Numbers.CreateComponent(Entity::Mesh_Component(), "4", "..\\..\\assets\\4.obj", 1, 1.1f);
	Numbers.CreateComponent(Entity::Mesh_Component(), "5", "..\\..\\assets\\5.obj", 1, 1.1f);
	
	Numbers.getcomponent("1")->setPosition(-10, -1, -15);
	Numbers.getcomponent("1")->setRotation(0, 0.1f, 0);
	Numbers.getcomponent("2")->setPosition(12, -1, -17);
	Numbers.getcomponent("2")->setRotation(0, 0.1f, 0);
	Numbers.getcomponent("3")->setPosition(12, -1, 0);
	Numbers.getcomponent("3")->setRotation(0, 0.1f, 0);
	Numbers.getcomponent("4")->setPosition(-11, -1, 0);
	Numbers.getcomponent("4")->setRotation(0, 0.1f, 0);
	Numbers.getcomponent("5")->setPosition(-15, -1, 10);
	Numbers.getcomponent("5")->setRotation(0, 0.1f, 0);
	
	//add entities to scene
	es.AddEntities(Room);
	es.AddEntities(Numbers);
	
	

	
	//ON E PRESSED RESET GAME
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_E, new const std::function<void()>([&]() { es.resetCamera();	counter = 1;
	es.SetVisibility(true, "1");
	es.SetVisibility(true, "2");
	es.SetVisibility(true, "3");
	es.SetVisibility(true, "4");
	es.SetVisibility(true, "5");
	es.SetVisibility(true, "wall1");
	es.SetVisibility(true, "wall2");
	es.SetVisibility(true, "wall3");
	es.SetVisibility(true, "wall4");
	}));
	
	//Move back
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_S, new const std::function<void()>([&]() { es.Move(0, 0, 0.04f,0,0,0); }));

	//Move foward
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_W, new const std::function<void()>([&]()
	{ 
		
		const char * moveRes = es.Move(0, 0, -0.08f, 0, 0, 0);

		//If colliding with an object check for number, or wall
		if (moveRes != nullptr)
		{
			//If colliding with an object check for number, or wall
			//Number: Correct, disapears
			//        Incorrect, reestarts
			//Wall:   Reset Camera

			switch (counter)
			{
			case 1:
			{
				if (moveRes == "1" ) 
				{
					es.SetVisibility(false, moveRes); ++counter; es.resetCamera();
				}

				else if (!std::strstr(moveRes, "wall"))
				{
					counter = 1;
					es.SetVisibility(true, "1");
					es.SetVisibility(true, "2");
					es.SetVisibility(true, "3");
					es.SetVisibility(true, "4");
					es.SetVisibility(true, "5");
					es.resetCamera();
				}

				else es.resetCamera();

				break;
			}

			case 2:
			{
				if (moveRes == "2")
				{
					es.SetVisibility(false, moveRes); ++counter; es.resetCamera();
				}
				else if (!std::strstr(moveRes, "wall"))
				{
					counter = 1;
					es.SetVisibility(true, "1");
					es.SetVisibility(true, "2");
					es.SetVisibility(true, "3");
					es.SetVisibility(true, "4");
					es.SetVisibility(true, "5");
					es.resetCamera();


				}

				else es.resetCamera();

				break;
			}
			case 3:
			{
				if (moveRes == "3")
				{
					es.SetVisibility(false, moveRes); ++counter; es.resetCamera();
				}
				else if (!std::strstr(moveRes, "wall"))
				{
					counter = 1;
					es.SetVisibility(true, "1");
					es.SetVisibility(true, "2");
					es.SetVisibility(true, "3");
					es.SetVisibility(true, "4");
					es.SetVisibility(true, "5");
					es.resetCamera();


				}

				else es.resetCamera();

				break;
			}

			case 4:
			{
				if (moveRes == "4") 
				{
					es.SetVisibility(false, moveRes); ++counter; es.resetCamera();
				}

				else if (!std::strstr(moveRes, "wall"))
				{
					counter = 1;
					es.SetVisibility(true, "1");
					es.SetVisibility(true, "2");
					es.SetVisibility(true, "3");
					es.SetVisibility(true, "4");
					es.SetVisibility(true, "5");
					es.resetCamera();


				}

				else es.resetCamera();

				break;
			}

			case 5:
			{

				if (moveRes == "5" || !std::strstr(moveRes, "wall") )
				{
					es.SetVisibility(false, moveRes);
					es.SetVisibility(false, "wall1");
					es.SetVisibility(false, "wall2");
					es.SetVisibility(false, "wall3");
					es.SetVisibility(false, "wall4");
					++counter;
					es.resetCamera();


				}

				else es.resetCamera();
				break;
			
			}
			

			default:
				break;
			}
		}
	}));

	//Turn Right
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_D, new const std::function<void()>([&]() { es.Move(0, 0, 0,0,-0.04f,0); }));
	//Turn Left
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_A, new const std::function<void()>([&]() { es.Move(0, 0, 0,0,0.04f,0); }));
	//Exits game
	es.ReturnImputTask().KeyActions.emplace(Keyboard::KEY_ESCAPE, new const std::function<void()>([&]() { es.Stop(); }));

	es.run();

	return 0;



}


 
