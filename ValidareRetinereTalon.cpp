#include "ValidareRetinereTalon.h"

bool ValidareRetinereTalon::verifica(const DetectieRadar&, const RezultatTestareAlcoolemie&,
                                     const CarteIdentitate&, const Permis&,
                                     const Talon& talon, const SpecificatiiAutovehicul& masina) const {
    return !(masina == talon.get_autovehicul());
}

std::shared_ptr<Validare> ValidareRetinereTalon::clone() const {
    return std::make_shared<ValidareRetinereTalon>(*this);
}
