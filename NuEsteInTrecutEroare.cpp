#include "NuEsteInTrecutEroare.h"
 
NuEsteInTrecutEroare::NuEsteInTrecutEroare(const std::string& mesaj)
    : JocEroare("Data nu este in trecut: " + mesaj) {}