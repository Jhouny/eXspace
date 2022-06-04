#include "../../include/ElementosGraficos/Coracao.h"

namespace ElementosGraficos {
    Coracao::Coracao(Coordenada pos):
        Ponto(TAMANHO_PADRAO_CORACAO, pos)
    {
        pId = PontoID::coracao;
    }

    Coracao::~Coracao() {}

    void Coracao::atualizarTextura() {
        if(preenchido)
            setTexture(TEX_CORACAO_CHEIO);
        else
            setTexture(TEX_CORACAO_VAZIO);
    }
}