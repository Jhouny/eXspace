#include "../../../../include/Ente/Entidades/Dinamicas/Chefe.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoVoador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Menus/Fase.h"

#define TEX_PROJETIL_INI_VOADOR "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil_2.png"
#define DISTANCIA_ALARMADO_PROJ 1000
#define DISTANCIA_ALARMADO 500
Chefe::Chefe():
    Inimigo(Coordenada(300,300),Coordenada(100,100),ID::chefe,false)
{
    alarmadoProj = false;

}
Chefe::~Chefe(){

}



void Chefe::colisao(Entidade* outraEntidade, Coordenada intersecao){
    if(outraEntidade->getID()==ID::projetil){
        Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
        InimigoVoador *tmp2 = dynamic_cast<InimigoVoador*>(tmp->getOrigem()); 
        if(tmp2 == NULL){ // se não for originario do mesmo 
            this->receberDano(tmp->getDano());
        }
    }
    else if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma) {
        pPlataforma = outraEntidade;
        // Fixa o inimigo em cima da plataforma
        Coordenada p;
        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
        this->setPosicao(p);
        
        Coordenada v = this->getVelocidade();
        v.y = 0;
        
        this->setVelocidade(v);

    } 

}

void Chefe::atacar(){
    if(getSegundos() > 0.6 && !jogTaPerto && alarmadoProj) {
        Coordenada direcao;
        Coordenada veloc;
        Coordenada centroJog;
        centroJog.x = pJogador->getPosicao().x  +  pJogador->getTamanho().x/2.f;
        centroJog.y = pJogador->getPosicao().y  +  pJogador->getTamanho().y/2.f;
        
        direcao.x = centroJog.x - posicao.x;
        direcao.y = centroJog.y - posicao.y;

        if(direcao.x > 0) {
            direcao.x = centroJog.x - (posicao.x + tamanho.x + 1);
        } else {
            direcao.x = centroJog.x - (posicao.x - 12.5);
        }

        float hip = sqrt(direcao.x*direcao.x + direcao.y*direcao.y);

        veloc.x = VELOCIDADE_PROJETIL * direcao.x/hip;
        veloc.y = VELOCIDADE_PROJETIL * direcao.y/hip;

        if(direcao.x > 0) { //jogador esta na direita
            pProj = new Projetil (Coordenada(posicao.x + tamanho.x + 1, posicao.y + tamanho.y/2.f), TAM_PROJETIL_CHEFE, veloc.x, veloc.y, dano, TEX_PROJETIL_INI_VOADOR);
        }      
        else { //jogador esta na esquerda
            pProj = new Projetil (Coordenada(posicao.x - 12.5, posicao.y + tamanho.y/2.f), TAM_PROJETIL_CHEFE, veloc.x, veloc.y, dano, TEX_PROJETIL_INI_VOADOR);
        }
        pProj->setEntOrigem(static_cast<Entidade*>(this));
        pFase->incluir(static_cast<Entidade*>(pProj));
        this->reiniciarClock();
    }

}

void Chefe::alarmadoProjetil(int dist){
    Coordenada centroIni,  centroJog, intersecao;
    float diferenca;
    
    centroIni.x = this->getPosicao().x + (this->getTamanho().x)/2.f;
    centroIni.y = this->getPosicao().y + (this->getTamanho().y)/2.f;
    
    centroJog.x = pJogador->getPosicao().x + (pJogador->getTamanho().x)/2.f;
    centroJog.y = pJogador->getPosicao().y + (pJogador->getTamanho().y)/2.f;;
    
    intersecao.x = fabs(centroJog.x - centroIni.x) - (this->getTamanho().x + pJogador->getTamanho().x)/2.f;
    intersecao.y = fabs(centroJog.y - centroIni.y) - (this->getTamanho().y + pJogador->getTamanho().y)/2.f;

    diferenca = sqrtf(intersecao.x*intersecao.x + intersecao.y*intersecao.y);
    
    if(fabs(diferenca) <= dist)
        alarmadoProj = true;
    else
        alarmadoProj = false;

}


void Chefe::atualiza(const float dt){

}

void Chefe::movimentar(const float dt){

}


void Chefe::executar(const float dt){
    alarmadoProjetil(DISTANCIA_ALARMADO_PROJ);
    alarmado(DISTANCIA_ALARMADO);
    atacar();

}
