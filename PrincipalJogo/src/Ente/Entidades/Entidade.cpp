#include "../../../include/Ente/Entidades/Entidade.h"
#include "../../../include/Ente/Entidades/Personagem.h"
#include "../../../include/Ente/Entidades/Dinamicas/Projetil.h"


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
    shape.setFillColor(sf::Color(255, 255, 255, 128));
    sprite.setPosition(pos.x, pos.y);
}

Entidade::~Entidade() {

}

void Entidade::setPosicao(Coordenada pos) {
    posicao = pos;
    this->shape.setPosition(pos.x, pos.y);
    this->sprite.setPosition(pos.x  + getTamanho().x/2.f, pos.y);
}

void Entidade::setPosicao(float x, float y) {
    posicao.setCoordenada(x, y);
    this->shape.setPosition(x, y);
    this->sprite.setPosition(x + getTamanho().x/2.f, y);
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
        sprite.setOrigin(sf::Vector2f(getTamanho().x/4.f - sX,0));
        sprite.setScale(sX, sY);
    }
}

void Entidade::atualizaTexture(){
    if(this->getID() == ID::projetil) {
        Projetil *proj= dynamic_cast<Projetil*>(this);
        sf::Vector2f escala = sprite.getScale();
        if(proj->getVelocidade().x < 0) {
            escala.x = -1*fabs(escala.x);
        } else {
            escala.x = fabs(escala.x);
        }

        sprite.setScale(escala);
    } else if(this->getEstatico() == false) {
        Personagem *psng= dynamic_cast<Personagem*>(this);

        sf::Vector2f escala = sprite.getScale();
        if(psng->getVelocidade().x < 0) {
            escala.x = -1*fabs(escala.x);
        } else if (psng->getVelocidade().x > 0){
            escala.x = fabs(escala.x);
        }

        sprite.setScale(escala);
    }
}


void Entidade::colisao(Entidade* outraEntidade, Coordenada intersecao) { };

void Entidade::setEstatico(bool est){
    estatico = est;
}

bool Entidade::operator==(Entidade *ent) {
    if(this->getRG() == ent->getRG())
        return true;
    else
        return false;
}