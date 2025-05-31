#include "JocEroare.h"
 
JocEroare::JocEroare(const std::string& mesaj)
    : std::runtime_error(mesaj) {}