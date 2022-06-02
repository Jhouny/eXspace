#include "../../include/ElementosGraficos/Botao.h"

namespace ElementosGraficos {
    Botao::Botao(Coordenada tam, Coordenada pos):
        ElementoGrafico(tam, pos, TEX_BOTAO_NEUTRO, ID::botao),
        ativo(false)
    {

    }

    Botao::~Botao() {

    }

    void Botao::ativar() {
        ativo = true;
    }

    void Botao::atualizarTextura() {
        if(ativo)
            setTexture(TEX_BOTAO_ATIVO);
        else
            setTexture(TEX_BOTAO_NEUTRO);
    }

    void Botao::executar() {
        atualizarTextura();
    }

} // namespace ElementosGraficos 