#include "Adresa.h"

Adresa::Adresa(const std::string &judet, const std::string &judet_prescurtat,
               const std::string &localitate, const std::string &strada, const std::string &numar,
               const std::string &bloc, const std::string &apartament)
    : judet(judet),
      judetPrescurtat(judet_prescurtat),
      localitate(localitate),
      strada(strada),
      numar(numar),
      bloc(bloc),
      apartament(apartament) {
}

Adresa::Adresa(const std::string &judet_prescurtat, const std::string &localitate)
    : judetPrescurtat(judet_prescurtat),
      localitate(localitate) {
}

const std::string &Adresa::get_localitate() const {
    return localitate;
}

const std::string &Adresa::get_numar() const {
    return numar;
}

const std::string &Adresa::get_judet_prescurtat() const {
    return judetPrescurtat;
}

std::ostream &operator<<(std::ostream &os, const Adresa &p) {
    os << "Jud." << p.judet << " ";
    os << "Loc." << p.localitate << '\n';
    os << "Str." << p.strada << ' ';
    os << "nr." << p.numar << ' ';
    os << "bl." << p.bloc << ' ';
    os << "ap." << p.apartament << '\n';

    return os;
}
