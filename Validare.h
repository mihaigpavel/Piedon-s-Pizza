#pragma once

#include <memory>
#include "DetectieRadar.h"
#include "RezultatTestareAlcoolemie.h"
#include "CarteIdentitate.h"
#include "Permis.h"
#include "Talon.h"
#include "SpecificatiiAutovehicul.h"

class Validare {
    static int numarRaspunsuriValidate;

public:
    static void adaugaRaspunsCorect() { ++numarRaspunsuriValidate; }
    static int get_numarRaspunsuriValidate() { return numarRaspunsuriValidate; }
    virtual ~Validare() = default;

    virtual bool verifica(const DetectieRadar&, const RezultatTestareAlcoolemie&,
                          const CarteIdentitate&, const Permis&,
                          const Talon&, const SpecificatiiAutovehicul&) const = 0;


};

