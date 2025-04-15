#include <iostream>
#include <array>
#include <Helper.h>
#include <string>

class Document {
private:
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitent;
    std::string numar;
    std::string serie;

public:
    // constructor
    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar, const std::string &serie)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent),
          numar(numar),
          serie(serie) {
    }

    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent,
             const std::string &numar)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent),
          numar(numar) {
    }

    Document(const std::string &data_eliberare, const std::string &data_expirare, const std::string &emitent)
        : dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent) {
    }

    // Copy constructor and move constructor
    Document(const Document &other)
        : dataEliberare(other.dataEliberare),
          dataExpirare(other.dataExpirare),
          emitent(other.emitent),
          numar(other.numar),
          serie(other.serie) {
    }

    Document(Document &&other) noexcept
        : dataEliberare(std::move(other.dataEliberare)),
          dataExpirare(std::move(other.dataExpirare)),
          emitent(std::move(other.emitent)),
          numar(std::move(other.numar)),
          serie(std::move(other.serie)) {
    }

    Document &operator=(const Document &other) {
        if (this == &other)
            return *this;
        dataEliberare = other.dataEliberare;
        dataExpirare = other.dataExpirare;
        emitent = other.emitent;
        numar = other.numar;
        serie = other.serie;
        return *this;
    }

    Document &operator=(Document &&other) noexcept {
        if (this == &other)
            return *this;
        dataEliberare = std::move(other.dataEliberare);
        dataExpirare = std::move(other.dataExpirare);
        emitent = std::move(other.emitent);
        numar = std::move(other.numar);
        serie = std::move(other.serie);
        return *this;
    }

    [[nodiscard]] const std::string &get_data_eliberare() const {
        return dataEliberare;
    }

    [[nodiscard]] const std::string &get_data_expirare() const {
        return dataExpirare;
    }

    [[nodiscard]] const std::string &get_emitent() const {
        return emitent;
    }

    [[nodiscard]] const std::string &get_numar() const {
        return numar;
    }

    [[nodiscard]] const std::string &get_serie() const {
        return serie;
    }

    friend std::ostream &operator<<(std::ostream &os, const Document &obj) {
        os << "//////////////////////////////////////////////" << '\n';
        os << "Data eliberare: " << obj.dataEliberare << '\n';
        os << "Data expirare: " << obj.dataExpirare << '\n';
        os << "Emitent: " << obj.emitent << '\n';
        os << "Numar: " << obj.numar << '\n';
        os << "Serie: " << obj.serie << '\n';
        os << "//////////////////////////////////////////////" << '\n';
        return os;
    }
};

class DatePersonale {
private:
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string dataNastere;
    char sex = 'M';

public:
    DatePersonale(const std::string &nume, const std::string &prenume, const std::string &cnp,
                  const std::string &data_nastere, char sex)
        : nume(nume),
          prenume(prenume),
          cnp(cnp),
          dataNastere(data_nastere),
          sex(sex) {
    }

    [[nodiscard]] const std::string &get_nume() const {
        return nume;
    }

    [[nodiscard]] const std::string &get_prenume() const {
        return prenume;
    }

    [[nodiscard]] const std::string &get_cnp() const {
        return cnp;
    }
    [[nodiscard]] const std::string &get_data_nastere() const {
        return dataNastere;
    }

    friend std::ostream &operator<<(std::ostream &os, const DatePersonale &obj) {
        os << "//////////////////////////////////////////////" << '\n';
        os << "Nume: " << obj.nume << '\n';
        os << "Prenume: " << obj.prenume<< '\n';
        os << "Cnp: " << obj.cnp << '\n';
        os << "Data nastere: " << obj.dataNastere << '\n';
        os << "sex: " << obj.sex << '\n';
        os << "//////////////////////////////////////////////" << '\n';
        return os;
    }
};

class Adresa {
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
           const std::string &apartament)
        : judet(judet),
          judetPrescurtat(judet_prescurtat),
          localitate(localitate),
          strada(strada),
          numar(numar),
          bloc(bloc),
          apartament(apartament) {
    }

    Adresa(const std::string &judet_prescurtat, const std::string &localitate)
        : judetPrescurtat(judet_prescurtat),
          localitate(localitate) {
    }

    [[nodiscard]] const std::string &get_judet() const {
        return judet;
    }

    [[nodiscard]] const std::string &get_localitate() const {
        return localitate;
    }

    [[nodiscard]] const std::string &get_numar() const {
        return numar;
    }


    [[nodiscard]] const std::string &get_judet_prescurtat() const {
        return judetPrescurtat;
    }

    friend std::ostream &operator<<(std::ostream &os, const Adresa &p) {
        os << "Jud." << p.judet << " ";
        os << "Loc." << p.localitate << '\n';
        os << "Str." << p.strada << ' ';
        os << "nr." << p.numar << ' ';
        os << "bl." << p.bloc << ' ';
        os << "ap." << p.apartament << '\n';

        return os;
    }
};

class CarteIdentitate {
    Document document;
    DatePersonale datePersonale;
    Adresa adresaDomiciliu;
    Adresa adresaNastere;
    std::string cetatenia;

public:
    CarteIdentitate(const Document &document, const DatePersonale &persoana, const Adresa &adresa_domiciliu,
                    const Adresa &adresa_nastere, const std::string &cetatenia)
        : document(document),
          datePersonale(persoana),
          adresaDomiciliu(adresa_domiciliu),
          adresaNastere(adresa_nastere),
          cetatenia(cetatenia) {
    }
    [[nodiscard]] const DatePersonale &get_datePersoanale() const {
        return datePersonale;
    }
    friend std::ostream &operator <<(std::ostream &os, const CarteIdentitate &p) {
        os << "CARTE DE IDENTITATE\n";
        os << "/////////////////////////////////////////////////////////////////\n";
        os << "ROUMANIE                     ROMANIA                     ROMANIA\n";
        os << "SERIA: " << p.document.get_serie() << "     NR: " << p.document.get_numar() << '\n';
        os << "CNP: " << p.datePersonale.get_cnp() << '\n';
        os << "Nume/Nom/Last name\n";
        os << p.datePersonale.get_nume() << '\n';
        os << "Prenume/Prenom/First name\n";
        os << p.datePersonale.get_prenume() << '\n';
        os << "Cetatenie/Nationalite/Nationality\n" << p.cetatenia << '\n';
        os << "Loc nastere/Lieu de naissance/Place of birth\n";
        os << "Jud. " << p.adresaNastere.get_judet_prescurtat() << " Loc. " << p.adresaNastere.get_localitate() << '\n';
        os << "Domiciliu/Adresse/Address\n" << p.adresaDomiciliu;
        os << "Emis de/Delivre par/Issued by      Valabilitate/Validite/Validity\n";
        os << p.document.get_emitent() << "                      "
           << p.document.get_data_eliberare() << " - "
           << p.document.get_data_expirare() << '\n';
        os << "/////////////////////////////////////////////////////////////////\n";
        return os;
    }
};

class Permis {
    Document document;
    DatePersonale persoana;
    std::string categorie;
    Adresa adresaNastere;

public:
    Permis(const Document &document, const DatePersonale &persoana, const std::string &categorie,
           const Adresa &adresa_nastere)
        : document(document),
          persoana(persoana),
          categorie(categorie),
          adresaNastere(adresa_nastere) {
    }

    [[nodiscard]] const DatePersonale &get_persoana() const {
        return persoana;
    }

    bool esteValidaDataNasterePermisVsCnp() {
        const std::string cnp = persoana.get_cnp();
        const std::string dataNastere = persoana.get_data_nastere();
        const std::string anNastere = cnp.substr(1, 2);
        const std::string lunaNastere = cnp.substr(3, 2);
        const std::string ziNastere = cnp.substr(5, 2);
        return dataNastere == ziNastere + "." + lunaNastere + "." + anNastere;
    }

    friend std::ostream &operator<<(std::ostream &os, const Permis &p) {
        os << "Permis sofer\n";
        os << "//////////////////////////////////////////////" << '\n';
        os << "1. " << p.persoana.get_nume() << '\n';
        os << "2. " << p.persoana.get_prenume() << '\n';
        os << "3. " << p.persoana.get_data_nastere() << " " << p.adresaNastere.get_localitate() << ", " << p.
                adresaNastere.get_judet_prescurtat() << '\n';
        os << "4a. " << p.document.get_data_eliberare() << "   4c. " << p.document.get_emitent() << '\n';
        os << "4b. " << p.document.get_data_expirare() << "   4d. " << p.persoana.get_cnp() << '\n';
        os << p.categorie << '\n';
        os << "//////////////////////////////////////////////" << '\n';
        return os;
    }
};

class Autovehicul {
    std::string serieSasiu;
    std::string numarInmatriculare;
    std::string marca;
    std::string model;
    std::string culoare;
    std::string tipAutovehicul;
    unsigned int anFabricatie;
    unsigned int capacitateCilindrica;
    unsigned int putere;

public:
    Autovehicul(const std::string &serie_sasiu, const std::string &numar_inmatriculare, const std::string &marca,
                const std::string &model, const std::string &culoare, const std::string &tip_autovehicul,
                unsigned int an_fabricatie, unsigned int capacitate_cilindrica, unsigned int putere)
        : serieSasiu(serie_sasiu),
          numarInmatriculare(numar_inmatriculare),
          marca(marca),
          model(model),
          culoare(culoare),
          tipAutovehicul(tip_autovehicul),
          anFabricatie(an_fabricatie),
          capacitateCilindrica(capacitate_cilindrica),
          putere(putere) {
    }

    [[nodiscard]] const std::string &get_serie_sasiu() const {
        return serieSasiu;
    }

    [[nodiscard]] const std::string &get_numar_inmatriculare() const {
        return numarInmatriculare;
    }

    [[nodiscard]] const std::string &get_marca() const {
        return marca;
    }

    [[nodiscard]] const std::string &get_model() const {
        return model;
    }

    [[nodiscard]] const std::string &get_culoare() const {
        return culoare;
    }

    [[nodiscard]] const std::string &get_tip_autovehicul() const {
        return tipAutovehicul;
    }

    [[nodiscard]] unsigned int get_an_fabricatie() const {
        return anFabricatie;
    }

    [[nodiscard]] unsigned int get_capacitate_cilindrica() const {
        return capacitateCilindrica;
    }

    [[nodiscard]] unsigned int get_putere() const {
        return putere;
    }


    friend std::ostream &operator<<(std::ostream &os, const Autovehicul &p) {
        os << "Autovehicul\n";
        os << "////////////////////////////////////////////////////////////////////\n";
        os << "Serie sasiu: " << p.serieSasiu << '\n';
        os << "Numar inmatriculare: " << p.numarInmatriculare << '\n';
        os << "Marca: " << p.marca << '\n';
        os << "Model: " << p.model << '\n';
        os << "Culoare: " << p.culoare << '\n';
        os << "An fabricatie: " << p.anFabricatie << '\n';
        os << "Capacitate cilindre: " << p.capacitateCilindrica << '\n';
        os << "Putere: " << p.putere << '\n';
        os << "Tip autovehicul: " << p.tipAutovehicul << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;
    }


};

class Talon {
    Document document;
    Autovehicul autovehicul;
    DatePersonale proprietar;
    Adresa adresaProprietar;
    std::string dataExpirareItp;

public:
    Talon(const Document &document, const Autovehicul &autovehicul, const DatePersonale &proprietar,
          const Adresa &adresa_proprietar, const std::string &data_expirare_itp)
        : document(document),
          autovehicul(autovehicul),
          proprietar(proprietar),
          adresaProprietar(adresa_proprietar),
          dataExpirareItp(data_expirare_itp) {
    }


    friend std::ostream &operator<<(std::ostream &os, const Talon &p) {
        os << "Certificat de inmatriculare\n";
        os << "////////////////////////////////////////////////////////////////////\n";
        os << "Numar inmatriculare: " << p.autovehicul.get_numar_inmatriculare() << '\n';
        os << "Tipul autovehiculului: " << p.autovehicul.get_tip_autovehicul() << '\n';
        os << "Marca: " << p.autovehicul.get_marca() << '\n';
        os << "Model: " << p.autovehicul.get_model() << '\n';
        os << "Seria sasiu: " << p.autovehicul.get_serie_sasiu() << '\n';
        os << "Proprietar: " << p.proprietar.get_nume() << ' ' << p.proprietar.get_prenume() << '\n';
        os << "Adresa: " << p.adresaProprietar;
        os << "Culoarea: " << p.autovehicul.get_culoare() << '\n';
        os << "An fabricatie: " << p.autovehicul.get_an_fabricatie() << '\n';
        os << "Capacitate cilindrica: " << p.autovehicul.get_capacitate_cilindrica() << '\n';
        os << "Putere: " << p.autovehicul.get_putere() << '\n';
        os << "Emitarote: " << p.document.get_emitent() << '\n';
        os << "Data expirare itp: " << p.dataExpirareItp << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;
    }
};


class DetectieRadar {
    Autovehicul autovehicul;
    int vitezaDetectata;
    std::string locatieDetectie;
    const int vitezaMaxLegalaOras = 50;
    const int vitezaMaxLegalaAutostrada = 130;
    const int vitezaMaxLegalaDn = 90;
    const int pragDepasireVitezaRetinerePermis = 50;

    int calculeazaDepasireViteza() {
        if (get_locatie_detectie() == "oras") {
            return get_viteza_detectata() - get_viteza_max_legala_oras();
        } else if (get_locatie_detectie() == "autostrada") {
            return get_viteza_detectata() - get_viteza_max_legala_autostrada();
        } else if (get_locatie_detectie() == "dn") {
            return get_viteza_detectata() - get_viteza_max_legala_dn();
        }
        return 0;
    }

public:
    DetectieRadar(const Autovehicul &autovehicul, int viteza_detectata, const std::string &locatie_detectie)
        : autovehicul(autovehicul),
          vitezaDetectata(viteza_detectata),
          locatieDetectie(locatie_detectie) {
    }



    [[nodiscard]] int get_viteza_detectata() const {
        return vitezaDetectata;
    }

    [[nodiscard]] const std::string &get_locatie_detectie() const {
        return locatieDetectie;
    }

    [[nodiscard]] int get_viteza_max_legala_oras() const {
        return vitezaMaxLegalaOras;
    }

    [[nodiscard]] int get_viteza_max_legala_autostrada() const {
        return vitezaMaxLegalaAutostrada;
    }

    [[nodiscard]] int get_viteza_max_legala_dn() const {
        return vitezaMaxLegalaDn;
    }

    friend std::ostream &operator<<(std::ostream &os, const DetectieRadar &p) {
        os << "Detectie Radar:\n";
        os << "Numar inmatriculare: " << p.autovehicul.get_numar_inmatriculare() << '\n';
        os << "Viteza detectata:" << p.vitezaDetectata << '\n';
        os << "Locatie detectie: " << p.locatieDetectie << '\n';
        return os;
    }

    bool esteCazRetinerePermis() {
        return calculeazaDepasireViteza() > pragDepasireVitezaRetinerePermis;
    }

    bool esteCazAmenda() {
        return calculeazaDepasireViteza() > 0 && calculeazaDepasireViteza() <= pragDepasireVitezaRetinerePermis;
    }
};

class RezultatTestareAlcolemie {
    DatePersonale sofer;
    double alcolemie;
    const double pragDosarPenalAlcolemie = 0.8;

public:
    RezultatTestareAlcolemie(const DatePersonale &sofer, double alcolemie)
        : sofer(sofer),
          alcolemie(alcolemie) {
    }


    [[nodiscard]] double get_alcolemie() const {
        return alcolemie;
    }

    [[nodiscard]] double get_prag_dosar_penal_alcolemie() const {
        return pragDosarPenalAlcolemie;
    }

    bool esteDosarPenal() {
        return alcolemie > get_prag_dosar_penal_alcolemie();
    }

    bool esteCazDeAmenda() {
        return alcolemie > 0.0 && get_alcolemie() <= get_prag_dosar_penal_alcolemie();
    }

    friend std::ostream &operator<<(std::ostream &os, const RezultatTestareAlcolemie &p) {
        os << "Rezultat testare alcolemie:\n";
        os << "Alcolemie: " << p.alcolemie << '\n';
        os << "Nume sofer: " << p.sofer.get_nume() << " " << p.sofer.get_prenume() << '\n';
        return os;
    }
};

class InformatiiAfisiate {
    DetectieRadar detectieRadar;
    RezultatTestareAlcolemie alcolemie;
    CarteIdentitate buletin;
    Permis permis;
    Talon talon;
    Autovehicul masina;

public:
    InformatiiAfisiate(const DetectieRadar &detectie_radar, const RezultatTestareAlcolemie &alcolemie,
                       const CarteIdentitate &buletin, const Permis &permis, const Talon &talon,
                       const Autovehicul &masina)
        : detectieRadar(detectie_radar),
          alcolemie(alcolemie),
          buletin(buletin),
          permis(permis),
          talon(talon),
          masina(masina) {
    }


    [[nodiscard]] const RezultatTestareAlcolemie &get_alcolemie() const {
        return alcolemie;
    }





    bool esteRaspunsCorect(int raspuns) {
        if (detectieRadar.esteCazAmenda() && raspuns == 2) {
            return true;
        }
        if ((detectieRadar.esteCazRetinerePermis() || alcolemie.esteCazDeAmenda()) && raspuns == 3) {
            return true;
        }
        if ((alcolemie.esteDosarPenal() ||
             alcolemie.esteDosarPenal() ||
             !permis.esteValidaDataNasterePermisVsCnp() ||
             !suntDatelePersonaleIdentice()) && raspuns == 4) {
            return true;
        }
        if (!detectieRadar.esteCazAmenda()
            && !detectieRadar.esteCazRetinerePermis()
            && !alcolemie.esteCazDeAmenda()
            && !alcolemie.esteDosarPenal()
            && raspuns == 1) {
            return true;
        }


        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const InformatiiAfisiate &p) {
        os << "Analizati urmatoarele informatii si raspundeti la intrebare\n\n";
        os << p.detectieRadar << '\n';
        os << p.alcolemie << '\n';
        os << p.buletin << '\n';
        os << p.permis << '\n';
        os << p.talon << '\n';
        os << p.masina;
        return os;
    }

private:
    bool suntDatelePersonaleIdentice() {
        return buletin.get_datePersoanale().get_cnp() == permis.get_persoana().get_cnp()
               && buletin.get_datePersoanale().get_nume() == permis.get_persoana().get_nume()
               && buletin.get_datePersoanale().get_prenume() == permis.get_persoana().get_prenume();
    }
};

class Joc {
    int numarRaspunsuriCorecte = 0;

private:
    void afiseazaRaspunsuriPosibile() {
        std::cout << "Raspunsuri posibile:\n";
        std::cout << "1. Fara sanctiune\n";
        std::cout << "2. Contraventie(amenda)\n";
        std::cout << "3. Retinere permis + amenda\n";
        std::cout << "4. Retinere permis +dosar penal\n";
    }

    InformatiiAfisiate construiesteInformatii1() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        Autovehicul autDetectieRadar("", "B123ABC", "", "", "", "", 0, 0, 0);
        DetectieRadar detectie(autDetectieRadar, 70, "oras");

        DatePersonale persCi("Popescu", "Ion", "1234567890123", "01.01.2000", 'M');
        RezultatTestareAlcolemie rez(persCi, 0.0);

        Document docCi("01.01.2021", "01.01.2025", "SPCLEP Constanta", "901123", "AB");
        Adresa adresaNastere("Constanta", "ct");
        Adresa adresaCi("Constanta", "CT", "Constanta", "Strada 1", "1", "1", "1");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romania");


        Document docPermis("01.01.2021", "01.01.2025", "SPCLEP Constanta");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("01.01.2021", "01.01.2025", "SPCLEP Constanta", "L10002212");
        Autovehicul autTalon("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "01.01.2025");
        Autovehicul autPrezentFizic("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);

        return InformatiiAfisiate(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    InformatiiAfisiate construiesteInformatii2() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        Autovehicul autDetectieRadar("", "B123ABC", "", "", "", "", 0, 0, 0);
        DetectieRadar detectie(autDetectieRadar, 70, "oras");

        DatePersonale persCi("Popescu", "Ion", "1234567890123", "01.01.2000", 'M');
        RezultatTestareAlcolemie rez(persCi, 0.0);

        Document docCi("01.01.2021", "01.01.2025", "SPCLEP Constanta", "901123", "AB");
        Adresa adresaNastere("Constanta", "ct");
        Adresa adresaCi("Constanta", "CT", "Constanta", "Strada 1", "1", "1", "1");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romania");


        Document docPermis("01.01.2021", "01.01.2025", "SPCLEP Constanta");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("01.01.2021", "01.01.2025", "SPCLEP Constanta", "L10002212");
        Autovehicul autTalon("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "01.01.2025");
        Autovehicul autPrezentFizic("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);

        return InformatiiAfisiate(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    InformatiiAfisiate construiesteInformatii3() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        Autovehicul autDetectieRadar("", "B123ABC", "", "", "", "", 0, 0, 0);
        DetectieRadar detectie(autDetectieRadar, 70, "oras");

        DatePersonale persCi("Popescu", "Ion", "1234567890123", "01.01.2000", 'M');
        RezultatTestareAlcolemie rez(persCi, 0.0);

        Document docCi("01.01.2021", "01.01.2025", "SPCLEP Constanta", "901123", "AB");
        Adresa adresaNastere("Constanta", "ct");
        Adresa adresaCi("Constanta", "CT", "Constanta", "Strada 1", "1", "1", "1");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romania");


        Document docPermis("01.01.2021", "01.01.2025", "SPCLEP Constanta");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("01.01.2021", "01.01.2025", "SPCLEP Constanta", "L10002212");
        Autovehicul autTalon("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "01.01.2025");
        Autovehicul autPrezentFizic("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);

        return InformatiiAfisiate(detectie, rez, ci, permis, talon, autPrezentFizic);
    }


    InformatiiAfisiate construiesteInformatii4() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        Autovehicul autDetectieRadar("", "B123ABC", "", "", "", "", 0, 0, 0);
        DetectieRadar detectie(autDetectieRadar, 70, "oras");

        DatePersonale persCi("Popescu", "Ion", "1234567890123", "01.01.2000", 'M');
        RezultatTestareAlcolemie rez(persCi, 0.0);

        Document docCi("01.01.2021", "01.01.2025", "SPCLEP Constanta", "901123", "AB");
        Adresa adresaNastere("Constanta", "ct");
        Adresa adresaCi("Constanta", "CT", "Constanta", "Strada 1", "1", "1", "1");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romania");


        Document docPermis("01.01.2021", "01.01.2025", "SPCLEP Constanta");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("01.01.2021", "01.01.2025", "SPCLEP Constanta", "L10002212");
        Autovehicul autTalon("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "01.01.2025");
        Autovehicul autPrezentFizic("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);

        return InformatiiAfisiate(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    InformatiiAfisiate construiesteInformatii5() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        Autovehicul autDetectieRadar("", "B123ABC", "", "", "", "", 0, 0, 0);
        DetectieRadar detectie(autDetectieRadar, 70, "oras");

        DatePersonale persCi("Popescu", "Ion", "1234567890123", "01.01.2000", 'M');
        RezultatTestareAlcolemie rez(persCi, 0.0);

        Document docCi("01.01.2021", "01.01.2025", "SPCLEP Constanta", "901123", "AB");
        Adresa adresaNastere("Constanta", "ct");
        Adresa adresaCi("Constanta", "CT", "Constanta", "Strada 1", "1", "1", "1");
        CarteIdentitate ci(docCi, persCi, adresaCi, adresaNastere, "Romania");


        Document docPermis("01.01.2021", "01.01.2025", "SPCLEP Constanta");
        Permis permis(docPermis, persCi, "B", adresaNastere);

        Document docTalon("01.01.2021", "01.01.2025", "SPCLEP Constanta", "L10002212");
        Autovehicul autTalon("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "01.01.2025");
        Autovehicul autPrezentFizic("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);

        return InformatiiAfisiate(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

public:
    Joc() {
        std::cout << "Jocul a inceput!\n";
    }

public:
    void start() {
        InformatiiAfisiate informatii[5] = {
            construiesteInformatii1(),
            construiesteInformatii2(),
            construiesteInformatii3(),
            construiesteInformatii4(),
            construiesteInformatii5()
        };
        for (int i = 0; i < 5; ++i) {
            std::cout << informatii[i] << '\n';
            afiseazaRaspunsuriPosibile();
            std::cout << "Alegeti un raspuns: ";
            std :: string raspuns;
            std::cin >> raspuns;
                if (raspuns == "1" || raspuns == "2" || raspuns == "3" || raspuns == "4") {

                    int raspunsInt = std::stoi(raspuns);
                    if (informatii[i].esteRaspunsCorect(raspunsInt)) {
                        std::cout << "Raspuns corect!\n";
                        numarRaspunsuriCorecte++;
                    } else {
                        std::cout << "Raspuns gresit!\n";
                    }
                } else {
                    std::cout << "Raspuns invalid!Trebuiau introduse una din cifrele 1,2,3,4\n";
                }

        }
    }

    // Destructor
    ~Joc() {
        std::cout << "Joc terminat.Numar raspunsuri corecte:" << numarRaspunsuriCorecte << std::endl;
    }
};

int main() {
    Joc joc = Joc();
    joc.start();
    return 0;
}
