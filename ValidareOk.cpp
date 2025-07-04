#include "ValidareOk.h"

bool ValidareOk::verifica(const DetectieRadar& radar, const RezultatTestareAlcoolemie& alcoolemie,
                          const CarteIdentitate& buletin, const Permis& permis,
                          const Talon& talon, const SpecificatiiAutovehicul& masina) const {
    return !radar.esteCazAmenda()
        && !radar.esteCazRetinerePermis()
        && !alcoolemie.esteCazDeAmenda()
        && !alcoolemie.esteDosarPenal()
        && permis.esteValidaDataNasterePermisVsCnp()
       // && buletin.get_datePersoanale() == permis.get_persoana()
        && permis.categorieValida(talon.get_autovehicul().get_tip_autovehicul())
        && masina == talon.get_autovehicul();
}

std::shared_ptr<Validare> ValidareOk::clone() const {
    return std::make_shared<ValidareOk>(*this);
}
