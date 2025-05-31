#include "Joc.h"
#include "ext/include/json/json.hpp"
#include <fstream>
#include <vector>

#include "JocEroare.h"
using json = nlohmann::json;

// Constructor
Joc::Joc() {
    std::cout << "Jocul a inceput!\n";
}

void Joc::afiseazaRaspunsuriPosibile() {
    std::cout << "Raspunsuri posibile:\n";
    std::cout << "1. Fara sanctiune\n";
    std::cout << "2. Contraventie(amenda)\n";
    std::cout << "3. Retinere permis + amenda\n";
    std::cout << "4. Retinere permis +dosar penal\n";
    std::cout << "5. Retinere Certificat de inmatriculare + amenda\n";
}
void Joc::esteRaspunsValid(std::pmr::string raspuns) {
    if ( !(raspuns == "1" || raspuns == "2" || raspuns == "3" || raspuns == "4" || raspuns == "5")) {
        throw JocEroare("Raspunsul trebuie sa fie intre 1 si 5.");
    }
}
std::vector<AnalizaActe> Joc::citesteInformatii() {
    std::vector<AnalizaActe> informatii;
    std::fstream file;
    file.open("../data.json", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului." << std::endl;
    } else {
        json data = json::parse(file);
        if (data.contains("joc")) {
            auto joc = data["joc"];
            for (const auto &entry: joc) {
                const auto &radar = entry["detectieRadar"];
                std::string numarInmatriculare = radar["numar_inmatriculare"];
                int viteza = radar["viteza_detectata"];
                std::string locatie = radar["locatie_detectie"];
                SpecificatiiAutovehicul autDetectieRadar(numarInmatriculare);
                DetectieRadar detectie(autDetectieRadar, viteza, locatie);
                const auto &testAlcool = entry["testareAlcoolemie"];
                DatePersonale persAlcoolTest(testAlcool["nume"], testAlcool["prenume"]);
                RezultatTestareAlcoolemie rez(persAlcoolTest, testAlcool["alcoolemie"]);
                const auto &ci = entry["ci"];
                DatePersonale persCi(ci["nume"], ci["prenume"], ci["cnp"], ci["dataNastere"], ci["sex"]);
                Adresa adresaNastere(ci["adresa_nastere"]["judetPrescurtat"], ci["adresa_nastere"]["localitate"]);
                Adresa adresaCi(ci["adresa_domiciliu"]["judet"], ci["adresa_domiciliu"]["judetPrescurtat"],
                                ci["adresa_domiciliu"]["localitate"], ci["adresa_domiciliu"]["strada"],
                                ci["adresa_domiciliu"]["numar"], ci["adresa_domiciliu"]["bloc"],
                                ci["adresa_domiciliu"]["apartament"]);
                CarteIdentitate cidoc(ci["data_eliberare"], ci["data_expirare"], ci["emitent"], ci["numar"],
                                      ci["serie"], persCi, adresaCi, adresaNastere, ci["cetatenia"]);
                const auto &p = entry["permis"];
                DatePersonale persPermis(p["nume"], p["prenume"], p["cnp"], p["dataNastere"], p["sex"]);
                Permis permis(p["data_eliberare"], p["data_expirare"], p["emitent"], persPermis, p["categorie"],
                              adresaNastere);
                const auto &t = entry["talon"];
                const auto &a = t["autovehicul"];
                SpecificatiiAutovehicul autTalon(a["serie_sasiu"], a["numar_inmatriculare"], a["marca"], a["model"],
                                                 a["culoare"], a["tip_autovehicul"], a["an_fabricatie"],
                                                 a["capacitate_cilindrica"], a["putere"]);
                Talon talon(t["data_eliberare"], t["data_expirare"], t["emitent"], t["numar"], autTalon, persCi,
                            adresaCi, t["data_expirare_itp"]);
                const auto &ap = entry["autPrezentFizic"];
                SpecificatiiAutovehicul autPrezentFizic(ap["serie_sasiu"], ap["numar_inmatriculare"], ap["marca"],
                                                        ap["model"],
                                                        ap["culoare"], ap["tip_autovehicul"], ap["an_fabricatie"],
                                                        ap["capacitate_cilindrica"], ap["putere"]);
                AnalizaActe aa(detectie, rez, cidoc, permis, talon, autPrezentFizic);
                informatii.push_back(aa);
            }
        }
    }
    file.close();
    return informatii;
}

void Joc::start() {
    std::vector<AnalizaActe> informatii = citesteInformatii();
    if (!informatii.empty()) {
        for (AnalizaActe &a: informatii) {
            std::cout << a << '\n';
            afiseazaRaspunsuriPosibile();
            std::cout << "Introduceti cifra corespunzatoare raspunsului corect: ";
            std::string raspuns;
            std::cin >> raspuns;
            if (raspuns == "1" || raspuns == "2" || raspuns == "3" || raspuns == "4" || raspuns == "5") {
                int raspunsInt = std::stoi(raspuns);
                for (int _ = 0; _ <= 100; _++) {
                    std::cout << '\n';
                }
                if (a.esteRaspunsCorect(raspunsInt)) {
                    std::cout << "Raspuns corect!\n";
                    numarRaspunsuriCorecte++;
                } else {
                    std::cout << "Raspuns gresit!\n";
                }
            } else {
                std::cout << "Raspuns invalid! Trebuiau introduse una din cifrele 1, 2, 3, 4, 5\n";
            }
        }
        std::cout << "Joc terminat. Numar raspunsuri corecte: " << numarRaspunsuriCorecte << std::endl;
    }
}
