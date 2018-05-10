#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

// implementation of default Animal constructor
Animal::Animal()
{
  id = 0;
  name = "?";
  species = "?";
  type = "?";
  hunger = 0;
}

Animal::Animal(string the_name, string the_type, string the_species, int the_id, int the_hunger)
{
  id = the_id;
  name = the_name ;
  species = the_species ;
  type = the_type ;
  hunger = the_hunger ;
}


void Animal::eat(int quantity)
{
  hunger = hunger - quantity;
  if (hunger < 0)
    hunger = 0;
}		


void Animal::play(int time)
{
  hunger = hunger + time;
}		


void Animal::make_sound(int time)
{
  while (time > 0) {
    cout << "generic animal sound" << endl;
    time--;
  }
}		

std::string Animal::get_name() {
  return name;
}

int Animal::get_id() {
  return id;
}
 
bool Animal::is_hungry() {
  if (hunger >=5)
    return true;
  return false;
}

void Animal::set_name(std::string new_name) {
  name = new_name;
}

void Animal::set_id(int new_id) {
  id = new_id;
}
