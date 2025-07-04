#ifndef PERMIS_H
#define PERMIS_H

#include <string>
#include <iostream>
#include "Document.h"
#include "DatePersonale.h"
#include "Adresa.h"

class Permis  : public Document{
private:
    DatePersonale persoana;
    std::string categorie;
    Adresa adresaNastere;

public:
    Permis(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent, const DatePersonale &persoana, const std::string &categorie,
           const Adresa &adresa_nastere);

    [[nodiscard]] const DatePersonale &get_persoana() const;

    bool esteValidaDataNasterePermisVsCnp()const ;

    bool categorieValida(const std::string &tipAuto) const;

    friend std::ostream &operator<<(std::ostream &os, const Permis &p);
};

#endif // PERMIS_H
