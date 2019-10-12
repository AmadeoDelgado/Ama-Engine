/*Amadeo Delgado Casado
14/01/2019
*/



#pragma once


namespace engine
{
	class Component 
	{
	public:
		float scale = 1.f;

		float xPos = 0.f;
		float yPos = 0.f;
		float zPos = 0.f;

		float xRot = 0.f;
		float yRot = 0.f;
		float zRot = 0.f;

		inline void setPosition(float x, float y, float z) { xPos = x; yPos = y; zPos = z; };
		inline void setRotation(float x, float y, float z) { xRot = x; yRot = y; zRot = z; };

		Component() = default;
		virtual ~Component() {};
	
	};
}