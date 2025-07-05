#include "ValidareRetinereTalon.h"

bool ValidareRetinereTalon::verifica(const DetectieRadar&, const RezultatTestareAlcoolemie&,
                                     const CarteIdentitate&, const Permis&,
                                     const Talon& talon, const SpecificatiiAutovehicul& masina) const {
    return !(masina == talon.get_autovehicul());
}


