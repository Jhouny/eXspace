#include "../../include/ElementosGraficos/Coracao.h"

namespace ElementosGraficos {
    Coracao::Coracao(Coordenada pos, Jogador* jog):
        Ponto(TAMANHO_PADRAO_CORACAO, pos, jog)
    {   
        preencher();  // Coração começa preenchido 
        pId = PontoID::coracao;
        atualizarTextura();
    }

    Coracao::~Coracao() {}

    void Coracao::atualizarTextura() {
        if(preenchido)
            setTextura(TEX_CORACAO_CHEIO);
        else
            setTextura(TEX_CORACAO_VAZIO);
    }
}