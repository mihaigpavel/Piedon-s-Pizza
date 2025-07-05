#include "ValidareDosarPenal.h"

bool ValidareDosarPenal::verifica(const DetectieRadar&, const RezultatTestareAlcoolemie& alcoolemie,
                                   const CarteIdentitate& buletin, const Permis& permis,
                                   const Talon& talon, const SpecificatiiAutovehicul&) const {
    return alcoolemie.esteDosarPenal()
           || !permis.esteValidaDataNasterePermisVsCnp()
           || buletin.get_datePersoanale() != permis.get_persoana()
           || !permis.categorieValida(talon.get_autovehicul().get_tip_autovehicul());
}



