#include "CarteIdentitate.h"

CarteIdentitate::CarteIdentitate(const std::string &data_eliberare, const std::string &data_expirare,
                                 const std::string &emitent,
                                 const std::string &numar, const std::string &serie,
                                 const DatePersonale &persoana, const Adresa &adresa_domiciliu,
                                 const Adresa &adresa_nastere, const std::string &cetatenia)
    : Document(data_eliberare, data_expirare, emitent, numar, serie),
      datePersonale(persoana),
      adresaDomiciliu(adresa_domiciliu),
      adresaNastere(adresa_nastere),
      cetatenia(cetatenia) {
}

const DatePersonale &CarteIdentitate::get_datePersoanale() const {
    return datePersonale;
}

std::ostream &operator<<(std::ostream &os, const CarteIdentitate &p) {
    os << "CARTE DE IDENTITATE\n";
    os << "/////////////////////////////////////////////////////////////////\n";
    os << "ROUMANIE                     ROMANIA                     ROMANIA\n";
    os << "SERIA " << p.get_serie() << "     NR " << p.get_numar() << '\n';
    os << "CNP " << p.datePersonale.get_cnp() << '\n';
    os << "Nume/Nom/Last name\n";
    os << p.datePersonale.get_nume() << '\n';
    os << "Prenume/Prenom/First name\n";
    os << p.datePersonale.get_prenume() << '\n';
    os << "Cetatenie/Nationalite/Nationality\n" << p.cetatenia << '\n';
    os << "Sex/Sexe/Sex\n" << p.datePersonale.get_sex() << '\n';
    os << "Loc nastere/Lieu de naissance/Place of birth\n";
    os << "Jud. " << p.adresaNastere.get_judet_prescurtat() << " Loc. " << p.adresaNastere.get_localitate() << '\n';
    os << "Domiciliu/Adresse/Address\n" << p.adresaDomiciliu;
    os << "Emis de/Delivre par/Issued by      Valabilitate/Validite/Validity\n";
    os << p.get_emitent() << "                      "
            << p.get_data_eliberare() << " - "
            << p.get_data_expirare() << '\n';
    os << "/////////////////////////////////////////////////////////////////\n";
    return os;
}
