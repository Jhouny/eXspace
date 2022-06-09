#include "../../../../include/Ente/Entidades/Dinamicas/Chefe.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoVoador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Menus/Fases/Fase.h"

#define TEX_PROJETIL_CHEFE "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil_2.png"
#define DISTANCIA_ALARMADO_PROJ COMPRIMENTO/2.f
#define DISTANCIA_ALARMADO COMPRIMENTO/3.f
#define VELOCIDADE 19600 * TICK_RATE
namespace Entidades::Personagens {
    Chefe::Chefe():
        Inimigo(Coordenada(252,208),Coordenada(100,100),ID::chefe,false,300,30),
        danoColisao(60)
    {
        this->setVelocidade(Coordenada(0,0));
        this->setAceleracao(GRAVIDADE);
        this->setEstatico(false); //nao precisa

        jogTaPerto = false;
        alarmadoProj = false;
        
        //this->getSprite()->setOrigin(sf::Vector2f(tamanho.x/2.f, 0));
        this->setTexture(TEX_CHEFE);
    }
    Chefe::~Chefe(){

    }

    bool Chefe::estaVivo() {
        if(vida <= 0) {
            this->setAtivo(false);
        }
    }

    void Chefe::colisao(Entidade* outraEntidade, Coordenada intersecao){
        if(outraEntidade->getID() == ID::projetil){
            Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
            Chefe *tmp2 = dynamic_cast<Chefe*>(tmp->getOrigem());
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
        //se o jogador estiver perto, mas nem tanto, atira 3 projeteis em direção dele
        if(getSegundos() > 0.8 && !jogTaPerto && alarmadoProj) {
            this->setTexture(TEX_CHEFE);
            velocidade.x = 0;
            Coordenada direcao;
            Coordenada veloc;
            Coordenada centroJog;
            centroJog.x = pJogador->getPosicao().x  +  pJogador->getTamanho().x/2.f;
            centroJog.y = pJogador->getPosicao().y  +  pJogador->getTamanho().y/2.f;
            
            direcao.x = centroJog.x - posicao.x;
            direcao.y = centroJog.y - (posicao.y + tamanho.y/2.f);

            if(direcao.x > 0) {
                direcao.x = centroJog.x - (posicao.x + tamanho.x + 1);
            } else {
                direcao.x = centroJog.x - (posicao.x - 12.5);
            }

            float hip = sqrt(direcao.x*direcao.x + direcao.y*direcao.y);

            veloc.x = VELOCIDADE_PROJETIL * direcao.x/hip;
            veloc.y = VELOCIDADE_PROJETIL * direcao.y/hip;

            if(direcao.x > 0) { //jogador esta na direita
                pProj = new Projetil (Coordenada(posicao.x + tamanho.x + 1, posicao.y + tamanho.y/2.f), TAM_PROJETIL_CHEFE, veloc.x, veloc.y, dano, TEX_PROJETIL_CHEFE);
                pProj->setEntOrigem(static_cast<Entidade*>(this));
                pFase->incluir(static_cast<Entidade*>(pProj));
            }      
            else { //jogador esta na esquerda
                pProj = new Projetil (Coordenada(posicao.x - 25, posicao.y + tamanho.y/2.f), TAM_PROJETIL_CHEFE, veloc.x, veloc.y, dano, TEX_PROJETIL_CHEFE);
                pProj->setEntOrigem(static_cast<Entidade*>(this));
                pFase->incluir(static_cast<Entidade*>(pProj));
            }
            this->reiniciarClock();
        }
        //caso o jogador estiver perto, persegui-lo
        else if(jogTaPerto) {
            this->setTexture(TEX_CHEFE_ALARMADO);
            Coordenada coordJog, coordChefe, v;
            coordChefe = this->getPosicao();
            coordJog = pJogador->getPosicao();
            v = this->getVelocidade();
            v.y += this->getAceleracao();
            
            if(coordChefe.x < coordJog.x)
                v.x = VELOCIDADE ;
            else
                v.x = VELOCIDADE * (-1);
            this->setVelocidade(v);
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
  
    void Chefe::movimentar(const float dt){
        Coordenada coordChefe, v;
        coordChefe = this->getPosicao();
        v = this->getVelocidade();
        v.y += this->getAceleracao();
        coordChefe.y += v.y * dt;
        coordChefe.x += v.x * dt;
        this->setPosicao(coordChefe);
    }


    void Chefe::executar(const float dt){
        alarmadoProjetil(DISTANCIA_ALARMADO_PROJ);
        alarmado(DISTANCIA_ALARMADO);
        atacar();
        atualizaTexture(velocidade);
        movimentar(dt);
        estaVivo();
    }
}