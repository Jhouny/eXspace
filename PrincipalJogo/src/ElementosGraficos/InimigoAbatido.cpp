#include "../../include/ElementosGraficos/InimigoAbatido.h"

namespace ElementosGraficos {
    InimigoAbatido::InimigoAbatido(Coordenada pos, Jogador* jog):
        Ponto(TAMANHO_PADRAO_INIMIGO_ABATIDO, pos, jog)
    {
        pId = PontoID::inimigoAbatido;
        atualizarTextura();
    }

    InimigoAbatido::~InimigoAbatido() {}

    void InimigoAbatido::atualizarTextura() {
        if(preenchido)
            setTextura(TEX_INIMIGO_ABATIDO_CHEIO);
        else
            setTextura(TEX_INIMIGO_ABATIDO_VAZIO);
    }
}