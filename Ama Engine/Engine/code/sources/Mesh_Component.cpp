/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once
#include "Mesh_component.hpp"

namespace engine {

	bool MeshComponent::isInArea(float x, float y, float z) 
	{
		switch (collisiontype)
		{

		case(Sphere):
		{
			//if distance is minor than radious return true 
			if (data.radius > std::sqrt((std::pow((x - xPos), 2) + std::pow((y - yPos), 2) + std::pow((z - zPos), 2)))) { std::cout << "Radious: " << data.radius - std::sqrt((std::pow((x - xPos), 2) + std::pow((y - yPos), 2) + std::pow((z - zPos), 2))) << std::endl; return true; }
			else return false;


			break;
		}
		case (Box):
		{
			//if x,y,z are withing min and max values of the box return true
			if ((x > (xPos - (data.boxData.width / 2))) && (x < (xPos + (data.boxData.width / 2))) &&
				(y > (yPos - (data.boxData.height / 2))) && (y < (yPos + (data.boxData.height / 2))) &&
				(z > (zPos - (data.boxData.depht / 2))) && (z < (zPos + (data.boxData.depht / 2))))
			{
				return true;
			}

			//Camera is far return false
			else return false;

			break;
		}


		}
	}
};
