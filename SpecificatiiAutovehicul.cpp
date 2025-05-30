#include "SpecificatiiAutovehicul.h"

#include "NuEstePozitivEroare.h"

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "NuEsteInTrecutEroare.h"

void SpecificatiiAutovehicul::estePozitiv(int valoare) {
    if (valoare < 0) {
        throw NuEstePozitivEroare("Valoarea primita: " + std::to_string(valoare));
    }
}
void SpecificatiiAutovehicul::esteInTrecut(std::string data) {
    // Parsează data din string
    std::tm tm = {};
    std::istringstream ss(data);
    ss >> std::get_time(&tm, "%d.%m.%Y");

    // Convertește data în timp calendaristic (time_t)
    std::time_t input_time = std::mktime(&tm);

    // Obține data curentă
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // Compară datele
    if (difftime(input_time, current_time) < 0) {
       // std::cout << "Data este in trecut.\n";
    } else {
       // std::cout << "Data NU este in trecut.\n";
        throw NuEsteInTrecutEroare( data);
    }
}

SpecificatiiAutovehicul::SpecificatiiAutovehicul(const std::string &serie_sasiu, const std::string &numar_inmatriculare,
                                                 const std::string &marca,
                                                 const std::string &model, const std::string &culoare, const std::string &tip_autovehicul,
                                                 unsigned int an_fabricatie, unsigned int capacitate_cilindrica, unsigned int putere)
    : serieSasiu(serie_sasiu),
      numarInmatriculare(numar_inmatriculare),
      marca(marca),
      model(model),
      culoare(culoare),
      tipAutovehicul(tip_autovehicul),
      anFabricatie(an_fabricatie),
      capacitateCilindrica(capacitate_cilindrica),
      putere(putere) {
      estePozitiv(putere);
    estePozitiv(an_fabricatie);
}


SpecificatiiAutovehicul::SpecificatiiAutovehicul(const std::string &numar_inmatriculare)
    : numarInmatriculare(numar_inmatriculare) {
}

const std::string &SpecificatiiAutovehicul::get_numar_inmatriculare() const {
    return numarInmatriculare;
}

const std::string &SpecificatiiAutovehicul::get_tip_autovehicul() const {
    return tipAutovehicul;
}

bool operator==(const SpecificatiiAutovehicul &lhs, const SpecificatiiAutovehicul &rhs) {
    return lhs.serieSasiu == rhs.serieSasiu
           && lhs.numarInmatriculare == rhs.numarInmatriculare
           && lhs.marca == rhs.marca
           && lhs.model == rhs.model
           && lhs.culoare == rhs.culoare
           && lhs.tipAutovehicul == rhs.tipAutovehicul
           && lhs.anFabricatie == rhs.anFabricatie
           && lhs.capacitateCilindrica == rhs.capacitateCilindrica
           && lhs.putere == rhs.putere;
}

bool operator!=(const SpecificatiiAutovehicul &lhs, const SpecificatiiAutovehicul &rhs) {
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const SpecificatiiAutovehicul &p) {
    os << "Serie sasiu: " << p.serieSasiu << '\n';
    os << "Numar inmatriculare: " << p.numarInmatriculare << '\n';
    os << "Marca: " << p.marca << '\n';
    os << "Model: " << p.model << '\n';
    os << "Culoare: " << p.culoare << '\n';
    os << "An fabricatie: " << p.anFabricatie << '\n';
    os << "Capacitate cilindre: " << p.capacitateCilindrica << '\n';
    os << "Putere: " << p.putere << '\n';
    os << "Tip autovehicul: " << p.tipAutovehicul << '\n';
    return os;
}
