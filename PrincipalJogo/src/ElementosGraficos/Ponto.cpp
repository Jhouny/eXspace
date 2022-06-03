#include "../../include/ElementosGraficos/Ponto.h"

namespace ElementosGraficos {
    Ponto::Ponto(Coordenada tam, Coordenada pos):
        ElementoGrafico(tam, pos, TEX_PONTO_VAZIO),
        preenchido(false)
    {

    }

    Ponto::~Ponto() {

    }

    void Ponto::preencher() {
        preenchido = true;
    }

    void Ponto::limpar() {
        preenchido = false;
    }

    void Ponto::executar() {
        atualizarTextura();
    }
} // namespace ElementosGraficos 
