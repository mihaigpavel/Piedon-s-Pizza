#ifndef DETECTIE_RADAR_H
#define DETECTIE_RADAR_H

#include <string>
#include <iostream>
#include "SpecificatiiAutovehicul.h"

class DetectieRadar {
private:
    SpecificatiiAutovehicul autovehicul;
    int vitezaDetectata;
    std::string locatieDetectie;
    const int vitezaMaxLegalaOras = 50;
    const int vitezaMaxLegalaAutostrada = 130;
    const int vitezaMaxLegalaDn = 90;
    const int pragDepasireVitezaRetinerePermis = 50;

    int calculeazaDepasireViteza() const;

public:
    DetectieRadar(const SpecificatiiAutovehicul &autovehicul, int viteza_detectata,
                  const std::string &locatie_detectie);

    bool esteCazRetinerePermis() const;
    bool esteCazAmenda()const;

    friend std::ostream &operator<<(std::ostream &os, const DetectieRadar &p);
};

#endif // DETECTIE_RADAR_H
