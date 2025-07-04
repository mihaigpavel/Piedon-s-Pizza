#include "RezultatTestareAlcoolemie.h"

RezultatTestareAlcoolemie::RezultatTestareAlcoolemie(const DatePersonale &sofer, double alcolemie)
    : sofer(sofer), alcolemie(alcolemie) {
}

bool RezultatTestareAlcoolemie::esteDosarPenal() const{
    return alcolemie > pragDosarPenalAlcolemie;
}

bool RezultatTestareAlcoolemie::esteCazDeAmenda() const{
    return alcolemie > 0.0 && alcolemie <= pragDosarPenalAlcolemie;
}

std::ostream &operator<<(std::ostream &os, const RezultatTestareAlcoolemie &p) {
    os << "Rezultat testare alcolemie:\n";
    os << "Alcolemie: " << p.alcolemie << '\n';
    os << "Nume sofer: " << p.sofer.get_nume() << " " << p.sofer.get_prenume() << '\n';
    return os;
}
