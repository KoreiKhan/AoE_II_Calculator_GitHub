#include "Panda.h"

Panda::Panda() : Animal("?","herbivore","Panda",0,10) {
}

Panda::Panda(std::string panda_name, int panda_id, bool fussy) : Animal(panda_name, "herbivore", "Panda", 1, 10) {
  fussy_eater = fussy;
}

