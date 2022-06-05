#include "../../include/ElementosGraficos/Ponto.h"

namespace ElementosGraficos {
    Ponto::Ponto(Coordenada tam, Coordenada pos, Jogador* jog):
        tamanho(tam),
        posicao(pos),
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        preenchido(false)
    {
        ref = jog;
        pId = PontoID::indef;
        posicaoRelativa.x = pos.x - COMPRIMENTO/2.f;
        posicaoRelativa.y = pos.y - ALTURA/2.f;
    }

    Ponto::~Ponto() {

    }

    void Ponto::preencher() {
        preenchido = true;
    }

    void Ponto::limpar() {
        preenchido = false;
    }

    void Ponto::setTextura(const char* path) {
        sf::Texture *temp = pGrafico->loadTexture(path);
        sprite.setTexture(*temp);
        float sX = (float)tamanho.x / temp->getSize().x;
        float sY = (float)tamanho.y / temp->getSize().y;
        sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
        sprite.setScale(sX, sY);
    }

    void Ponto::atualizaPosicao(Coordenada pos) {
        posicao.x = pos.x + posicaoRelativa.x;
        //posicao.y = pos.y + posicaoRelativa.y;
    }   

    void Ponto::executar(Coordenada pos) {
        atualizaPosicao(pos);
        atualizarTextura();
    }
} // namespace ElementosGraficos 

