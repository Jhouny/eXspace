#include "../../../include/Entidades/Dinamicas/InimigoTerrestre.h"

#define VELOCIDADE 5
#define RECUO 50

InimigoTerrestre::InimigoTerrestre(Coordenada tam, Coordenada pos, int v,int d):
    Inimigo(tam,pos,v,d),
    velocidade(VELOCIDADE),
    jogTaPerto(false)
{
    shape.setFillColor(sf::Color::Red);
    pJogador=NULL;
}

InimigoTerrestre::~InimigoTerrestre() { }

void InimigoTerrestre::setVelocidade(float v) {
    velocidade = v;
}

void InimigoTerrestre::colisao(Entidade* outraEntidade, Coordenada intersecao){
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::platforma){
        // Fixa o inimigo em cima da plataforma
        Coordenada p;
        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
        this->setPosicao(p);
        
        // Se estiver na borda da plataforma inverte a direção e para de seguir o jogador
        jogTaPerto = false;
        if((this->getPosicao().x <= outraEntidade->getPosicao().x) || (this->getPosicao().x + this->getTamanho().x >= outraEntidade->getPosicao().x + outraEntidade->getTamanho().x)) {
            setVelocidade(-1.f * velocidade);
        }
    } else if(intersecao.y <= intersecao.x && outraEntidade->getID() == ID::jogador) {
        Coordenada p = this->getPosicao();
        if(p.x < outraEntidade->getPosicao().x)
            p.x -= RECUO;
        else
            p.x += RECUO;
        this->setPosicao(p);
    }
}

// Verifica se o jogador esta perto do inimigo
void InimigoTerrestre::alarmado() {
    Coordenada coordJog, coordIni;
    int diferenca;

    coordJog = pJogador->getPosicao();
    coordIni = this->getPosicao();

    diferenca = coordJog.x - coordIni.x;
    
    if(fabs(diferenca)<=100)
        jogTaPerto = true;
}

// Movimenta o inimigo
void InimigoTerrestre::movimentar() {
    Coordenada coordJog, coordIni;
    coordIni = this->getPosicao();
    coordJog = pJogador->getPosicao();
    
    // Se jogador estiver proximo, siga-o
    if(jogTaPerto){
        if(coordIni.x < coordJog.x){
            velocidade = VELOCIDADE * 2.f;
        }
        else{
            velocidade = VELOCIDADE * (-2.f);
        }
    }
    
    coordIni.x += velocidade;
    this->setPosicao(coordIni);

}

void InimigoTerrestre::executar(){
    alarmado();
    movimentar();

}