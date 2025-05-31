#ifndef JOC_H
#define JOC_H

#include <iostream>
#include <array>
#include <string>
#include "AnalizaActe.h"  // Include toate clasele folosite în construcțiile din construiesteInformatiiX
#include <vector>
class Joc {
    int numarRaspunsuriCorecte = 0;

private:
    void afiseazaRaspunsuriPosibile();
    std::vector<AnalizaActe> citesteInformatii();
    void esteRaspunsValid(std::string);
public:
    Joc();

    void start();

    ~Joc() = default;
};

#endif // JOC_H
