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


};
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
};
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
};

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
};
class Acte {
 Permis p;
    Talon t;

public:
 Acte(const Permis &p, const Talon &t)
     : p(p),
       t(t) {
 }

 ~Acte() {
     std::cout << "Acte deleted" << std::endl;
 }

 Acte(const Acte &other)
     : p(other.p),
       t(other.t) {
 }

 Acte(Acte &&other)
     : p(std::move(other.p)),
       t(std::move(other.t)) {
 }

 Acte & operator=(const Acte &other) {
     if (this == &other)
         return *this;
     p = other.p;
     t = other.t;
     return *this;
 }

 Acte & operator=(Acte &&other) {
     if (this == &other)
         return *this;
     p = std::move(other.p);
     t = std::move(other.t);
     return *this;
 }
};
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

};
class LegitimatiePolitist{
    std::string nume;
    std::string prenume;
    std::string grad;
    std::string numarLegitimatie;
    std::string sectie;
    std::string dataEliberare;
    std::string dataExpirare;
    std::string emitent;

public:
    LegitimatiePolitist(const std::string &nume, const std::string &prenume, const std::string &grad,
        const std::string &numar_legitimatie, const std::string &sectie, const std::string &data_eliberare,
        const std::string &data_expirare, const std::string &emitent)
        : nume(nume),
          prenume(prenume),
          grad(grad),
          numarLegitimatie(numar_legitimatie),
          sectie(sectie),
          dataEliberare(data_eliberare),
          dataExpirare(data_expirare),
          emitent(emitent) {
    }

    ~LegitimatiePolitist() {
        std::cout << "LegitimatiePolitist deleted" << std::endl;
    }

    LegitimatiePolitist(const LegitimatiePolitist &other)
        : nume(other.nume),
          prenume(other.prenume),
          grad(other.grad),
          numarLegitimatie(other.numarLegitimatie),
          sectie(other.sectie),
          dataEliberare(other.dataEliberare),
          dataExpirare(other.dataExpirare),
          emitent(other.emitent) {
    }

    LegitimatiePolitist(LegitimatiePolitist &&other)
        : nume(std::move(other.nume)),
          prenume(std::move(other.prenume)),
          grad(std::move(other.grad)),
          numarLegitimatie(std::move(other.numarLegitimatie)),
          sectie(std::move(other.sectie)),
          dataEliberare(std::move(other.dataEliberare)),
          dataExpirare(std::move(other.dataExpirare)),
          emitent(std::move(other.emitent)) {
    }

    LegitimatiePolitist & operator=(const LegitimatiePolitist &other) {
        if (this == &other)
            return *this;
        nume = other.nume;
        prenume = other.prenume;
        grad = other.grad;
        numarLegitimatie = other.numarLegitimatie;
        sectie = other.sectie;
        dataEliberare = other.dataEliberare;
        dataExpirare = other.dataExpirare;
        emitent = other.emitent;
        return *this;
    }

    LegitimatiePolitist & operator=(LegitimatiePolitist &&other) {
        if (this == &other)
            return *this;
        nume = std::move(other.nume);
        prenume = std::move(other.prenume);
        grad = std::move(other.grad);
        numarLegitimatie = std::move(other.numarLegitimatie);
        sectie = std::move(other.sectie);
        dataEliberare = std::move(other.dataEliberare);
        dataExpirare = std::move(other.dataExpirare);
        emitent = std::move(other.emitent);
        return *this;
    }
};
class Politist {
Buletin id;
LegitimatiePolitist legitimatie;

public:
Politist(const Buletin &id, const LegitimatiePolitist &legitimatie)
    : id(id),
      legitimatie(legitimatie) {
}

    ~Politist() {
    std::cout << "Politist deleted" << std::endl;
}

Politist(const Politist &other)
    : id(other.id),
      legitimatie(other.legitimatie) {
}

Politist(Politist &&other)
    : id(std::move(other.id)),
      legitimatie(std::move(other.legitimatie)) {
}

Politist & operator=(const Politist &other) {
    if (this == &other)
        return *this;
    id = other.id;
    legitimatie = other.legitimatie;
    return *this;
}

Politist & operator=(Politist &&other) {
    if (this == &other)
        return *this;
    id = std::move(other.id);
    legitimatie = std::move(other.legitimatie);
    return *this;
}
};

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
};

int main() {

    return 0;
}
