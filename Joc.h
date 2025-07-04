#ifndef JOC_H
#define JOC_H

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "AnalizaActe.h"

class Joc {
    int numarRaspunsuriCorecte = 0;

    Joc();
    Joc(const Joc&) = delete;
    Joc& operator=(const Joc&) = delete;

private:
    void afiseazaRaspunsuriPosibile();
    std::vector<AnalizaActe> citesteInformatii();
    void esteRaspunsValid(std::string);

public:
    static Joc& getInstance();

    void start();

    ~Joc() = default;
};

#endif // JOC_H
