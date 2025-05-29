#ifndef SPECIFICATIIAUTOVEHICUL_H
#define SPECIFICATIIAUTOVEHICUL_H

#include <string>
#include <iostream>

class SpecificatiiAutovehicul {
private:
    std::string serieSasiu;
    std::string numarInmatriculare;
    std::string marca;
    std::string model;
    std::string culoare;
    std::string tipAutovehicul;
    unsigned int anFabricatie = 0;
    unsigned int capacitateCilindrica = 0;
    unsigned int putere = 0;

public:
    SpecificatiiAutovehicul(const std::string &serie_sasiu, const std::string &numar_inmatriculare,
                             const std::string &marca,
                             const std::string &model, const std::string &culoare, const std::string &tip_autovehicul,
                             unsigned int an_fabricatie, unsigned int capacitate_cilindrica, unsigned int putere);

    explicit SpecificatiiAutovehicul(const std::string &numar_inmatriculare);

    [[nodiscard]] const std::string &get_numar_inmatriculare() const;
    [[nodiscard]] const std::string &get_tip_autovehicul() const;

    friend bool operator==(const SpecificatiiAutovehicul &lhs, const SpecificatiiAutovehicul &rhs);
    friend bool operator!=(const SpecificatiiAutovehicul &lhs, const SpecificatiiAutovehicul &rhs);

    friend std::ostream &operator<<(std::ostream &os, const SpecificatiiAutovehicul &p);
};

#endif // SPECIFICATIIAUTOVEHICUL_H
