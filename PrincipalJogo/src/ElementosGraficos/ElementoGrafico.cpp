#include "../../include/ElementosGraficos/ElementoGrafico.h"

namespace ElementosGraficos {
    ElementoGrafico::ElementoGrafico(Coordenada tam, Coordenada pos, const char* pathTextura, ID Id):
    tamanho(tam),
    posicao(pos),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    id(Id)
    {
        setTexture(pathTextura);    
    }

    ElementoGrafico::~ElementoGrafico() {
        
    }

    void ElementoGrafico::setTexture(const char* path) {
        sf::Texture *temp = pGrafico->loadTexture(path);
        sprite.setTexture(*temp);
        float sX = (float)tamanho.x / temp->getSize().x;
        float sY = (float)tamanho.y / temp->getSize().y;
        sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));
        sprite.setScale(sX, sY);
    }
    
} // namespace ElementosGraficos