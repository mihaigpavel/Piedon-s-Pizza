#include "DatePersonale.h"

DatePersonale::DatePersonale(const std::string &nume, const std::string &prenume, const std::string &cnp,
                             const std::string &data_nastere,const std::string &sex)
    : nume(nume),
      prenume(prenume),
      cnp(cnp),
      dataNastere(data_nastere),
      sex(sex) {
}

DatePersonale::DatePersonale(const std::string &nume, const std::string &prenume)
    : nume(nume),
      prenume(prenume) {
}

const std::string &DatePersonale::get_nume() const {
    return nume;
}

const std::string &DatePersonale::get_prenume() const {
    return prenume;
}

const std::string &DatePersonale::get_cnp() const {
    return cnp;
}

const std::string &DatePersonale::get_data_nastere() const {
    return dataNastere;
}

const std::string &DatePersonale::get_sex() const {
    return sex;
}

std::ostream &operator<<(std::ostream &os, const DatePersonale &obj) {
    os << "Nume: " << obj.nume << '\n';
    os << "Prenume: " << obj.prenume << '\n';
    os << "Cnp: " << obj.cnp << '\n';
    os << "Data nastere: " << obj.dataNastere << '\n';
    return os;
}
