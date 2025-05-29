#include <iostream>
#include <array>
#include <Helper.h>
#include <string.h>
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

    DatePersonale(const std::string &nume, const std::string &prenume)
        : nume(nume),
          prenume(prenume) {
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
        os << "Prenume: " << obj.prenume << '\n';
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
        os << "SERIA " << p.document.get_serie() << "     NR " << p.document.get_numar() << '\n';
        os << "CNP " << p.datePersonale.get_cnp() << '\n';
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
        const std::string& cnp = persoana.get_cnp();
        const std::string& dataNastere = persoana.get_data_nastere();
        char sexSiSecol = cnp[0];
        std::string an = cnp.substr(1, 2);
        std::string luna = cnp.substr(3, 2);
        std::string zi = cnp.substr(5, 2);
        std::string secol;
        switch (sexSiSecol) {
            case '1': case '2': secol = "19"; break;  // 1900-1999
            case '3': case '4': secol = "18"; break;  // 1800-1899
            case '5': case '6': secol = "20"; break;  // 2000-2099
            default: return false;  // Cod S invalid
        }

        std::string dataDinCnp = zi + "." + luna + "." + secol + an;
        return dataDinCnp == dataNastere;
    }

public:
    bool categorieValida(const std::string &tipAuto) {
        const std::string tipB = "M1N1O1O2";
        const std::string tipC = "N2N3O3O4";
        const std::string tipD = "M2M3";
        if (categorie.contains("B") and
            tipB.contains(tipAuto)) {
            return true;
        }
        if (categorie.contains("C") and
            tipC.contains(tipAuto)) {
            return true;
        }
        if (categorie.contains("D") and
            tipD.contains(tipAuto)
        ) {
            return true;
        }
        return false;
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

class SpecificatiiAutovechivul {
    std::string serieSasiu;
    std::string numarInmatriculare;
    std::string marca;
    std::string model;
    std::string culoare;
    std::string tipAutovehicul;
    unsigned int anFabricatie = 0;
    unsigned int capacitateCilindrica = 0;
    unsigned int putere = 0;

public:
    SpecificatiiAutovechivul(const std::string &serie_sasiu, const std::string &numar_inmatriculare,
                             const std::string &marca,
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

    explicit SpecificatiiAutovechivul(const std::string &numar_inmatriculare)
        : numarInmatriculare(numar_inmatriculare) {
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

    friend bool operator==(const SpecificatiiAutovechivul &lhs, const SpecificatiiAutovechivul &rhs) {
        return lhs.serieSasiu == rhs.serieSasiu
               && lhs.numarInmatriculare == rhs.numarInmatriculare
               && lhs.marca == rhs.marca
               && lhs.model == rhs.model
               && lhs.culoare == rhs.culoare
               && lhs.tipAutovehicul == rhs.tipAutovehicul
               && lhs.anFabricatie == rhs.anFabricatie
               && lhs.capacitateCilindrica == rhs.capacitateCilindrica
               && lhs.putere == rhs.putere;
    }

    friend bool operator!=(const SpecificatiiAutovechivul &lhs, const SpecificatiiAutovechivul &rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream &operator<<(std::ostream &os, const SpecificatiiAutovechivul &p) {
        os << "Autovehicul oprit la control\n";
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
    SpecificatiiAutovechivul autovehicul;
    DatePersonale proprietar;
    Adresa adresaProprietar;
    std::string dataExpirareItp;

public:
    Talon(const Document &document, const SpecificatiiAutovechivul &autovehicul, const DatePersonale &proprietar,
          const Adresa &adresa_proprietar, const std::string &data_expirare_itp)
        : document(document),
          autovehicul(autovehicul),
          proprietar(proprietar),
          adresaProprietar(adresa_proprietar),
          dataExpirareItp(data_expirare_itp) {
    }

    [[nodiscard]] const SpecificatiiAutovechivul &get_autovehicul() const {
        return autovehicul;
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
    SpecificatiiAutovechivul autovehicul;
    int vitezaDetectata;
    std::string locatieDetectie;
    const int vitezaMaxLegalaOras = 50;
    const int vitezaMaxLegalaAutostrada = 130;
    const int vitezaMaxLegalaDn = 90;
    const int pragDepasireVitezaRetinerePermis = 50;

    int calculeazaDepasireViteza() {
        if (locatieDetectie== "oras") {
            return vitezaDetectata - vitezaMaxLegalaOras;
        } else if (locatieDetectie== "autostrada") {
            return vitezaDetectata - vitezaMaxLegalaAutostrada;
        } else if (locatieDetectie== "in afara localitatii") {
            return vitezaDetectata - vitezaMaxLegalaDn;
        }
        return 0;
    }

public:
    DetectieRadar(const SpecificatiiAutovechivul &autovehicul, int viteza_detectata,
                  const std::string &locatie_detectie)
        : autovehicul(autovehicul),
          vitezaDetectata(viteza_detectata),
          locatieDetectie(locatie_detectie) {
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

class RezultatTestareAlcoolemie {
    DatePersonale sofer;
    double alcolemie;
    const double pragDosarPenalAlcolemie = 0.8;

public:
    RezultatTestareAlcoolemie(const DatePersonale &sofer, double alcolemie)
        : sofer(sofer),
          alcolemie(alcolemie) {
    }


    bool esteDosarPenal() {
        return alcolemie > pragDosarPenalAlcolemie;
    }

    bool esteCazDeAmenda() {
        return alcolemie > 0.0 && alcolemie <=  pragDosarPenalAlcolemie;
    }

    friend std::ostream &operator<<(std::ostream &os, const RezultatTestareAlcoolemie &p) {
        os << "Rezultat testare alcolemie:\n";
        os << "Alcolemie: " << p.alcolemie << '\n';
        os << "Nume sofer: " << p.sofer.get_nume() << " " << p.sofer.get_prenume() << '\n';
        return os;
    }
};

class AnalizaActe {
    DetectieRadar detectieRadar;
    RezultatTestareAlcoolemie alcolemie;
    CarteIdentitate buletin;
    Permis permis;
    Talon talon;
    SpecificatiiAutovechivul masina;

public:
    AnalizaActe(const DetectieRadar &detectie_radar, const RezultatTestareAlcoolemie &alcolemie,
                const CarteIdentitate &buletin, const Permis &permis, const Talon &talon,
                const SpecificatiiAutovechivul &masina)
        : detectieRadar(detectie_radar),
          alcolemie(alcolemie),
          buletin(buletin),
          permis(permis),
          talon(talon),
          masina(masina) {
    }

    bool esteRaspunsCorect(int raspuns) {
        if (detectieRadar.esteCazAmenda() && raspuns == 2) {
            return true;
        }
        if ((detectieRadar.esteCazRetinerePermis() || alcolemie.esteCazDeAmenda()) && raspuns == 3) {
            return true;
        }
        if ((alcolemie.esteDosarPenal() ||
             !permis.esteValidaDataNasterePermisVsCnp() ||
             !suntDatelePersonaleIdentice() ||
             !esteCorespunzatorPermisulPentruAutoturism()) && raspuns == 4) {
            return true;
        }
        if (!detectieRadar.esteCazAmenda()
            && !detectieRadar.esteCazRetinerePermis()
            && !alcolemie.esteCazDeAmenda()
            && !alcolemie.esteDosarPenal()
            && permis.esteValidaDataNasterePermisVsCnp()
            && suntDatelePersonaleIdentice()
            && esteCorespunzatorPermisulPentruAutoturism()
            && coincideTalonCuMasina() &&
            raspuns == 1) {
            return true;
        }
        if (!coincideTalonCuMasina() && raspuns == 5) {
            return true;
        }
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const AnalizaActe &p) {
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

private:
    bool esteCorespunzatorPermisulPentruAutoturism() {
        return permis.categorieValida(talon.get_autovehicul().get_tip_autovehicul());
    }

    bool coincideTalonCuMasina() {
      return masina ==talon.get_autovehicul();
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
        std::cout << "5. Retinere Certificat de inmatriculare + amenda\n";
    }

    AnalizaActe construiesteInformatii1() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        // Autovehicul detectat de radar (număr valid, tip compatibil cu categoria B)
        SpecificatiiAutovechivul autDetectieRadar("CJ01XYZ");
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
        SpecificatiiAutovechivul autTalon("VF1BB15C524652158", "CJ01XYZ", "Renault", "Clio", "Albastru", "M1", 2017,
                                          1200, 75);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "20.02.2029");

        // Autovehiculul prezent fizic (aceleași date)
        SpecificatiiAutovechivul autPrezentFizic("VF1BB15C524652158", "CJ01XYZ", "Renault", "Clio", "Albastru", "M1",
                                                 2017, 1200, 75);


        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii2() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovechivul autDetectieRadar("B456DEF");
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
        SpecificatiiAutovechivul autTalon("WVWZZZ1JZYW000002", "B456DEF", "Skoda", "Octavia", "Gri", "M1", 2016, 1400,
                                          105);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "15.07.2030");

        SpecificatiiAutovechivul autPrezentFizic("WVWZZZ1JZYW000002", "B456DEF", "Skoda", "Octavia", "Gri", "M1", 2016,
                                                 1400, 105);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii3() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovechivul autDetectieRadar("IF88MNO");
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
        SpecificatiiAutovechivul autTalon("VF7ABC9HZBJ620123", "IF88MNO", "Peugeot", "208", "Negru", "M1", 2020, 1199,
                                          100);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "10.08.2031");

        SpecificatiiAutovechivul autPrezentFizic("VF7ABC9HZBJ620123", "IF88MNO", "Peugeot", "208", "Roz", "M1", 2020,
                                                 1199, 100);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }


    AnalizaActe construiesteInformatii4() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovechivul autDetectieRadar("CJ22ZZZ");
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
        SpecificatiiAutovechivul autTalon("ZFA19900000512345", "CJ22ZZZ", "Fiat", "Punto", "Rosu", "M1", 2015, 1242,
                                          70);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "05.05.2031");

        SpecificatiiAutovechivul autPrezentFizic("ZFA19900000512345", "CJ22ZZZ", "Fiat", "Punto", "Rosu", "M1", 2015,
                                                 1242, 70);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

    AnalizaActe construiesteInformatii5() {
        // trebuiesc create detectiile radar , detectie alcolemie
        // trebuiesc create documentele care se prezinta la control
        // trebuie creat informatii despre autovechiculul prezent fizic la control
        SpecificatiiAutovechivul autDetectieRadar("TM10VPT");
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
        SpecificatiiAutovechivul autTalon("WAUZZZ8V0JA123456", "TM10VPT", "Audi", "A3", "Alb", "M1", 2018, 1395, 125);
        Talon talon(docTalon, autTalon, persCi, adresaCi, "12.12.2028");

        SpecificatiiAutovechivul autPrezentFizic("WAUZZZ8V0JA123456", "TM10VPT", "Audi", "A3", "Alb", "M1", 2018, 1395,
                                                 125);

        return AnalizaActe(detectie, rez, ci, permis, talon, autPrezentFizic);
    }

public:
    Joc() {
        std::cout << "Jocul a inceput!\n";
    }

public:
    void start() {
        AnalizaActe informatii[5] = {
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
        }
    }

    // Destructor
    ~Joc() {
        std::cout << "Joc terminat. Numar raspunsuri corecte:" << numarRaspunsuriCorecte << std::endl;
    }
};

int main() {
    Joc joc = Joc();
    joc.start();
    return 0;
}
