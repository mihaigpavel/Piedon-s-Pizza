#include "NuEstePozitivEroare.h"
 
NuEstePozitivEroare::NuEstePozitivEroare(const std::string& mesaj)
    : JocEroare("Nu este pozitiv: " + mesaj) {}