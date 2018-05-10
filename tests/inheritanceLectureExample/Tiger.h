#ifndef TIGER_H
#define TIGER_H

#include <string>
#include "Animal.h"

class Tiger : public Animal
{
  int prey_killed;

public:

  Tiger();
  Tiger(std::string name, int id);
  void hunt();
};

#endif
