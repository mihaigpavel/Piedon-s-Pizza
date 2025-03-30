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


    // Destructor
    ~Document() {
        std::cout << "Document deleted" << std::endl;
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
        os << "Data eliberare: " << obj.get_data_eliberare() << '\n';
        os << "Data expirare: " << obj.get_data_expirare() << '\n';
        os << "Emitent: " << obj.get_emitent() << '\n';
        os << "Numar: " << obj.get_numar() << '\n';
        os << "Serie: " << obj.get_serie() << '\n';
        os << "//////////////////////////////////////////////" << '\n';
        return os;
    }
};

class Persoana {
private:
    std::string nume;
    std::string prenume;
    std::string cnp;
    std::string dataNastere;
    char sex = 'M';

public:
    Persoana(const std::string &nume, const std::string &prenume, const std::string &cnp,
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

    [[nodiscard]] char get_sex() const {
        return sex;
    }
    [[nodiscard]] const std::string &get_data_nastere() const {
        return dataNastere;
    }

    friend std::ostream &operator<<(std::ostream &os, const Persoana &obj) {
        os << "//////////////////////////////////////////////" << '\n';
        os << "Nume: " << obj.get_nume() << '\n';
        os << "Prenume: " << obj.get_prenume() << '\n';
        os << "Cnp: " << obj.get_cnp() << '\n';
        os << "Data nastere: " << obj.get_data_nastere() << '\n';
        os << "sex: " << obj.get_sex() << '\n';
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
    Adresa( const std::string &judet, const std::string &judet_prescurtat,
        const std::string &localitate, const std::string &strada, const std::string &numar, const std::string &bloc,
        const std::string &apartament)
        :
          judet(judet),
          judetPrescurtat(judet_prescurtat),
          localitate(localitate),
          strada(strada),
          numar(numar),
          bloc(bloc),
          apartament(apartament) {
    }

    [[nodiscard]] const std::string & get_judet() const {
        return judet;
    }

    [[nodiscard]] const std::string & get_localitate() const {
        return localitate;
    }

    [[nodiscard]] const std::string & get_strada() const {
        return strada;
    }

    [[nodiscard]] const std::string & get_numar() const {
        return numar;
    }

    [[nodiscard]] const std::string & get_bloc() const {
        return bloc;
    }

    [[nodiscard]] const std::string & get_apartament() const {
        return apartament;
    }
    [[nodiscard]] const std::string & get_judet_prescurtat() const {
        return judetPrescurtat;
    }

   friend std:: ostream & operator<<(std::ostream &os, const Adresa &p) {
        os << "Jud." << p.get_judet() << " ";
        os << "Loc." << p.get_localitate() << '\n';
        os << "Str." << p.get_strada() << ' ';
        os << "nr." << p.get_numar() << ' ';
        os << "bl." << p.get_bloc() << ' ';
        os << "ap." << p.get_apartament() << '\n';

        return os;
    }
};

class CarteIdentitate {
    Document document;
    Persoana persoana;
    Adresa adresaDomiciliu;
    Adresa adresaNastere;
  std::string cetatenia;
public:
    CarteIdentitate(const Document &document, const Persoana &persoana, const Adresa &adresa_domiciliu,
        const Adresa &adresa_nastere, const std::string &cetatenia)
        : document(document),
          persoana(persoana),
          adresaDomiciliu(adresa_domiciliu),
          adresaNastere(adresa_nastere),
          cetatenia(cetatenia) {
    }

    [[nodiscard]] const Document & get_document() const {
        return document;
    }

    [[nodiscard]] const Persoana & get_persoana() const {
        return persoana;
    }

    [[nodiscard]] const Adresa & get_adresa_domiciliu() const {
        return adresaDomiciliu;
    }

    [[nodiscard]] const Adresa & get_adresa_nastere() const {
        return adresaNastere;
    }

    [[nodiscard]] const std::string & get_cetatenia() const {
        return cetatenia;
    }

    friend std :: ostream & operator << (std :: ostream & os, const CarteIdentitate & p) {
        os << "////////////////////////////////////////////////////////////////////\n";
        os << "ROUMANIE   " << "ROMANIA   " << "ROMANIA\n";
        os << "              SERIA " << p.get_document().get_serie() << "  NR " << p.get_document().get_numar() << '\n';
        os << "Nume/Nom/Last name\n";
        os << p.get_persoana().get_nume() << '\n';
        os << "Prenume/Prenom/First name\n";
        os << p.get_persoana().get_prenume() << '\n';
        os << "Cetatenie/Nationalite,NAtionality\n" << p.get_cetatenia() << '\n';
        os << "Loc nastere/Lieu de naissance/Place of birth\nJud." <<p.get_adresa_nastere().get_judet() << " Loc." << p.get_adresa_nastere().get_judet_prescurtat() << '\n';
        os << "Domiciliu/Adresse/address\n" << p.get_adresa_domiciliu();
        os << "Emis de/Delivree par/issued by       valabilitate/validite/validity\n";
        os << p.get_document().get_emitent() << "              " << p.get_document().get_data_eliberare()<<"-"<<p.get_document().get_data_expirare() << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;

    }
};

class Permis {
    Document document;
    Persoana persoana;
    std::string categorie;
Adresa adresaNastere;
public:
    Permis(const Document &document, const Persoana &persoana, const std::string &categorie,
        const Adresa &adresa_nastere)
        : document(document),
          persoana(persoana),
          categorie(categorie),
          adresaNastere(adresa_nastere) {
    }

    [[nodiscard]] const Document & get_document() const {
        return document;
    }

    [[nodiscard]] const Persoana & get_persoana() const {
        return persoana;
    }

    [[nodiscard]] const std::string & get_categorie() const {
        return categorie;
    }
    [[nodiscard]] const Adresa & get_adresa_nastere() const {
        return adresaNastere;
    }

    friend std::ostream & operator<<(std::ostream &os, const Permis &p) {
        os << "//////////////////////////////////////////////" << '\n';
        os << "  " << p.get_persoana().get_nume() << '\n';
        os << "  " << p.get_persoana().get_prenume() << '\n';
        os << "  " << p.get_persoana().get_data_nastere() << " "<<p.get_adresa_nastere().get_localitate()<< " "<< p.get_adresa_nastere().get_judet_prescurtat() << '\n';
        os << "  " << p.get_document().get_data_eliberare() << "    "<<p.get_document().get_emitent() << '\n';
        os << "  " << p.get_document().get_data_expirare() << "    " <<p.get_persoana().get_cnp()<< '\n';
        os <<"  "<< p.get_categorie()<< '\n';
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

    [[nodiscard]] const std::string & get_serie_sasiu() const {
        return serieSasiu;
    }

    [[nodiscard]] const std::string & get_numar_inmatriculare() const {
        return numarInmatriculare;
    }

    [[nodiscard]] const std::string & get_marca() const {
        return marca;
    }

    [[nodiscard]] const std::string & get_model() const {
        return model;
    }

    [[nodiscard]] const std::string & get_culoare() const {
        return culoare;
    }

    [[nodiscard]] const std::string & get_tip_autovehicul() const {
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


    friend std::ostream & operator<<(std::ostream &os, const Autovehicul &p) {
        os << "////////////////////////////////////////////////////////////////////\n";
        os << "Serie sasiu: " << p.get_serie_sasiu() << '\n';
        os << "Numar inmatriculare: " << p.get_numar_inmatriculare() << '\n';
        os << "Marca: " << p.get_marca() << '\n';
        os << "Model: " << p.get_model() << '\n';
        os << "Culoare: " << p.get_culoare() << '\n';
        os << "An fabricatie: " << p.get_an_fabricatie() << '\n';
        os << "Capacitate cilindre: " << p.get_capacitate_cilindrica() << '\n';
        os << "Putere: " << p.get_putere() << '\n';
        os << "Tip autovehicul: " << p.get_tip_autovehicul() << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;
    }

};

class Talon {
    Document document;
    Autovehicul autovehicul;
    Persoana proprietar;
    Adresa adresaProprietar;
    std::string DataExpirareItp;

public:
    Talon(const Document &document, const Autovehicul &autovehicul, const Persoana &proprietar,
        const Adresa &adresa_proprietar, const std::string &data_expirare_itp)
        : document(document),
          autovehicul(autovehicul),
          proprietar(proprietar),
          adresaProprietar(adresa_proprietar),
          DataExpirareItp(data_expirare_itp) {
    }

    [[nodiscard]] const Document & get_document() const {
        return document;
    }

    [[nodiscard]] const Autovehicul & get_autovehicul() const {
        return autovehicul;
    }

    [[nodiscard]] const Persoana & get_proprietar() const {
        return proprietar;
    }

    [[nodiscard]] const Adresa & get_adresa_proprietar() const {
        return adresaProprietar;
    }

    [[nodiscard]] const std::string & get_data_expirare_itp() const {
        return DataExpirareItp;
    }

    friend std::ostream & operator<<(std::ostream &os, const Talon &p) {
        os << "////////////////////////////////////////////////////////////////////\n";
        os << "numar inmatriculare: " << p.get_autovehicul().get_numar_inmatriculare() << '\n';
        os << "tipul autovehiculului: " << p.get_autovehicul().get_tip_autovehicul() << '\n';
        os << "marca: " << p.get_autovehicul().get_marca() << '\n';
        os << "model: " << p.get_autovehicul().get_model() << '\n';
        os<< "seria sasiu: " << p.get_autovehicul().get_serie_sasiu() << '\n';
        os << "proprietar: " << p.get_proprietar().get_nume() << ' ' << p.get_proprietar().get_prenume() << '\n';
        os << "adresa: " << p.get_adresa_proprietar();
        os<<"culoarea: " << p.get_autovehicul().get_culoare() << '\n';
        os << "an fabricatie: " << p.get_autovehicul().get_an_fabricatie() << '\n';
        os << "capacitate cilindrica: " << p.get_autovehicul().get_capacitate_cilindrica() << '\n';
        os << "putere: " << p.get_autovehicul().get_putere() << '\n';
        os << "emitarote: " << p.get_document().get_emitent() << '\n';
        os << "data expirare itp: " << p.get_data_expirare_itp() << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;
    }
};


class DetectieRadar {
    Autovehicul autovehicul;
    int vitezaDetectata;
    std:: string locatieDetectie;
    const int vitezaMaxLegalaOras = 50;
    const int vitezaMaxLegalaAutostrada = 130;
    const int vitezaMaxLegalaDn = 90;

public:
    DetectieRadar(const Autovehicul &autovehicul, int viteza_detectata, const std::string &locatie_detectie)
        : autovehicul(autovehicul),
          vitezaDetectata(viteza_detectata),
          locatieDetectie(locatie_detectie) {
    }

    [[nodiscard]] const Autovehicul & get_autovehicul() const {
        return autovehicul;
    }

    [[nodiscard]] int get_viteza_detectata() const {
        return vitezaDetectata;
    }

    [[nodiscard]] const std::string & get_locatie_detectie() const {
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

    friend std::ostream & operator<<(std::ostream &os, const DetectieRadar &p) {
        os << "Detectie Radar\n";
        os << "numar inmatriculare: " << p.get_autovehicul().get_numar_inmatriculare() << '\n';
        os << "Viteza detectata:"<< p.get_viteza_detectata() << '\n';
        os << "Locatie detectie: " << p.get_locatie_detectie() << '\n';
        os << "////////////////////////////////////////////////////////////////////\n";
        return os;
    }

    bool esteDepasireDeViteza() {
        if (locatieDetectie == "oras") {
            return vitezaDetectata > vitezaMaxLegalaOras;
        } else if (locatieDetectie == "autostrada") {
            return vitezaDetectata > vitezaMaxLegalaAutostrada;
        } else if (locatieDetectie == "dn") {
            return vitezaDetectata > vitezaMaxLegalaDn;
        }
        return false;
    }

};
int main() {
    Document doc1("01-01-2023", "01-01-2024", "Emitent1", "123456", "AB");
    std::cout << doc1;
    Persoana mihai("Mihai", "Popescu", "1234567890123", "01-01-2000", 'M');
    std:: cout << mihai;
    Adresa adresa( "Bucuresti", "B", "Bucuresti", "Strada 1", "1", "1", "1");
    std::cout << adresa;
   CarteIdentitate carte(  doc1, mihai, adresa, adresa, "Romania");
    std::cout << carte;
    Permis permis(doc1, mihai, "B", adresa);
    std::cout << permis;
    Autovehicul autov("12345678901234567", "B123ABC", "Dacia", "Logan", "Alb", "Turism", 2020, 1600, 90);
    std::cout << autov;
    Talon t(doc1, autov, mihai, adresa, "01-01-2025");
    std::cout << t;
    return 0;
}
