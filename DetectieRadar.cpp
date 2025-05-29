#include "DetectieRadar.h"

DetectieRadar::DetectieRadar(const SpecificatiiAutovehicul &autovehicul, int viteza_detectata,
                             const std::string &locatie_detectie)
    : autovehicul(autovehicul),
      vitezaDetectata(viteza_detectata),
      locatieDetectie(locatie_detectie) {
}

int DetectieRadar::calculeazaDepasireViteza() {
    if (locatieDetectie == "oras") {
        return vitezaDetectata - vitezaMaxLegalaOras;
    } else if (locatieDetectie == "autostrada") {
        return vitezaDetectata - vitezaMaxLegalaAutostrada;
    } else if (locatieDetectie == "in afara localitatii") {
        return vitezaDetectata - vitezaMaxLegalaDn;
    }
    return 0;
}

bool DetectieRadar::esteCazRetinerePermis() {
    return calculeazaDepasireViteza() > pragDepasireVitezaRetinerePermis;
}

bool DetectieRadar::esteCazAmenda() {
    int depasire = calculeazaDepasireViteza();
    return depasire > 0 && depasire <= pragDepasireVitezaRetinerePermis;
}

std::ostream &operator<<(std::ostream &os, const DetectieRadar &p) {
    os << "Detectie Radar:\n";
    os << "Numar inmatriculare: " << p.autovehicul.get_numar_inmatriculare() << '\n';
    os << "Viteza detectata: " << p.vitezaDetectata << '\n';
    os << "Locatie detectie: " << p.locatieDetectie << '\n';
    return os;
}
