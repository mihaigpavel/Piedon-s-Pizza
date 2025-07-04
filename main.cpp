#include <iostream>
#include <array>
#include <Helper.h>
#include <string.h>
#include <string>

#include "Adresa.h"
#include "AnalizaActe.h"
#include "CarteIdentitate.h"
#include "DatePersonale.h"
#include "DetectieRadar.h"
#include "Document.h"
#include "Joc.h"
#include "JocEroare.h"
#include "Permis.h"
#include "RezultatTestareAlcoolemie.h"
#include "SpecificatiiAutovehicul.h"
#include "Talon.h"
int main() {

    try {
        Joc& joc = Joc::getInstance();
        joc.start();
        return 0;
     } catch (const JocEroare& e) {
         std::cerr << "Eroare: " << e.what() << std::endl;
     }
}
