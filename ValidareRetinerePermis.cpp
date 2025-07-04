#include "ValidareRetinerePermis.h"

bool ValidareRetinerePermis::verifica(const DetectieRadar& radar, const RezultatTestareAlcoolemie& alcoolemie,
                                      const CarteIdentitate&, const Permis&,
                                      const Talon&, const SpecificatiiAutovehicul&) const {
    return radar.esteCazRetinerePermis() || alcoolemie.esteCazDeAmenda();
}

std::shared_ptr<Validare> ValidareRetinerePermis::clone() const {
    return std::make_shared<ValidareRetinerePermis>(*this);
}
