#include "AnalizaActe.h"

AnalizaActe::AnalizaActe(const DetectieRadar &detectie_radar, const RezultatTestareAlcoolemie &alcolemie,
                         const CarteIdentitate &buletin, const Permis &permis, const Talon &talon,
                         const SpecificatiiAutovehicul &masina)
    : detectieRadar(detectie_radar),
      alcolemie(alcolemie),
      buletin(buletin),
      permis(permis),
      talon(talon),
      masina(masina) {
}

bool AnalizaActe::esteCorectRaspunsul(int raspuns) {
    if (!detectieRadar.esteCazAmenda()
     && !detectieRadar.esteCazRetinerePermis()
     && !alcolemie.esteCazDeAmenda()
     && !alcolemie.esteDosarPenal()
     && permis.esteValidaDataNasterePermisVsCnp()
     && suntDatelePersonaleIdentice()
     && esteCorespunzatorPermisulPentruAutoturism()
     && coincideTalonCuMasina()
     && raspuns == 1) {
        return true;
    }
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
    if (!coincideTalonCuMasina() && raspuns == 5) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const AnalizaActe &p) {
    os << "Analizati urmatoarele informatii si raspundeti la intrebare\n\n";
    os << p.detectieRadar << '\n';
    os << p.alcolemie << '\n';
    os << p.buletin << '\n';
    os << p.permis << '\n';
    os << p.talon << '\n';
    os << "Autovehicul oprit la control\n";
    os << "////////////////////////////////////////////////////////////////////\n" << p.masina << "////////////////////////////////////////////////////////////////////\n";
    return os;
}

bool AnalizaActe::suntDatelePersonaleIdentice() {
    return buletin.get_datePersoanale().get_cnp() == permis.get_persoana().get_cnp()
           && buletin.get_datePersoanale().get_nume() == permis.get_persoana().get_nume()
           && buletin.get_datePersoanale().get_prenume() == permis.get_persoana().get_prenume();
}

bool AnalizaActe::esteCorespunzatorPermisulPentruAutoturism() {
    return permis.categorieValida(talon.get_autovehicul().get_tip_autovehicul());
}

bool AnalizaActe::coincideTalonCuMasina() {
    return masina == talon.get_autovehicul();
}
