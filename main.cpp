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
#include "Permis.h"
#include "RezultatTestareAlcoolemie.h"
#include "SpecificatiiAutovehicul.h"
#include "Talon.h"








class Joc {
    int numarRaspunsuriCorecte = 0;

private:
    void afiseazaRaspunsuriPosibile() {
        std::cout << "Raspunsuri posibile:\n";
        std::cout << "1. Fara sanctiune\n";
        std::cout << "2. Contraventie(amenda)\n";
        std::cout << "3. Retinere permis + amenda\n";
        std::cout << "4. Retinere permis +dosar penal\n";
        std::cout << "5. Retinere Certificat de inmatriculare + amenda\n";
    }

    AnalizaActe construiesteInformatii1() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        // Autovehicul detectat de radar (număr valid, tip compatibil cu categoria B)
        SpecificatiiAutovehicul autDetectieRadar("CJ01XYZ");
        DetectieRadar detectie(autDetectieRadar, 65, "oras");

        // Date personale pentru alcoolemie
        DatePersonale persAlcoolTest("Ionescu", "Andrei");
        RezultatTestareAlcoolemie rez(persAlcoolTest, 0.0);

        // Carte de identitate
        DatePersonale persCi("Ionescu", "Andrei", "1800901123456", "01.09.1980", 'M');
        Document docCi("15.03.2018", "15.03.2028", "SPCLEP Cluj", "CJ123456", "CJ");
        Adresa adresaNastere("CJ", "Cluj-Napoca");
        Adresa adresaCi("Cluj-Napoca", "CJ", "Cluj-Napoca", "Strada Unirii", "5", "A", "10");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romana / ROU");

        // Permis categoria B valabil
        Document docPermis("10.06.2017", "10.06.2027", "SRPCIV Cluj");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        // Talon cu date valide și compatibile
        Document docTalon("20.02.2019", "20.02.2029", "SPCLEP Cluj", "CJ200123");
        SpecificatiiAutovehicul autTalon("VF1BB15C524652158", "CJ01XYZ", "Renault", "Clio", "Albastru", "M1", 2017,
                                          1200, 75);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "20.02.2029");

        // Autovehiculul prezent fizic (aceleași date)
        SpecificatiiAutovehicul autPrezentFizic("VF1BB15C524652158", "CJ01XYZ", "Renault", "Clio", "Albastru", "M1",
                                                 2017, 1200, 75);


        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii2() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovehicul autDetectieRadar("B456DEF");
        DetectieRadar detectie(autDetectieRadar, 72, "in afara localitatii");

        DatePersonale persAlcoolTest("Georgescu", "Mihai");
        RezultatTestareAlcoolemie rez(persAlcoolTest, 1.21);

        DatePersonale persCi("Georgescu", "Mihai", "1600523123456", "23.05.1960", 'M');
        Document docCi("01.01.2015", "01.01.2025", "SPCLEP Bucuresti", "B123456", "B");
        Adresa adresaNastere("B", "Bucuresti");
        Adresa adresaCi("Bucuresti", "B", "Sector 1", "Strada Aviatorilor", "12", "1", "5");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romana / ROU");

        Document docPermis("10.10.2018", "10.10.2028", "SPCLEP Bucuresti");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("15.07.2020", "15.07.2030", "SRPCIV Bucuresti", "B200345");
        SpecificatiiAutovehicul autTalon("WVWZZZ1JZYW000002", "B456DEF", "Skoda", "Octavia", "Gri", "M1", 2016, 1400,
                                          105);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "15.07.2030");

        SpecificatiiAutovehicul autPrezentFizic("WVWZZZ1JZYW000002", "B456DEF", "Skoda", "Octavia", "Gri", "M1", 2016,
                                                 1400, 105);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii3() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovehicul autDetectieRadar("IF88MNO");
        DetectieRadar detectie(autDetectieRadar, 50, "in afara localitatii");

        DatePersonale persAlcoolTest("Marin", "Elena");
        RezultatTestareAlcoolemie rez(persAlcoolTest, 0.0);

        DatePersonale persCi("Marin", "Elena", "2891015123456", "15.10.1989", 'F');
        Document docCi("01.03.2016", "01.03.2026", "SPCLEP Ilfov", "IF654321", "IF");
        Adresa adresaNastere("IF", "Ilfov");
        Adresa adresaCi("Otopeni", "IF", "Otopeni", "Strada Aviatiei", "2", "2", "6");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romana / ROU");

        Document docPermis("01.07.2019", "01.07.2029", "SRPCIV Ilfov");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("10.08.2021", "10.08.2031", "SRPCIV Ilfov", "IF876543");
        SpecificatiiAutovehicul autTalon("VF7ABC9HZBJ620123", "IF88MNO", "Peugeot", "208", "Negru", "M1", 2020, 1199,
                                          100);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "10.08.2031");

        SpecificatiiAutovehicul autPrezentFizic("VF7ABC9HZBJ620123", "IF88MNO", "Peugeot", "208", "Roz", "M1", 2020,
                                                 1199, 100);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }


    AnalizaActe construiesteInformatii4() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovehicul autDetectieRadar("CJ22ZZZ");
        DetectieRadar detectie(autDetectieRadar, 120, "autostrada");

        DatePersonale persAlcoolTest("Stan", "Ioana");
        RezultatTestareAlcoolemie rez(persAlcoolTest, 0.0);

        DatePersonale persCi("Stan", "Ioana", "2920306123456", "06.03.1992", 'F');
        Document docCi("01.04.2019", "01.04.2029", "SPCLEP Cluj", "CJ777777", "CJ");
        Adresa adresaNastere("CJ", "Cluj-Napoca");
        Adresa adresaCi("Cluj-Napoca", "CJ", "Cluj", "Str. Memorandumului", "7", "B", "8");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romana / ROU");

        Document docPermis("15.06.2020", "15.06.2030", "SRPCIV Cluj");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("05.05.2021", "05.05.2031", "SRPCIV Cluj", "CJ456789");
        SpecificatiiAutovehicul autTalon("ZFA19900000512345", "CJ22ZZZ", "Fiat", "Punto", "Rosu", "M1", 2015, 1242,
                                          70);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "05.05.2031");

        SpecificatiiAutovehicul autPrezentFizic("ZFA19900000512345", "CJ22ZZZ", "Fiat", "Punto", "Rosu", "M1", 2015,
                                                 1242, 70);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii5() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovehicul autDetectieRadar("TM10VPT");
        DetectieRadar detectie(autDetectieRadar, 90, "autostrada");

        DatePersonale persAlcoolTest("Dumitrescu", "Sorin");
        RezultatTestareAlcoolemie rez(persAlcoolTest, 0.0);

        DatePersonale persCi("Dumitrescu", "Sorin - Adrian", "1850728123456", "28.07.1985", 'M');
        Document docCi("01.09.2016", "01.09.2026", "SPCLEP Timis", "TM998877", "TM");
        Adresa adresaNastere("TM", "Timisoara");
        Adresa adresaCi("Timisoara", "TM", "Timis", "Str. Libertatii", "3", "A", "2");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romana / ROU");

        DatePersonale persPermis("Dumitrescu", "Sorin", "1850728123456", "28.07.1985", 'M');
        Document docPermis("01.01.2017", "01.01.2027", "SRPCIV Timis");
        Permis permis(docPermis, persPermis, "B", adresaNastere);

        Document docTalon("12.12.2018", "12.12.2028", "SRPCIV Timis", "TM321654");
        SpecificatiiAutovehicul autTalon("WAUZZZ8V0JA123456", "TM10VPT", "Audi", "A3", "Alb", "M1", 2018, 1395, 125);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "12.12.2028");

        SpecificatiiAutovehicul autPrezentFizic("WAUZZZ8V0JA123456", "TM10VPT", "Audi", "A3", "Alb", "M1", 2018, 1395,
                                                 125);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

public:
    Joc() {
        std::cout << "Jocul a inceput!\n";
    }

public:
    void start() {
        std::array<AnalizaActe, 5> informatii = {
            construiesteInformatii1(),
            construiesteInformatii2(),
            construiesteInformatii3(),
            construiesteInformatii4(),
            construiesteInformatii5()
        };
        for (int i = 0; i < 5; ++i) {
            std::cout << informatii[i] << '\n';
            afiseazaRaspunsuriPosibile();
            std::cout << "Introduceti cifra corespunzatoare raspunsului corect: ";
            std::string raspuns;
            std::cin >> raspuns;
            if (raspuns == "1" || raspuns == "2" || raspuns == "3" || raspuns == "4" || raspuns == "5") {
                int raspunsInt = std::stoi(raspuns);
                for (int _ = 0; _ <= 100; _++) {
                    std::cout << '\n';
                }
                if (informatii[i].esteRaspunsCorect(raspunsInt)) {
                    std::cout << "Raspuns corect!\n";
                    numarRaspunsuriCorecte++;
                } else {
                    std::cout << "Raspuns gresit!\n";
                }
            } else {
                std::cout << "Raspuns invalid! Trebuiau introduse una din cifrele 1, 2, 3, 4, 5\n";
            }
        }std::cout << "Joc terminat. Numar raspunsuri corecte:" << numarRaspunsuriCorecte << std::endl;
    }

    ~Joc() = default;
};


int main() {
    Joc joc = Joc();
    joc.start();
    return 0;
}
