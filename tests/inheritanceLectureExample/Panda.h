#ifndef PANDA_H
#define PANDA_H

#include <string>
#include "Animal.h"

class Panda : public Animal
{
  bool fussy_eater;

 public: 

  Panda();
  Panda(std::string panda_name, int panda_id, bool fussy);

  Panda operator+(Panda another_panda);

};

#endif
