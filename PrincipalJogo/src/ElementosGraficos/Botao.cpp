#include "../../include/ElementosGraficos/Botao.h"

namespace ElementosGraficos {
    Botao::Botao(Coordenada tam, Coordenada pos, Estados::IdEstado func, std::string titulo):
        ElementoGrafico(tam, Coordenada(pos.x-tam.x/2.f, pos.y-tam.y/2.f), TEX_BOTAO_NEUTRO, ID::botao),
        ativo(false),
        texto(tam, pos, titulo)
    {
        funcao = func;
        atualizarTextura();
    }

    Botao::~Botao() {

    }

    void Botao::ativar() {
        ativo = true;
    }
    void Botao::desativar(){
        ativo = false;
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