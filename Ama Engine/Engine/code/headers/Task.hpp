/*Amadeo Delgado Casado
14/01/2019
*/


#pragma once



namespace engine {
	
	class Task
	{

	private:
		int priority;
		
	public:
		
		inline int getpriority() { return priority; };

	
		//Abstract virtual method run obligatory to implement
		virtual void run() = 0;
		


		Task()=default;
	
	protected:
		
		//Contructor just for children of task

		Task (int param_priotrity) : priority(param_priotrity) {};

	
	};






	

	

}
