#include "../../../include/Ente/Entidades/Entidade.h"
#include "../../../include/Ente/Entidades/Personagem.h"


Entidade::Entidade(ID id, Coordenada tam, Coordenada pos, bool estat):
    Ente(id),
    tamanho(tam),
    posicao(pos),
    estatico(estat),
    shape(sf::Vector2f(tam.getX(),tam.getY())),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    ativo(true)
{
    shape.setPosition(pos.x,pos.y);
    sprite.setPosition(pos.x, pos.y);
}

Entidade::~Entidade() {

}

void Entidade::setPosicao(Coordenada pos) {
    posicao = pos;
    this->shape.setPosition(pos.x, pos.y);
    this->sprite.setPosition(pos.x, pos.y);
}

void Entidade::setPosicao(float x, float y) {
    posicao.setCoordenada(x, y);
    this->shape.setPosition(x, y);
    this->sprite.setPosition(x, y);
}

void Entidade::setTexture(const char* path, bool esticar) {
    sf::Texture* temp = pGrafico->loadTexture(path);
    
    sprite.setTexture(*temp);

    if(!esticar) {
        sprite.setTextureRect(sf::IntRect(0, 0, tamanho.x, temp->getSize().y));
        temp->setRepeated(true);
    } else {
        // Define a textura e a escala de acordo com o o retangulo de shape
        float sX = tamanho.x/temp->getSize().x;
        float sY = tamanho.y/temp->getSize().y;
        sprite.setScale(sX, sY);
    }
}

void Entidade::atualizaTexture(const char* path){
    if(this->getID() == ID::jogador || this->getID() == ID::inimigoTerrestre){
        sf::Texture* temp = pGrafico->loadTexture(path);
        Personagem *psng= dynamic_cast<Personagem*>(this);
        float sX;

        if(psng->getVelocidade().x<0){
            sX = -tamanho.x/temp->getSize().x;
            sprite.setOrigin(sf::Vector2f(23,0)); //seta outro eixo
        } else {
            sX = tamanho.x/temp->getSize().x;
            sprite.setOrigin(sf::Vector2f(0,0));
        }
        float sY = tamanho.y/temp->getSize().y;
        sprite.setScale(sX, sY);
    }
    else if(this->getID() == ID::inimigoTerrestre){
        sf::Texture* temp = pGrafico->loadTexture(path);
        Personagem *psng= dynamic_cast<Personagem*>(this);
        float sX;

        if(psng->getVelocidade().x<0){
            sX = -tamanho.x/temp->getSize().x;
            sprite.setOrigin(sf::Vector2f(23,0)); //
        } else {
            sX = tamanho.x/temp->getSize().x;
            sprite.setOrigin(sf::Vector2f(25,0));
        }
        float sY = tamanho.y/temp->getSize().y;
        sprite.setScale(sX, sY);
    }
}


void Entidade::colisao(Entidade* outraEntidade, Coordenada intersecao) { };

void Entidade::setEstatico(bool est){
    estatico=est;
}