#include "../../include/ElementosGraficos/BotaoAlternador.h"

namespace ElementosGraficos {
    BotaoAlternador::BotaoAlternador(Coordenada tam, Coordenada pos):
        Botao(tam, pos, Estados::IdEstado::indefinido),
        escolha(),
        indice(0)
    {
        atualizarTextura();
    }

    BotaoAlternador::~BotaoAlternador() {
        escolha.clear();
    }

    void BotaoAlternador::setAtivo(int ind) {
        texto = escolha[ind];
        indice = ind;
    }

    void BotaoAlternador::inserirEscolha(std::string conteudo) {
        Texto* temp = new Texto(getTamanho(), Coordenada(getPosicao().x + getTamanho().x/2.f, getPosicao().y + getTamanho().y/2.f), conteudo);
        escolha.emplace_back(temp);
    }

    void BotaoAlternador::proximo() {
        indice++;
        if(indice >= escolha.size())
            indice = 0;
        texto = escolha[indice];
    }

    void BotaoAlternador::anterior() {
        indice--;
        if(indice < 0)
            indice = escolha.size();
        texto = escolha[indice];
    }

    void BotaoAlternador::atualizarTextura() {
        if(ativo)
            setTexture(TEX_BOTAO_ALTERNADOR_ATIVO);
        else
            setTexture(TEX_BOTAO_ALTERNADOR_NEUTRO);
    }

} // namespace ElementosGraficos 