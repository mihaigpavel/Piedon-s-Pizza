#ifndef NUESTEPOZITIVERROARE_H
#define NUESTEPOZITIVERROARE_H
 
#include "JocEroare.h"
 
class NuEstePozitivEroare : public JocEroare {
public:
    explicit NuEstePozitivEroare(const std::string& mesaj);
};
 
#endif