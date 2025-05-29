#ifndef REZULTAT_TESTARE_ALCOOLEMIE_H
#define REZULTAT_TESTARE_ALCOOLEMIE_H

#include <iostream>
#include "DatePersonale.h"

class RezultatTestareAlcoolemie {
private:
    DatePersonale sofer;
    double alcolemie;
    const double pragDosarPenalAlcolemie = 0.8;

public:
    RezultatTestareAlcoolemie(const DatePersonale &sofer, double alcolemie);

    bool esteDosarPenal();
    bool esteCazDeAmenda();

    friend std::ostream &operator<<(std::ostream &os, const RezultatTestareAlcoolemie &p);
};

#endif // REZULTAT_TESTARE_ALCOOLEMIE_H
