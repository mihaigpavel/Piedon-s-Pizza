#ifndef ADRESA_H
#define ADRESA_H

#include <string>
#include <iostream>

class Adresa {
private:
    std::string judet;
    std::string judetPrescurtat;
    std::string localitate;
    std::string strada;
    std::string numar;
    std::string bloc;
    std::string apartament;

public:
    Adresa(const std::string &judet, const std::string &judet_prescurtat,
           const std::string &localitate, const std::string &strada, const std::string &numar, const std::string &bloc,
           const std::string &apartament);

    Adresa(const std::string &judet_prescurtat, const std::string &localitate);

    [[nodiscard]] const std::string &get_localitate() const;
    [[nodiscard]] const std::string &get_numar() const;
    [[nodiscard]] const std::string &get_judet_prescurtat() const;

    friend std::ostream &operator<<(std::ostream &os, const Adresa &p);
};

#endif // ADRESA_H
