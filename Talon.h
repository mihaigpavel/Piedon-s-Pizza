#ifndef TALON_H
#define TALON_H

#include <string>
#include <iostream>
#include "Document.h"
#include "SpecificatiiAutovehicul.h"
#include "DatePersonale.h"
#include "Adresa.h"

class Talon: public Document {
private:
    SpecificatiiAutovehicul autovehicul;
    DatePersonale proprietar;
    Adresa adresaProprietar;
    std::string dataExpirareItp;

public:
    Talon(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar, const SpecificatiiAutovehicul &autovehicul, const DatePersonale &proprietar,
          const Adresa &adresa_proprietar, const std::string &data_expirare_itp);

    [[nodiscard]] const SpecificatiiAutovehicul &get_autovehicul() const;

    friend std::ostream &operator<<(std::ostream &os, const Talon &p);
};

#endif // TALON_H
