#include "Tiger.h"

using namespace std;

// implementation of the default Tiger constructor
Tiger::Tiger() : Animal("?","carnivore","Tiger",1,5)
{
	prey_killed = 0;
}

// implementation of a Tiger constructor taking a name and food type
Tiger::Tiger(string given_name, int id) : Animal(given_name,"carnivore","Tiger", id, 5)
{
	prey_killed = 0;
}

// implementation of the Tiger hunt function
void Tiger::hunt()
{
	prey_killed++;
	eat(1);
}		
