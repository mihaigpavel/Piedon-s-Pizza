#include "ValidareAmenda.h"

bool ValidareAmenda::verifica(const DetectieRadar& radar, const RezultatTestareAlcoolemie&,
                              const CarteIdentitate&, const Permis&,
                              const Talon&, const SpecificatiiAutovehicul&) const {
    return radar.esteCazAmenda();
}

std::shared_ptr<Validare> ValidareAmenda::clone() const {
    return std::make_shared<ValidareAmenda>(*this);
}
