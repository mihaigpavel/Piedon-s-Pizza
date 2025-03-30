#include <iostream>
#include <array>

//#include <Helper.h>
#include <string>
class DatePersonale {
    std::string nume;
    std::string prenume;
    std::string orasNastere;
    std::string judetNastere;
    std::string DataObtinere;
    std::string dataExpirare;
    std::string emitator;
    unsigned long long cnp;

public:
    DatePersonale(const std::string &nume, const std::string &prenume, const std::string &oras_nastere,
        const std::string &judet_nastere, const std::string &data_obtinere, const std::string &data_expirare,
        const std::string &emitator, unsigned long long cnp)
        : nume(nume),
          prenume(prenume),
          orasNastere(oras_nastere),
          judetNastere(judet_nastere),
          DataObtinere(data_obtinere),
          dataExpirare(data_expirare),
          emitator(emitator),
          cnp(cnp) {
    }

    ~DatePersonale(){
        std::cout << "DatePersonale deleted" << std::endl;
    }

    DatePersonale(const DatePersonale &other)
        : nume(other.nume),
          prenume(other.prenume),
          orasNastere(other.orasNastere),
          judetNastere(other.judetNastere),
          DataObtinere(other.DataObtinere),
          dataExpirare(other.dataExpirare),
          emitator(other.emitator),
          cnp(other.cnp) {
    }

    DatePersonale(DatePersonale &&other) noexcept
        : nume(std::move(other.nume)),
          prenume(std::move(other.prenume)),
          orasNastere(std::move(other.orasNastere)),
          judetNastere(std::move(other.judetNastere)),
          DataObtinere(std::move(other.DataObtinere)),
          dataExpirare(std::move(other.dataExpirare)),
          emitator(std::move(other.emitator)),
          cnp(other.cnp) {
    }

    DatePersonale & operator=(const DatePersonale &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        prenume = other.prenume;
        orasNastere = other.orasNastere;
        judetNastere = other.judetNastere;
        DataObtinere = other.DataObtinere;
        dataExpirare = other.dataExpirare;
        emitator = other.emitator;
        cnp = other.cnp;
        return *this;
    }

    DatePersonale & operator=(DatePersonale &&other) noexcept {
        if (this == &other)
            return *this;
        nume = std::move(other.nume);
        prenume = std::move(other.prenume);
        orasNastere = std::move(other.orasNastere);
        judetNastere = std::move(other.judetNastere);
        DataObtinere = std::move(other.DataObtinere);
        dataExpirare = std::move(other.dataExpirare);
        emitator = std::move(other.emitator);
        cnp = other.cnp;
        return *this;
    }

    [[nodiscard]] std::string get_nume() const {
        return nume;
    }

    void set_nume(const std::string &nume) {
        this->nume = nume;
    }

    [[nodiscard]] std::string get_prenume() const {
        return prenume;
    }

    void set_prenume(const std::string &prenume) {
        this->prenume = prenume;
    }

    [[nodiscard]] std::string get_oras_nastere() const {
        return orasNastere;
    }

    void set_oras_nastere(const std::string &oras_nastere) {
        orasNastere = oras_nastere;
    }

    [[nodiscard]] std::string get_judet_nastere() const {
        return judetNastere;
    }

    void set_judet_nastere(const std::string &judet_nastere) {
        judetNastere = judet_nastere;
    }

    [[nodiscard]] std::string get_data_obtinere() const {
        return DataObtinere;
    }

    void set_data_obtinere(const std::string &data_obtinere) {
        DataObtinere = data_obtinere;
    }

    [[nodiscard]] std::string get_data_expirare() const {
        return dataExpirare;
    }

    void set_data_expirare(const std::string &data_expirare) {
        dataExpirare = data_expirare;
    }

    [[nodiscard]] std::string get_emitator() const {
        return emitator;
    }

    void set_emitator(const std::string &emitator) {
        this->emitator = emitator;
    }

    [[nodiscard]] unsigned long long get_cnp() const {
        return cnp;
    }

    void set_cnp(const unsigned long long cnp) {
        this->cnp = cnp;
    }

    friend std::ostream & operator<<(std::ostream &os, const DatePersonale &obj);
};

std::ostream & operator<<(std::ostream &os, const DatePersonale &obj) {
    os<<"//////////////////////////////////////////////" << '\n';
    os << "  " << obj.nume << '\n';
    os << "  " << obj.prenume << '\n';
    os << "  " << obj.orasNastere << '\n';
    os << "  " << obj.judetNastere << '\n';
    os << "  " << obj.DataObtinere << '\n';
    os << "  " << obj.dataExpirare << '\n';
    os << "  " << obj.emitator << '\n';
    os << "  " << obj.cnp << '\n';
    os << "//////////////////////////////////////////////" << '\n';
    return os;
}

class Adresa {
    std::string judet;
    std::string oras;
    std::string strada;
    int nr;
    int et;
    int ap;
    int sc;

public:
    Adresa(const std::string &judet, const std::string &oras, const std::string &strada, int nr, int et, int ap, int sc)
        : judet(judet),
          oras(oras),
          strada(strada),
          nr(nr),
          et(et),
          ap(ap),
          sc(sc) {
    }

    [[nodiscard]] std::string get_judet() const {
        return judet;
    }

    [[nodiscard]] std::string get_oras() const {
        return oras;
    }

    [[nodiscard]] std::string get_strada() const {
        return strada;
    }

    [[nodiscard]] int get_nr() const {
        return nr;
    }

    [[nodiscard]] int get_et() const {
        return et;
    }

    [[nodiscard]] int get_ap() const {
        return ap;
    }

    [[nodiscard]] int get_sc() const {
        return sc;
    }
    friend std::ostream & operator<<(std::ostream &os, const Adresa &p);
};
std:: ostream & operator<<(std::ostream &os, const Adresa &p) {
    os << "Jud." << p.judet << " ";
    os << "Oras" << p.oras << '\n';
    os << "Str." << p.strada << ' ';
    os << "nr." << p.nr << ' ';
    if (p.sc != -1) {
        os << "Sc." << p.sc << ' ';
    }
    if (p.et != -1) {
        os << "et." << p.et << ' ';
    }
    if (p.ap != -1) {
        os << "ap." << p.ap << ' ';
    }
    return os;
}
class Buletin {
    DatePersonale dp;
    Adresa adr;
    std::string serie;
    std::string cod;
    std::string cetatenie;
    int CifraControl;
    int nr;

public:
    Buletin(const DatePersonale &dp, const Adresa &adr, const std::string &serie, const std::string &cod,
        const std::string &cetatenie, int cifra_control, int nr)
        : dp(dp),
          adr(adr),
          serie(serie),
          cod(cod),
          cetatenie(cetatenie),
          CifraControl(cifra_control),
          nr(nr) {
    }

    [[nodiscard]] DatePersonale get_dp() const {
        return dp;
    }

    [[nodiscard]] Adresa get_adr() const {
        return adr;
    }

    [[nodiscard]] std::string get_serie() const {
        return serie;
    }

    [[nodiscard]] std::string get_cod() const {
        return cod;
    }

    [[nodiscard]] std::string get_cetatenie() const {
        return cetatenie;
    }

    [[nodiscard]] int get_cifra_control() const {
        return CifraControl;
    }

    [[nodiscard]] int get_nr() const {
        return nr;
    }

    friend std::ostream & operator<<(std::ostream &os, const Buletin &p);
};
std :: ostream & operator << (std :: ostream & os, const Buletin & p) {
    os << "////////////////////////////////////////////////////////////////////";
    os << "ROUMANIE   " << "ROMANIA   " << "ROMANIA\n";
    os << "              SERIA " << p.serie << "  NR " << p.nr << '\n';
    os << "Nume/Nom/Last name\n";
    os << p.dp.get_nume() << '\n';
    os << "Prenume/Prenom/First name\n";
    os << p.dp.get_prenume() << '\n';
    os << "Cetatenie/Nationalite,NAtionality\n" << p.cetatenie << '\n';
    os << "Loc nastere/Lieu de naissance/Place of birth\nJud." << p.dp.get_judet_nastere() << " " << p.dp.get_oras_nastere() << '\n';
    os << "Domiciliu/Adresse/address\n" << p.adr;
    os << "Emis de/Delivree par/issued by       valabilitate/validite/validity\n";
    os << p.dp.get_emitator() << "              " << p.dp.get_data_obtinere()<<"-"<<p.dp.get_data_expirare() << '\n';
    os << p.cod << "   esp   " << p.dp.get_judet_nastere();
    os << "////////////////////////////////////////////////////////////////////";
    return os;

}

class Permis {
    DatePersonale dp;
    std::string categorie;
   const  std::string dataNastere;

public:
    Permis(const DatePersonale &dp, const std::string &categorie, const std::string &data_nastere)
        : dp(dp),
          categorie(categorie),
          dataNastere(data_nastere) {
    }
    [[nodiscard]] DatePersonale get_dp() const {
        return dp;
    }

    [[nodiscard]] std::string get_categorie() const {
        return categorie;
    }

    [[nodiscard]] std::string get_dataNastere() const {
        return dataNastere;
    }

private:
    friend std::ostream & operator<<(std::ostream &os, const Permis &p);
};
std::ostream & operator<<(std::ostream &os, const Permis &p) {
    os << "//////////////////////////////////////////////" << '\n';
    os << "  " << p.dp.get_nume() << '\n';
    os << "  " << p.dp.get_prenume() << '\n';
    os << "  " << p.dataNastere << p.dp.get_oras_nastere() << p.dp.get_judet_nastere() << '\n';
    os << "  " << p.dp.get_data_obtinere() << p.dp.get_emitator() << '\n';
    os << "  " << p.dp.get_data_expirare() << p.dp.get_cnp() << '\n';
    os << "  " << p.categorie << '\n';
    os << "//////////////////////////////////////////////" << '\n';
    return os;
}
class SpecificatiiMasina {
    const std::string serieSasiu;
    std::string numarInmatriculare;
    const std::string marca;
    const std::string model;
    std::string culoare;
    std::string tipAutovehicul;
    unsigned int anFabricatie;
    unsigned int cilindre;
    unsigned int putere;

public:
    SpecificatiiMasina(const std::string &serie_sasiu, const std::string &numar_inmatriculare, const std::string &marca,
        const std::string &model, const std::string &culoare, const std::string &tip_autovehicul,
        unsigned int an_fabricatie, unsigned int cilindre, unsigned int putere)
        : serieSasiu(serie_sasiu),
          numarInmatriculare(numar_inmatriculare),
          marca(marca),
          model(model),
          culoare(culoare),
          tipAutovehicul(tip_autovehicul),
          anFabricatie(an_fabricatie),
          cilindre(cilindre),
          putere(putere) {
    }

    [[nodiscard]] std::string get_serie_sasiu() const {
        return serieSasiu;
    }

    [[nodiscard]] std::string get_numar_inmatriculare() const {
        return numarInmatriculare;
    }

    [[nodiscard]] std::string get_marca() const {
        return marca;
    }

    [[nodiscard]] std::string get_model() const {
        return model;
    }

    [[nodiscard]] std::string get_culoare() const {
        return culoare;
    }

    [[nodiscard]] std::string get_tip_autovehicul() const {
        return tipAutovehicul;
    }

    [[nodiscard]] unsigned int get_an_fabricatie() const {
        return anFabricatie;
    }

    [[nodiscard]] unsigned int get_cilindre() const {
        return cilindre;
    }

    [[nodiscard]] unsigned int get_putere() const {
        return putere;
    }
    friend std::ostream & operator<<(std::ostream &os, const SpecificatiiMasina &p);
};
std::ostream & operator<<(std::ostream &os, const SpecificatiiMasina &p) {
    os << "////////////////////////////////////////////////////////////////////\n";
    os << "Serie sasiu: " << p.serieSasiu << '\n';
    os << "Numar inmatriculare: " << p.numarInmatriculare << '\n';
    os << "Marca: " << p.marca << '\n';
    os << "Model: " << p.model << '\n';
    os << "Culoare: " << p.culoare << '\n';
    os << "An fabricatie: " << p.anFabricatie << '\n';
    os << "cilindre: " << p.cilindre << '\n';
    os << "Putere: " << p.putere << '\n';
    os << "Tip autovehicul: " << p.tipAutovehicul << '\n';
    os << "////////////////////////////////////////////////////////////////////\n";
    return os;
}

class Talon {
    const SpecificatiiMasina masina;
    std::string numeProprietar;
    std::string prenumeProprietar;
    const std::string dataInmatriculare;
    std::string valabilitateITP;
    std::string valabilitateRCA;
    Adresa adr;

public:
    Talon(const SpecificatiiMasina &masina, const std::string &nume_proprietar, const std::string &prenume_proprietar,
        const std::string &data_inmatriculare, const std::string &valabilitate_itp, const std::string &valabilitate_rca,
        const Adresa &adr)
        : masina(masina),
          numeProprietar(nume_proprietar),
          prenumeProprietar(prenume_proprietar),
          dataInmatriculare(data_inmatriculare),
          valabilitateITP(valabilitate_itp),
          valabilitateRCA(valabilitate_rca),
          adr(adr) {
    }

    [[nodiscard]] SpecificatiiMasina get_masina() const {
        return masina;
    }

    [[nodiscard]] std::string get_nume_proprietar() const {
        return numeProprietar;
    }

    [[nodiscard]] std::string get_prenume_proprietar() const {
        return prenumeProprietar;
    }

    [[nodiscard]] std::string get_data_inmatriculare() const {
        return dataInmatriculare;
    }

    [[nodiscard]] std::string get_valabilitate_itp() const {
        return valabilitateITP;
    }

    [[nodiscard]] std::string get_valabilitate_rca() const {
        return valabilitateRCA;
    }

    [[nodiscard]] Adresa get_adr() const {
        return adr;
    }
    friend std::ostream &operator<<(std::ostream &os, const Talon &talon);
};
std::ostream &operator<<(std::ostream &os, const Talon &p) {

    os << "////////////////////////////////////////////////////////////////////\n";
    os << "Certificat de Inmatriculare\n";
    os<< "Numar de inmatriculare\n";
    os << p.masina.get_numar_inmatriculare() << '\n';
    os << "Marca/Brand/Make\n";
    os << p.masina.get_marca() << '\n';
    os << "Model/Model/Model\n";
    os << p.masina.get_model() << '\n';
    os << "Culoare/Color/Couleur\n";
    os << p.masina.get_culoare() << '\n';
    os << "Tip autovehicul/Vehicle type/Type de véhicule\n";
    os << p.masina.get_tip_autovehicul() << '\n';
    os << "An fabricatie/Year of manufacture/Année de fabrication\n";
    os << p.masina.get_an_fabricatie() << '\n';
    os <<"Nume/Nom/Last name\n";
    os << p.numeProprietar << '\n';
    os << "Prenume/Prenom/First name\n";
    os << p.prenumeProprietar << '\n';
    os << "Adresa/Adresse/Address\n";
    os << p.adr;
    os << "Data inmatriculare/Date d'immatriculation/Date of registration\n";
    os << p.dataInmatriculare << '\n';
    os << "Valabilitate ITP/ITP validity/ITP validité\n";
    os << p.valabilitateITP << '\n';
    os << "Valabilitate RCA/RCA validity/RCA validité\n";
    os << p.valabilitateRCA << '\n';
    os << "Putere/Power/puissance\n";
    os << p.masina.get_putere() << '\n';
    os << "cilindre/Engine capacity/Capacité du moteur\n";
    os << p.masina.get_cilindre() << '\n';
    os << "SERIA\n" << p.masina.get_serie_sasiu() << '\n';
    os << "////////////////////////////////////////////////////////////////////\n";
    return os;

}
class Masina {
   const SpecificatiiMasina masina;
   const unsigned int viteza;

public:
    Masina(const SpecificatiiMasina &masina, unsigned int viteza)
        : masina(masina),
          viteza(viteza) {
    }

    [[nodiscard]] SpecificatiiMasina get_masina() const {
        return masina;
    }

    [[nodiscard]] unsigned int get_viteza() const {
        return viteza;
    }
    friend std::ostream &operator<<(std::ostream &os, const Masina &p);

};

std::ostream &operator<<(std::ostream &os, const Masina &p) {
    os << "Masina\n";
    os << "////////////////////////////////////////////////////////////////////\n";
    os << "Viteza: " << p.viteza << '\n';
    os << "Marca: " << p.masina.get_marca() << '\n';
    os << "Model: " << p.masina.get_model() << '\n';
    os << "Culoare: " << p.masina.get_culoare() << '\n';
    os << "An fabricatie: " << p.masina.get_an_fabricatie() << '\n';
    os << "cilindre: " << p.masina.get_cilindre() << '\n';
    os << "Putere: " << p.masina.get_putere() << '\n';
    os << "Serie sasiu: " << p.masina.get_serie_sasiu() << '\n';
    os << "Numar inmatriculare: " << p.masina.get_numar_inmatriculare() << '\n';
    os << "////////////////////////////////////////////////////////////////////\n";
    return os;

}

class AlcoolTest {
   const float rezultat;
    const float rezultat_sange;

public:
    AlcoolTest(float rezultat, float rezultat_sange)
        : rezultat(rezultat),
          rezultat_sange(rezultat_sange) {
    }

    [[nodiscard]] float rezultat1() const {
        return rezultat;
    }

    [[nodiscard]] float rezultat_sange1() const {
        return rezultat_sange;
    }
    friend std::ostream &operator<<(std::ostream &os, const AlcoolTest &p);
};
std:: ostream & operator<<(std::ostream &os, const AlcoolTest &p) {
    os<< "Rezultat alcool test: "<<p.rezultat<<'\n';
    if (p.rezultat > 0.4) {
        os<< "Rezultat alcool test sange: "<<p.rezultat_sange<<'\n';
    }
    return os;
}
class Joc {

};

int main() {
    return 0;
}