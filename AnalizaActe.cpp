#include "AnalizaActe.h"

#include "ValidareOk.h"
#include "ValidareAmenda.h"
#include "ValidareRetinerePermis.h"
#include "ValidareDosarPenal.h"
#include "ValidareRetinereTalon.h"

#include <memory>

AnalizaActe::AnalizaActe(const DetectieRadar &detectie_radar, const RezultatTestareAlcoolemie &alcolemie,
                         const CarteIdentitate &buletin, const Permis &permis, const Talon &talon,
                         const SpecificatiiAutovehicul &masina)
    : detectieRadar(detectie_radar),
      alcolemie(alcolemie),
      buletin(buletin),
      permis(permis),
      talon(talon),
      masina(masina) {}
// cppcheck-suppress unusedFunction
bool AnalizaActe::esteRaspunsCorect(int raspuns) {
    std::shared_ptr<Validare> validare;

    switch (raspuns) {
        case 1:
            validare = std::make_shared<ValidareOk>();
        break;
        case 2:
            validare = std::make_shared<ValidareAmenda>();
        break;
        case 3:
            validare = std::make_shared<ValidareRetinerePermis>();
        break;
        case 4:
            validare = std::make_shared<ValidareDosarPenal>();
        break;
        case 5:
            validare = std::make_shared<ValidareRetinereTalon>();
        break;
        default:
            return false;
    }

    return validare->verifica(detectieRadar, alcolemie, buletin, permis, talon, masina);
}

std::ostream &operator<<(std::ostream &os, const AnalizaActe &p) {
    os << "Analizati urmatoarele informatii si raspundeti la intrebare\n\n";
    os << p.detectieRadar << '\n';
    os << p.alcolemie << '\n';
    os << p.buletin << '\n';
    os << p.permis << '\n';
    os << p.talon << '\n';
    os << "Autovehicul oprit la control\n";
    os << "////////////////////////////////////////////////////////////////////\n"
       << p.masina
       << "////////////////////////////////////////////////////////////////////\n";
    return os;
}