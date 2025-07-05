#ifndef DATEPERSONALE_H
#define DATEPERSONALE_H

#include <string>
#include <iostream>

class DatePersonale {
private:
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string dataNastere;
    std::string sex;

public:
    DatePersonale(const std::string &nume, const std::string &prenume, const std::string &cnp,
                  const std::string &data_nastere, const std::string &sex);

    DatePersonale(const std::string &nume, const std::string &prenume);

    [[nodiscard]] const std::string &get_nume() const;
    [[nodiscard]] const std::string &get_prenume() const;
    [[nodiscard]] const std::string &get_cnp() const;
    [[nodiscard]] const std::string &get_data_nastere() const;
    [[nodiscard]] const std::string &get_sex() const;

    friend std::ostream &operator<<(std::ostream &os, const DatePersonale &obj);
    bool operator==(const DatePersonale& other) const;
    bool operator!=(const DatePersonale& other) const;


};

#endif // DATEPERSONALE_H