#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

#define VELOCIDADE 2
#define RECUO 100

InimigoTerrestre::InimigoTerrestre(Coordenada pos, Coordenada tam, int v, int d, ID id):
    Inimigo(tam,pos,v,d,id),
    jogTaPerto(false)
{   
    this->setVelocidade(Coordenada((float)VELOCIDADE, 0.f));
    this->setAceleracao(GRAVIDADE);
    
    shape.setFillColor(sf::Color::Red);
    pJogador=NULL;
    pPlataforma=NULL;

    setTexture(TEX_INIMIGO_TERRESTRE);
}

InimigoTerrestre::~InimigoTerrestre() { }

void InimigoTerrestre::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300 || vida <= 0) {
        vivo = false;
    }
}

void InimigoTerrestre::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma){
        pPlataforma = outraEntidade;
        // Fixa o inimigo em cima da plataforma
        Coordenada p;
        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
        this->setPosicao(p);
        
        Coordenada v = this->getVelocidade();
        v.y = 0;
        
        this->setVelocidade(v);

    } else if(intersecao.y <= intersecao.x) {
        if( outraEntidade->getID() == ID::jogador){
            Coordenada p = this->getPosicao();
            if(p.x < outraEntidade->getPosicao().x)
                p.x -= RECUO;
            else
                p.x += RECUO;
            this->setPosicao(p);
        }
        else if( outraEntidade->getID() == ID::projetil) {
            Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
            this->receberDano(tmp->getDano());
        }
    }
}

// Verifica se o jogador esta perto do inimigo
void InimigoTerrestre::alarmado() {
    Coordenada centroIni,  centroJog, intersecao;
    float diferenca;
    
    centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
    centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
    
    centroJog.x = pJogador->getPosicao().x + (pJogador->getTamanho().x)/2.f;
    centroJog.y = pJogador->getPosicao().y + (pJogador->getTamanho().y)/2.f;;
    
    intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador->getTamanho().x)/2.f;
    intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador->getTamanho().y)/2.f;

    diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
    
    if(fabs(diferenca) <= 300)
        jogTaPerto = true;
    else
        jogTaPerto = false;
}

// Movimenta o inimigo
void InimigoTerrestre::movimentar() {
    Coordenada coordJog, coordIni, v;
    coordIni = this->getPosicao();
    coordJog = pJogador->getPosicao();
    
    v = this->getVelocidade();
    v.y += this->getAceleracao();
    coordIni.y += v.y;
    
    // Se estiver na borda da plataforma e (jogador não esta perto ou jogador está acima do inimigo) inverte a direção
    if(pPlataforma && (!jogTaPerto || coordJog.y < coordIni.y - 100)) {
        if(this->getPosicao().x <= pPlataforma->getPosicao().x && v.x < 0)
            v.x = VELOCIDADE;
        else if((this->getPosicao().x + this->getTamanho().x >= pPlataforma->getPosicao().x + pPlataforma->getTamanho().x) && v.x > 0)
            v.x = -1*VELOCIDADE;
    }
    
    coordIni.x += v.x;
    
    // Se jogador estiver proximo, siga-o
    if(jogTaPerto) {

        if(coordIni.x < coordJog.x){
            v.x = VELOCIDADE * 2;
        }
        else{
            v.x = VELOCIDADE * (-2);
        }
    }

    this->setPosicao(coordIni);
    this->setVelocidade(v);
}

void InimigoTerrestre::executar() {
    alarmado();
    movimentar();
    estaVivo();
    
    if(!vivo) {
        this->setAtivo(false);
    }
}