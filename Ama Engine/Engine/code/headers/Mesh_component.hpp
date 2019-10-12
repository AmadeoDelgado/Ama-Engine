/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once

#include "Component.hpp"
#include <math.h>
#include <iostream>

namespace engine {

	class MeshComponent : public Component
	{

		const char * file = { "..//..//assets//buny.obj" };

	public:

		enum CollisionType
		{
			Sphere, Box
		} collisiontype;

		//Union data for sphere or box collider
		union Data
		{
			float radius;

			struct BoxData
			{
				float width;
				float height;
				float depht;
			}boxData;

		}data;



		MeshComponent(const char* fileDir, CollisionType colision, Data m_data) : file(fileDir), collisiontype(colision), data(m_data) {};
		inline const char* getMesh() { return file; };
		
		//Returns if camera is within this Mesh_Component area
		bool isInArea(float x, float y, float z);

	};
}