#include "../../include/Estados/Estado.h"
#include "../../include/Ente/Menus/Menu.h"

namespace Estados {
    Estado::Estado(Menus::Menu* menu, IdEstado mid) {
        id = mid;
        pMenu = menu;
        anterior = NULL;        
    }

    Estado::~Estado() {
        
    }
    
    void Estado::observar() {
        pMenu->ativarControle();
    }
    void Estado::cegar(){
        pMenu->desativarControle();
    }
} // namespace Estados