#pragma once
#include "Validare.h"

class ValidareOk : public Validare {
public:
    bool verifica(const DetectieRadar&, const RezultatTestareAlcoolemie&,
                  const CarteIdentitate&, const Permis&,
                  const Talon&, const SpecificatiiAutovehicul&) const override;


};
