#ifndef CARTEIDENTITATE_H
#define CARTEIDENTITATE_H

#include <string>
#include <iostream>
#include "Document.h"
#include "DatePersonale.h"
#include "Adresa.h"

class CarteIdentitate : public Document {
private:
    DatePersonale datePersonale;
    Adresa adresaDomiciliu;
    Adresa adresaNastere;
    std::string cetatenia;

public:
    CarteIdentitate(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
                    const std::string &numar, const std::string &serie,
                    const DatePersonale &persoana, const Adresa &adresa_domiciliu,
                    const Adresa &adresa_nastere, const std::string &cetatenia);

    [[nodiscard]] const DatePersonale &get_datePersoanale() const;

    friend std::ostream &operator<<(std::ostream &os, const CarteIdentitate &p);
};

#endif // CARTEIDENTITATE_H
