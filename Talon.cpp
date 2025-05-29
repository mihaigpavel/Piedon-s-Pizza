#include "Talon.h"

Talon::Talon(const Document &document, const SpecificatiiAutovehicul &autovehicul, const DatePersonale &proprietar,
             const Adresa &adresa_proprietar, const std::string &data_expirare_itp)
    : document(document),
      autovehicul(autovehicul),
      proprietar(proprietar),
      adresaProprietar(adresa_proprietar),
      dataExpirareItp(data_expirare_itp) {
}

const SpecificatiiAutovehicul &Talon::get_autovehicul() const {
    return autovehicul;
}

std::ostream &operator<<(std::ostream &os, const Talon &p) {
    os << "Certificat de inmatriculare\n";
    os << "////////////////////////////////////////////////////////////////////\n";
    os << p.autovehicul << p.proprietar;
    os << "////////////////////////////////////////////////////////////////////\n";
    return os;
}
