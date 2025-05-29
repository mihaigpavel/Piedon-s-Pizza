#ifndef JOC_H
#define JOC_H

#include <iostream>
#include <array>
#include <string>
#include "AnalizaActe.h"  // Include toate clasele folosite în construcțiile din construiesteInformatiiX

class Joc {
    int numarRaspunsuriCorecte = 0;

private:
    void afiseazaRaspunsuriPosibile();

    AnalizaActe construiesteInformatii1();
    AnalizaActe construiesteInformatii2();
    AnalizaActe construiesteInformatii3();
    AnalizaActe construiesteInformatii4();
    AnalizaActe construiesteInformatii5();

public:
    Joc();

    void start();

    ~Joc() = default;
};

#endif // JOC_H
