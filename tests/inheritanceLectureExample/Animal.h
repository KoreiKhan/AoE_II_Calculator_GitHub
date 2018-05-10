#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
  std::string name;
  std::string species;
  std::string type;
  int id;
  int hunger;

 public:

  Animal();
  Animal(std::string given_name, std::string given_type, std::string given_species, int id, int hunger);

  void eat(int quantity);		
  void play(int time);
  void make_sound(int time);

  bool is_hungry();
  int get_id();
  std::string get_name();

  void set_id(int new_id);
  void set_name(std::string new_name);
};

#endif
