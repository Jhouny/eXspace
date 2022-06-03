#include "../../include/ElementosGraficos/Coracao.h"

namespace ElementosGraficos {
    Coracao::Coracao(Coordenada tam, Coordenada pos):
        Ponto(tam, pos)
    {

    }

    Coracao::~Coracao() {}

    void Coracao::atualizarTextura() {
        if(preenchido)
            setTexture(TEX_CORACAO_CHEIO);
        else
            setTexture(TEX_CORACAO_VAZIO);
    }
}