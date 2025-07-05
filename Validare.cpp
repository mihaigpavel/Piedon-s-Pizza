//
// Created by Mihai on 7/5/2025.
//

#include "Validare.h"
int Validare::numarRaspunsuriValidate = 0;

// cppcheck-suppress unusedFunction

void Validare::adaugaRaspunsCorect() {
    ++numarRaspunsuriValidate;
}
// cppcheck-suppress unusedFunction

int Validare::get_numarRaspunsuriValidate() {
    return numarRaspunsuriValidate;
}