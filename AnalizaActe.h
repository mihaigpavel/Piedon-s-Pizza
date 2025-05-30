#ifndef ANALIZA_ACTE_H
#define ANALIZA_ACTE_H

#include <iostream>
#include "DetectieRadar.h"
#include "RezultatTestareAlcoolemie.h"
#include "CarteIdentitate.h"
#include "Permis.h"
#include "Talon.h"
#include "SpecificatiiAutovehicul.h"
#include "Joc.h"

class AnalizaActe {
private:
    DetectieRadar detectieRadar;
    RezultatTestareAlcoolemie alcolemie;
    CarteIdentitate buletin;
    Permis permis;
    Talon talon;
    SpecificatiiAutovehicul masina;

public:
    AnalizaActe(const DetectieRadar &detectie_radar, const RezultatTestareAlcoolemie &alcolemie,
                const CarteIdentitate &buletin, const Permis &permis, const Talon &talon,
                const SpecificatiiAutovehicul &masina);

    bool esteCorectRaspunsul(int raspuns);

    friend std::ostream &operator<<(std::ostream &os, const AnalizaActe &p);

private:
    bool suntDatelePersonaleIdentice();
    bool esteCorespunzatorPermisulPentruAutoturism();
    bool coincideTalonCuMasina();
};

#endif // ANALIZA_ACTE_H
