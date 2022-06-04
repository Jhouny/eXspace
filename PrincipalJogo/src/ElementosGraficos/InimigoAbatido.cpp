#include "../../include/ElementosGraficos/InimigoAbatido.h"

namespace ElementosGraficos {
    InimigoAbatido::InimigoAbatido(Coordenada pos):
        Ponto(TAMANHO_PADRAO_INIMIGO_ABATIDO, pos)
    {
        pId = PontoID::inimigoAbatido;
    }

    InimigoAbatido::~InimigoAbatido() {}

    void InimigoAbatido::atualizarTextura() {
        if(preenchido)
            setTexture(TEX_INIMIGO_ABATIDO_CHEIO);
        else
            setTexture(TEX_INIMIGO_ABATIDO_VAZIO);
    }
}