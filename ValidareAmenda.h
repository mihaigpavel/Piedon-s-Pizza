#pragma once
#include "Validare.h"

class ValidareAmenda : public Validare {
public:
    bool verifica(const DetectieRadar&, const RezultatTestareAlcoolemie&,
                  const CarteIdentitate&, const Permis&,
                  const Talon&, const SpecificatiiAutovehicul&) const override;

    std::shared_ptr<Validare> clone() const override;
};
