#include "../../../include/Entidades/Dinamicas/InimigoTerrestre.h"

#define VELOCIDADE 5
#define RECUO 50

InimigoTerrestre::InimigoTerrestre(Coordenada tam, Coordenada pos, int v, int d, ID id):
    Inimigo(tam,pos,v,d,id),
    velocidade(VELOCIDADE),
    jogTaPerto(false)
{   
    this->setAceleracao(GRAVIDADE);
    shape.setFillColor(sf::Color::Red);
    pJogador=NULL;
}

InimigoTerrestre::~InimigoTerrestre() { }

void InimigoTerrestre::estaVivo() {}

void InimigoTerrestre::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::platforma){
        // Fixa o inimigo em cima da plataforma
        Coordenada p;
        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
        this->setPosicao(p);
        
        this->setAceleracao(0);
        Coordenada v = this->getVelocidade();
        v.y = 0;
        
        // Se estiver na borda da plataforma inverte a direção e para de seguir o jogador
        jogTaPerto = false;
        if((this->getPosicao().x <= outraEntidade->getPosicao().x) || (this->getPosicao().x + this->getTamanho().x >= outraEntidade->getPosicao().x + outraEntidade->getTamanho().x)) {
            v.x *= -1;
        }
        this->setVelocidade(v);

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
    Coordenada coordJog, coordIni, v;
    coordIni = this->getPosicao();
    coordJog = pJogador->getPosicao();
    
    v = this->getVelocidade();
    v.y += this->getAceleracao();
    coordIni.y += v.y;

    // Se jogador estiver proximo, siga-o
    if(jogTaPerto){
        if(coordIni.x < coordJog.x){
            velocidade.x = VELOCIDADE * 2.f;
        }
        else{
            velocidade.x = VELOCIDADE * (-2.f);
        }
    }
    
    coordIni.x += velocidade.x;
    this->setPosicao(coordIni);
    this->setVelocidade(v);
}

void InimigoTerrestre::executar() {
    //alarmado();
    movimentar();

}