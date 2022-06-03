#include "../../incude/ElementosGraficos/InimigoAbatido.h"

namespace ElementosGraficos {
    InimigoAbatido::InimigoAbatido(Coordenada tam, Coordenada pos):
        Ponto(tam, pos)
    {
        
    }

    InimigoAbatido::~InimigoAbatido() {}

    void InimigoAbatido::atualizarTextura() {
        if(preenchido)
            setTexture(TEX_CORACAO_CHEIO);
        else
            setTexture(TEX_CORACAO_VAZIO);
    }
}