#include <iostream>
#include <array>

#include <Helper.h>
#include <string>


class Permis {
    std::string nume;
    std::string prenume;
    std::string dataNastere;
    std::string orasNastere;
    std::string judetNastere;
    std::string dataObtinere;
    std::string dataExpirare;
    std::string emitator;
    unsigned long long cnp;
    std::string categorie;

public:
    Permis(const std::string &nume, const std::string &prenume, const std::string &data_nastere,
        const std::string &oras_nastere, const std::string &judet_nastere, const std::string &data_obtinere,
        const std::string &data_expirare, const std::string &emitator, const unsigned long long cnp,
        const std::string &categorie)
        : nume(nume),
          prenume(prenume),
          dataNastere(data_nastere),
          orasNastere(oras_nastere),
          judetNastere(judet_nastere),
          dataObtinere(data_obtinere),
          dataExpirare(data_expirare),
          emitator(emitator),
          cnp(cnp),
          categorie(categorie) {
    }

    ~Permis() {
        std::cout<<"Permis deleted"<<std::endl;
    }

    Permis(const Permis &other)
        : nume(other.nume),
          prenume(other.prenume),
          dataNastere(other.dataNastere),
          orasNastere(other.orasNastere),
          judetNastere(other.judetNastere),
          dataObtinere(other.dataObtinere),
          dataExpirare(other.dataExpirare),
          emitator(other.emitator),
          cnp(other.cnp),
          categorie(other.categorie) {
    }

    Permis(Permis &&other)
        : nume(std::move(other.nume)),
          prenume(std::move(other.prenume)),
          dataNastere(std::move(other.dataNastere)),
          orasNastere(std::move(other.orasNastere)),
          judetNastere(std::move(other.judetNastere)),
          dataObtinere(std::move(other.dataObtinere)),
          dataExpirare(std::move(other.dataExpirare)),
          emitator(std::move(other.emitator)),
          cnp(other.cnp),
          categorie(std::move(other.categorie)) {
    }

    Permis & operator=(const Permis &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        prenume = other.prenume;
        dataNastere = other.dataNastere;
        orasNastere = other.orasNastere;
        judetNastere = other.judetNastere;
        dataObtinere = other.dataObtinere;
        dataExpirare = other.dataExpirare;
        emitator = other.emitator;
        cnp = other.cnp;
        categorie = other.categorie;
        return *this;
    }

    Permis & operator=(Permis &&other) {
        if (this == &other)
            return *this;
        nume = std::move(other.nume);
        prenume = std::move(other.prenume);
        dataNastere = std::move(other.dataNastere);
        orasNastere = std::move(other.orasNastere);
        judetNastere = std::move(other.judetNastere);
        dataObtinere = std::move(other.dataObtinere);
        dataExpirare = std::move(other.dataExpirare);
        emitator = std::move(other.emitator);
        cnp = other.cnp;
        categorie = std::move(other.categorie);
        return *this;
    }
    friend std::ostream & operator<<(std::ostream &os, const Permis &p);

};
std::ostream & operator<<(std::ostream &os, const Permis &p) {
        std::cout<< "//////////////////////////////////////////////"<<'\n';
        std::cout<<"  "<<p.nume<<'\n';
        std::cout<<"  "<<p.prenume<<'\n';
        std::cout<<"  "<<p.dataNastere << p.orasNastere <<p.judetNastere << '\n';
        std::cout<<"  "<<p.dataObtinere << p.emitator<<'\n';
        std::cout<<"  "<<p.dataExpirare << p.cnp<<'\n';
        std::cout<<"  "<<p.categorie <<'\n';
        std::cout<< "//////////////////////////////////////////////"<<'\n';
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
    Adresa(const std::string &judet, const std::string &oras, const std::string &strada, const int nr, const int et,
        const int ap, const int sc)
        : judet(judet),
          oras(oras),
          strada(strada),
          nr(nr),
          et(et),
          ap(ap),
          sc(sc) {
    }

    ~Adresa() {
        std::cout<<"Adresa deleted"<<std::endl;
    }

    Adresa(const Adresa &other)
        : judet(other.judet),
          oras(other.oras),
          strada(other.strada),
          nr(other.nr),
          et(other.et),
          ap(other.ap),
          sc(other.sc) {
    }

    Adresa(Adresa &&other)
        : judet(std::move(other.judet)),
          oras(std::move(other.oras)),
          strada(std::move(other.strada)),
          nr(other.nr),
          et(other.et),
          ap(other.ap),
          sc(other.sc) {
    }

    Adresa & operator=(const Adresa &other) {
        if (this == &other)
            return *this;
        judet = other.judet;
        oras = other.oras;
        strada = other.strada;
        nr = other.nr;
        et = other.et;
        ap = other.ap;
        sc = other.sc;
        return *this;
    }

    Adresa & operator=(Adresa &&other) {
        if (this == &other)
            return *this;
        judet = std::move(other.judet);
        oras = std::move(other.oras);
        strada = std::move(other.strada);
        nr = other.nr;
        et = other.et;
        ap = other.ap;
        sc = other.sc;
        return *this;
    }
    friend std::ostream & operator<<(std::ostream &os, const Adresa &p);
};


std::ostream & operator<<(std::ostream &os, const Adresa &p) {
    std::cout<< "Jud." <<p.judet<<" ";
    std::cout<< "Oras" <<p.oras<<'\n';
    std::cout<< "Str." <<p.strada<<' ';
    std::cout<< "nr." <<p.nr<<' ';
    if (p.sc != -1) {
        std::cout<< "Sc." <<p.sc<<' ';
    }
    if (p.et != -1) {
        std::cout<< "et." <<p.et<<' ';
    }
    if (p.ap != -1) {
        std::cout<< "ap." <<p.ap<<' ';
    }



}
class Buletin {
unsigned long long cnp;
    std::string serie;
    int nr;
    std::string cod;
    std::string nume;
    std::string prenume;
    std::string cetatenie;
    std::string orasNastere;
    std::string judetNastere;
  Adresa adr;
    std::string emitator;
    std::string valabilitate;
    std::string orasPrescurtat;
    int CifraControl;

public:
Buletin(const unsigned long long cnp, const std::string &serie, const int nr, const std::string &cod,
    const std::string &nume, const std::string &prenume, const std::string &cetatenie, const std::string &oras_nastere,
    const std::string &judet_nastere, const Adresa &adr, const std::string &emitator, const std::string &valabilitate,
    const std::string &oras_prescurtat, const int cifra_control)
    : cnp(cnp),
      serie(serie),
      nr(nr),
      cod(cod),
      nume(nume),
      prenume(prenume),
      cetatenie(cetatenie),
      orasNastere(oras_nastere),
      judetNastere(judet_nastere),
      adr(adr),
      emitator(emitator),
      valabilitate(valabilitate),
      orasPrescurtat(oras_prescurtat),
      CifraControl(cifra_control) {
}

~Buletin() {
    std::cout<<"Buletin deleted"<<std::endl;
}

Buletin(const Buletin &other)
    : cnp(other.cnp),
      serie(other.serie),
      nr(other.nr),
      cod(other.cod),
      nume(other.nume),
      prenume(other.prenume),
      cetatenie(other.cetatenie),
      orasNastere(other.orasNastere),
      judetNastere(other.judetNastere),
      adr(other.adr),
      emitator(other.emitator),
      valabilitate(other.valabilitate),
      orasPrescurtat(other.orasPrescurtat),
      CifraControl(other.CifraControl) {
}

Buletin(Buletin &&other)
    : cnp(other.cnp),
      serie(std::move(other.serie)),
      nr(other.nr),
      cod(std::move(other.cod)),
      nume(std::move(other.nume)),
      prenume(std::move(other.prenume)),
      cetatenie(std::move(other.cetatenie)),
      orasNastere(std::move(other.orasNastere)),
      judetNastere(std::move(other.judetNastere)),
      adr(std::move(other.adr)),
      emitator(std::move(other.emitator)),
      valabilitate(std::move(other.valabilitate)),
      orasPrescurtat(std::move(other.orasPrescurtat)),
      CifraControl(other.CifraControl) {
}

Buletin & operator=(const Buletin &other) {
    if (this == &other)
        return *this;
    cnp = other.cnp;
    serie = other.serie;
    nr = other.nr;
    cod = other.cod;
    nume = other.nume;
    prenume = other.prenume;
    cetatenie = other.cetatenie;
    orasNastere = other.orasNastere;
    judetNastere = other.judetNastere;
    adr = other.adr;
    emitator = other.emitator;
    valabilitate = other.valabilitate;
    orasPrescurtat = other.orasPrescurtat;
    CifraControl = other.CifraControl;
    return *this;
}

Buletin & operator=(Buletin &&other) {
    if (this == &other)
        return *this;
    cnp = other.cnp;
    serie = std::move(other.serie);
    nr = other.nr;
    cod = std::move(other.cod);
    nume = std::move(other.nume);
    prenume = std::move(other.prenume);
    cetatenie = std::move(other.cetatenie);
    orasNastere = std::move(other.orasNastere);
    judetNastere = std::move(other.judetNastere);
    adr = std::move(other.adr);
    emitator = std::move(other.emitator);
    valabilitate = std::move(other.valabilitate);
    orasPrescurtat = std::move(other.orasPrescurtat);
    CifraControl = other.CifraControl;
    return *this;
}
    friend std::ostream & operator<<(std::ostream &os, const Buletin &);
};

std :: ostream & operator << (std :: ostream & os, const Buletin & p) {
    std:: cout<<"////////////////////////////////////////////////////////////////////";
    std:: cout<<"ROUMANIE   "<<"ROMANIA   "<<"ROMANIA\n";
    std::cout<<"              SERIA "<<p.serie<<"  NR "<<p.nr<<'\n';
    std::cout<<"Nume/Nom/Last name\n";
    std::cout<<p.nume<<'\n';
    std::cout<<"Prenume/Prenom/First name\n";
    std::cout<<p.prenume<<'\n';
    std::cout<<"Cetatenie/Nationalite,NAtionality\n"<<p.cetatenie<<'\n';
    std::cout<<"Loc nastere/Lieu de naissance/Place of birth\nJud."<<p.judetNastere<<" "<<p.orasNastere<<'\n';
    std::cout<<"Domiciliu/Adresse/address\n"<<p.adr;
    std:: cout<<"Emis de/Delivree par/issued by       valabilitate/validite/validity\n";
    std::cout<<p.emitator<<"              "<<p.valabilitate<<'\n';
    std:: cout<<p.cod << "   esp   "<<p.orasPrescurtat;
    std:: cout<<"////////////////////////////////////////////////////////////////////";
}

class Talon {
    std::string serieSasiu;
    std::string numarInmatriculare;
    std::string marca;
    std::string model;
    std::string culoare;
    std::string tipAutovehicul;
    unsigned int anFabricatie;
    unsigned int cilindree;
    unsigned int putere;
    std::string categorieVehicul;
    std::string numeProprietar;
    std::string prenumeProprietar;
    std::string dataInmatriculare;
    std::string valabilitateITP;
    std::string valabilitateRCA;
    Adresa adr;

public:
    Talon(const std::string &serie_sasiu, const std::string &numar_inmatriculare, const std::string &marca,
        const std::string &model, const std::string &culoare, const std::string &tip_autovehicul,
        const unsigned int an_fabricatie, const unsigned int cilindree, const unsigned int putere,
        const std::string &categorie_vehicul, const std::string &nume_proprietar, const std::string &prenume_proprietar,
        const std::string &data_inmatriculare, const std::string &valabilitate_itp, const std::string &valabilitate_rca,
        const Adresa &adr)
        : serieSasiu(serie_sasiu),
          numarInmatriculare(numar_inmatriculare),
          marca(marca),
          model(model),
          culoare(culoare),
          tipAutovehicul(tip_autovehicul),
          anFabricatie(an_fabricatie),
          cilindree(cilindree),
          putere(putere),
          categorieVehicul(categorie_vehicul),
          numeProprietar(nume_proprietar),
          prenumeProprietar(prenume_proprietar),
          dataInmatriculare(data_inmatriculare),
          valabilitateITP(valabilitate_itp),
          valabilitateRCA(valabilitate_rca),
          adr(adr) {
    }

    ~Talon() {
        std::cout << "Talon deleted"<< std::endl;
    }

    Talon(const Talon &other)
        : serieSasiu(other.serieSasiu),
          numarInmatriculare(other.numarInmatriculare),
          marca(other.marca),
          model(other.model),
          culoare(other.culoare),
          tipAutovehicul(other.tipAutovehicul),
          anFabricatie(other.anFabricatie),
          cilindree(other.cilindree),
          putere(other.putere),
          categorieVehicul(other.categorieVehicul),
          numeProprietar(other.numeProprietar),
          prenumeProprietar(other.prenumeProprietar),
          dataInmatriculare(other.dataInmatriculare),
          valabilitateITP(other.valabilitateITP),
          valabilitateRCA(other.valabilitateRCA),
          adr(other.adr) {
    }

    Talon(Talon &&other)
        : serieSasiu(std::move(other.serieSasiu)),
          numarInmatriculare(std::move(other.numarInmatriculare)),
          marca(std::move(other.marca)),
          model(std::move(other.model)),
          culoare(std::move(other.culoare)),
          tipAutovehicul(std::move(other.tipAutovehicul)),
          anFabricatie(other.anFabricatie),
          cilindree(other.cilindree),
          putere(other.putere),
          categorieVehicul(std::move(other.categorieVehicul)),
          numeProprietar(std::move(other.numeProprietar)),
          prenumeProprietar(std::move(other.prenumeProprietar)),
          dataInmatriculare(std::move(other.dataInmatriculare)),
          valabilitateITP(std::move(other.valabilitateITP)),
          valabilitateRCA(std::move(other.valabilitateRCA)),
          adr(std::move(other.adr)) {
    }

    Talon & operator=(const Talon &other) {
        if (this == &other)
            return *this;
        serieSasiu = other.serieSasiu;
        numarInmatriculare = other.numarInmatriculare;
        marca = other.marca;
        model = other.model;
        culoare = other.culoare;
        tipAutovehicul = other.tipAutovehicul;
        anFabricatie = other.anFabricatie;
        cilindree = other.cilindree;
        putere = other.putere;
        categorieVehicul = other.categorieVehicul;
        numeProprietar = other.numeProprietar;
        prenumeProprietar = other.prenumeProprietar;
        dataInmatriculare = other.dataInmatriculare;
        valabilitateITP = other.valabilitateITP;
        valabilitateRCA = other.valabilitateRCA;
        adr = other.adr;
        return *this;
    }

    Talon & operator=(Talon &&other) {
        if (this == &other)
            return *this;
        serieSasiu = std::move(other.serieSasiu);
        numarInmatriculare = std::move(other.numarInmatriculare);
        marca = std::move(other.marca);
        model = std::move(other.model);
        culoare = std::move(other.culoare);
        tipAutovehicul = std::move(other.tipAutovehicul);
        anFabricatie = other.anFabricatie;
        cilindree = other.cilindree;
        putere = other.putere;
        categorieVehicul = std::move(other.categorieVehicul);
        numeProprietar = std::move(other.numeProprietar);
        prenumeProprietar = std::move(other.prenumeProprietar);
        dataInmatriculare = std::move(other.dataInmatriculare);
        valabilitateITP = std::move(other.valabilitateITP);
        valabilitateRCA = std::move(other.valabilitateRCA);
        adr = std::move(other.adr);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Talon &talon);
};

std::ostream &operator<<(std::ostream &os, const Talon &p) {

    std::cout << "////////////////////////////////////////////////////////////////////\n";
    std::cout<< "Certificat de Inmatriculare\n";
    std::cout << "Marca/Brand/Make\n";
    std::cout << p.marca << '\n';
    std::cout << "Model/Model/Model\n";
    std::cout << p.model << '\n';
    std::cout << "Culoare/Color/Couleur\n";
    std::cout << p.culoare << '\n';
    std::cout << "Tip autovehicul/Vehicle type/Type de véhicule\n";
    std::cout << p.tipAutovehicul << '\n';
    std::cout << "An fabricatie/Year of manufacture/Année de fabrication\n";
    std::cout << p.anFabricatie << '\n';
    std::cout << "Cilindree/Engine capacity/Capacité du moteur\n";
    std::cout << p.cilindree << '\n';
    std::cout << "SERIA\n" << p.serieSasiu <<'\n'<< "  NR Inmatriculare \n" << p.numarInmatriculare << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////\n";

}
class Acte {
 Permis p;
    Talon t;
    Buletin b;

public:
 Acte(const Permis &p, const Talon &t, const Buletin &b)
     : p(p),
       t(t),
       b(b) {
 }

 ~Acte() {
     std::cout << "acte deleted\n";
 }

 Acte(const Acte &other)
     : p(other.p),
       t(other.t),
       b(other.b) {
 }

 Acte(Acte &&other)
     : p(std::move(other.p)),
       t(std::move(other.t)),
       b(std::move(other.b)) {
 }

 Acte & operator=(const Acte &other) {
     if (this == &other)
         return *this;
     p = other.p;
     t = other.t;
     b = other.b;
     return *this;
 }

 Acte & operator=(Acte &&other) {
     if (this == &other)
         return *this;
     p = std::move(other.p);
     t = std::move(other.t);
     b = std::move(other.b);
     return *this;
 }

    friend std::ostream &operator<<(std::ostream &os, const Acte &p);
};

std::ostream &operator<<(std::ostream &os, const Acte &p) {
  std::cout << "Acte\nPermis\n" << p.p << '\nBuletin\n' << p.b << '\nTalon\n' << p.t << '\n';
}



class AlcoolTest {
int rezultat;
    int rezultat_sange;

public:
AlcoolTest(const int rezultat, const int rezultat_sange)
    : rezultat(rezultat),
      rezultat_sange(rezultat_sange) {
}

~AlcoolTest() {
    std::cout << "AlcoolTest deleted" << std::endl;
}

AlcoolTest(const AlcoolTest &other)
    : rezultat(other.rezultat),
      rezultat_sange(other.rezultat_sange) {
}

AlcoolTest(AlcoolTest &&other)
    : rezultat(other.rezultat),
      rezultat_sange(other.rezultat_sange) {
}

AlcoolTest & operator=(const AlcoolTest &other) {
    if (this == &other)
        return *this;
    rezultat = other.rezultat;
    rezultat_sange = other.rezultat_sange;
    return *this;
}

AlcoolTest & operator=(AlcoolTest &&other) {
    if (this == &other)
        return *this;
    rezultat = other.rezultat;
    rezultat_sange = other.rezultat_sange;
    return *this;
}

friend std::ostream &operator<<(std::ostream &os, const AlcoolTest &p);

};

std:: ostream & operator<<(std::ostream &os, const AlcoolTest &p) {
    std::cout<< "Rezultat alcool test: "<<p.rezultat<<'\n';
    if (p.rezultat > 0.4) {
        std::cout<< "Rezultat alcool test sange: "<<p.rezultat_sange<<'\n';
    }
}

class Masina {
    std::string marca;
    std::string model;
    std::string culoare;
    unsigned int anFabricatie;
    unsigned int cilindree;
    unsigned int putere;
    std::string serieSasiu;
    std::string numarInmatriculare;

public:
    Masina(const std::string &marca, const std::string &model, const std::string &culoare,
        const unsigned int an_fabricatie, const unsigned int cilindree, const unsigned int putere,
        const std::string &serie_sasiu, const std::string &numar_inmatriculare)
        : marca(marca),
          model(model),
          culoare(culoare),
          anFabricatie(an_fabricatie),
          cilindree(cilindree),
          putere(putere),
          serieSasiu(serie_sasiu),
          numarInmatriculare(numar_inmatriculare) {
    }

    ~Masina() {
        std::cout << "Masina deleted" << std::endl;
    }

    Masina(const Masina &other)
        : marca(other.marca),
          model(other.model),
          culoare(other.culoare),
          anFabricatie(other.anFabricatie),
          cilindree(other.cilindree),
          putere(other.putere),
          serieSasiu(other.serieSasiu),
          numarInmatriculare(other.numarInmatriculare) {
    }

    Masina(Masina &&other)
        : marca(std::move(other.marca)),
          model(std::move(other.model)),
          culoare(std::move(other.culoare)),
          anFabricatie(other.anFabricatie),
          cilindree(other.cilindree),
          putere(other.putere),
          serieSasiu(std::move(other.serieSasiu)),
          numarInmatriculare(std::move(other.numarInmatriculare)) {
    }

    Masina & operator=(const Masina &other) {
        if (this == &other)
            return *this;
        marca = other.marca;
        model = other.model;
        culoare = other.culoare;
        anFabricatie = other.anFabricatie;
        cilindree = other.cilindree;
        putere = other.putere;
        serieSasiu = other.serieSasiu;
        numarInmatriculare = other.numarInmatriculare;
        return *this;
    }

    Masina & operator=(Masina &&other) {
        if (this == &other)
            return *this;
        marca = std::move(other.marca);
        model = std::move(other.model);
        culoare = std::move(other.culoare);
        anFabricatie = other.anFabricatie;
        cilindree = other.cilindree;
        putere = other.putere;
        serieSasiu = std::move(other.serieSasiu);
        numarInmatriculare = std::move(other.numarInmatriculare);
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Masina &p);
};


std::ostream &operator<<(std::ostream &os, const Masina &p) {
    std::cout<< "Masina\n";
    std::cout << "////////////////////////////////////////////////////////////////////\n";
    std::cout << "Marca: " << p.marca << '\n';
    std::cout << "Model: " << p.model << '\n';
    std::cout << "Culoare: " << p.culoare << '\n';
    std::cout << "An fabricatie: " << p.anFabricatie << '\n';
    std::cout << "Cilindree: " << p.cilindree << '\n';
    std::cout << "Putere: " << p.putere << '\n';
    std::cout << "Serie sasiu: " << p.serieSasiu << '\n';
    std::cout << "Numar inmatriculare: " << p.numarInmatriculare << '\n';
    std::cout << "////////////////////////////////////////////////////////////////////\n";
}

int main() {

    return 0;
}
