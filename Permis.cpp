#include "Permis.h"

#include "SpecificatiiAutovehicul.h"

Permis::Permis(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent, const DatePersonale &persoana, const std::string &categorie,
               const Adresa &adresa_nastere)
    :Document(data_eliberare, data_expirare,emitent),
      persoana(persoana),
      categorie(categorie),
      adresaNastere(adresa_nastere) {
    SpecificatiiAutovehicul::esteInTrecut(data_eliberare);
}

const DatePersonale &Permis::get_persoana() const {
    return persoana;
}

bool Permis::esteValidaDataNasterePermisVsCnp() const {
    const std::string& cnp = persoana.get_cnp();
    const std::string& dataNastere = persoana.get_data_nastere();

    if (cnp.size() < 7) return false; // verificare simplă pentru lungimea CNP-ului

    char sexSiSecol = cnp[0];
    std::string an = cnp.substr(1, 2);
    std::string luna = cnp.substr(3, 2);
    std::string zi = cnp.substr(5, 2);
    std::string secol;

    switch (sexSiSecol) {
        case '1': case '2': secol = "19"; break;  // 1900-1999
        case '3': case '4': secol = "18"; break;  // 1800-1899
        case '5': case '6': secol = "20"; break;  // 2000-2099
        default: return false;  // Cod S invalid
    }

    std::string dataDinCnp = zi + "." + luna + "." + secol + an;
    return dataDinCnp == dataNastere;
}

bool Permis::categorieValida(const std::string &tipAuto) const{
    const std::string tipB = "M1N1O1O2";
    const std::string tipC = "N2N3O3O4";
    const std::string tipD = "M2M3";

    if (categorie.find("B") != std::string::npos && tipB.find(tipAuto) != std::string::npos) {
        return true;
    }
    if (categorie.find("C") != std::string::npos && tipC.find(tipAuto) != std::string::npos) {
        return true;
    }
    if (categorie.find("D") != std::string::npos && tipD.find(tipAuto) != std::string::npos) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Permis &p) {
    os << "Permis sofer\n";
    os << "//////////////////////////////////////////////\n";
    os << p.persoana << "Locul nasteri: " << p.adresaNastere.get_localitate() << ' ' << p.adresaNastere.get_judet_prescurtat() << "\n";
    os << "Categorie: " << p.categorie << '\n';
    os << static_cast<const Document &>(p);
    os << "//////////////////////////////////////////////\n";
    return os;
}
