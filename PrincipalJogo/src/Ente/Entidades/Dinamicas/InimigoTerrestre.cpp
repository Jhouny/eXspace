#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

#define VELOCIDADE 12800 * TICK_RATE
#define RECUO 100

InimigoTerrestre::InimigoTerrestre():
    Inimigo(Coordenada(50,50),Coordenada(100,100),ID::inimigoTerrestre, false)
{   
    this->setVelocidade(Coordenada((float)VELOCIDADE, 0.f));
    this->setAceleracao(GRAVIDADE);
    this->setEstatico(false);

    pJogador=NULL;
    pPlataforma=NULL;

    setTexture(TEX_INIMIGO_TERRESTRE);
}

InimigoTerrestre::~InimigoTerrestre() { }

bool InimigoTerrestre::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300 || vida <= 0) {
        vivo = false;
        setAtivo(false);
    }

    return vivo;
}

void InimigoTerrestre::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    if(outraEntidade->getID()==ID::projetil){
        Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
        InimigoTerrestre *tmp2 = dynamic_cast<InimigoTerrestre*>(tmp->getOrigem()); 
        if(tmp2 == NULL){ // se não for originario do mesmo 
            this->receberDano(tmp->getDano());
        }
    }
    
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma) {
        pPlataforma = outraEntidade;
        // Fixa o inimigo em cima da plataforma
        Coordenada p;
        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
        this->setPosicao(p);
        
        Coordenada v = this->getVelocidade();
        v.y = 0;
        
        this->setVelocidade(v);

    } else if(intersecao.y < intersecao.x && outraEntidade->getID() != ID::plataforma) {
        if(outraEntidade->getID() == ID::jogador) {
            Coordenada p = this->getPosicao();
            if(p.x < outraEntidade->getPosicao().x)
                p.x -= RECUO;
            else
                p.x += RECUO;
            this->setPosicao(p);
        }
        if(outraEntidade->getID() == ID::inimigoTerrestre) {
            if (this->getPosicao().x < outraEntidade->getPosicao().x) {
                this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
            } else {
                this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
            }
            velocidade.x *= -1;  // Inverte a direção
        }
    }
}


// Movimenta o inimigo
void InimigoTerrestre::movimentar(const float dt) {
    Coordenada coordJog, coordIni, v;
    coordIni = this->getPosicao();
    coordJog = pJogador->getPosicao();
    
    v = this->getVelocidade();
    v.y += this->getAceleracao();
    coordIni.y += v.y * dt;
    
    // Se estiver na borda da plataforma e (jogador não esta perto ou jogador está acima do inimigo) inverte a direção
    if(pPlataforma && (!jogTaPerto || coordJog.y < coordIni.y - 100)) {
        if(this->getPosicao().x <= pPlataforma->getPosicao().x && v.x < 0)
            v.x = VELOCIDADE;
        else if((this->getPosicao().x + this->getTamanho().x >= pPlataforma->getPosicao().x + pPlataforma->getTamanho().x) && v.x > 0)
            v.x = -1*VELOCIDADE;
    }
    
    coordIni.x += v.x * dt;
    
    // Se jogador estiver proximo, siga-o
    if(jogTaPerto) {
        setTexture(TEX_INIMIGO_TERRESTRE_ALARMADO);
        if(coordIni.x < coordJog.x)
            v.x = VELOCIDADE * 2;
        else
            v.x = VELOCIDADE * (-2);
    } else {
        setTexture(TEX_INIMIGO_TERRESTRE);
        if(v.x > 0)
            v.x = VELOCIDADE;
        else
            v.x = -1 * VELOCIDADE;
    }

    this->setPosicao(coordIni);
    this->setVelocidade(v);
}

void InimigoTerrestre::executar(const float dt) {
    alarmado(300);
    movimentar(dt);
    estaVivo();
    atualizaTexture();  // Deve estar abaixo do movimentar(dt)
    
    if(!vivo) {
        this->setAtivo(false);
    }
}