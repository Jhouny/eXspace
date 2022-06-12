#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"

#define VELOCIDADE 12800 * TICK_RATE
#define RECUO 100

namespace Entidades::Personagens {
    InimigoTerrestre::InimigoTerrestre():
        Inimigo(Coordenada(50,50),Coordenada(100,100),ID::inimigoTerrestre, false)
    {   
        this->setVelocidade(Coordenada((float)VELOCIDADE, 0.f));
        this->setAceleracao(GRAVIDADE);
        this->setEstatico(false);

        pJogador2=NULL;
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
    //Colisao do inimigoTerrestre
    void InimigoTerrestre::colisao(Entidade* outraEntidade, Coordenada intersecao) {
        if(outraEntidade->getID()==ID::projetil){
            Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
            InimigoTerrestre *tmp2 = dynamic_cast<InimigoTerrestre*>(tmp->getOrigem()); 
            if(tmp2 == NULL){ // se não for originario do mesmo 
                this->receberDano(tmp->getDano());
            }
        } else if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma) {
            // Fixa o inimigo em cima da plataforma
            pPlataforma = outraEntidade;
            Coordenada p;
            p.x = this->getPosicao().x;
            p.y = outraEntidade->getPosicao().y - this->getTamanho().y;
            velocidade.y = 0;
            this->setPosicao(p);

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
    
    // Define a velocidade e textura de ataque
    void InimigoTerrestre::atacar() {
        Coordenada coordJog;
        if(pJogador1->estaVivo())
            coordJog = pJogador1->getPosicao();
        else if(pJogador2 != NULL && pJogador2->estaVivo() && !pJogador1->estaVivo())
            coordJog = pJogador2->getPosicao();
        
         // Se jogador estiver proximo, siga-o
        if(jogTaPerto) {
            setTexture(TEX_INIMIGO_TERRESTRE_ALARMADO);
            if(posicao.x < coordJog.x)
                velocidade.x = VELOCIDADE * 2;
            else
                velocidade.x = VELOCIDADE * (-2);
        } else {
            setTexture(TEX_INIMIGO_TERRESTRE);
            if(velocidade.x > 0)
                velocidade.x = VELOCIDADE;
            else
                velocidade.x = -1 * VELOCIDADE;
        }
    }

    // Movimenta o inimigo
    void InimigoTerrestre::movimentar(const float dt) {
        Coordenada coordJog, coordIni;
        coordIni = this->getPosicao();
        if(pJogador1->estaVivo())
            coordJog = pJogador1->getPosicao();
        else if(pJogador2 != NULL && pJogador2->estaVivo() && !pJogador1->estaVivo())
            coordJog = pJogador2->getPosicao();

        if(temporizador.getElapsedTime().asSeconds() > 3) {  // A cada três segundos roda uma chance para inverter a direção
            int chance = rand() % 100;
            if(chance < 10 && !jogTaPerto)  // Chance de 10%
                velocidade.x *= -1;
            temporizador.restart();
        }
        
        // Se estiver na borda da plataforma e (jogador não esta perto ou jogador está acima do inimigo) inverte a direção
        if(pPlataforma && (!jogTaPerto || coordJog.y < coordIni.y - 100)) {
            if(this->getPosicao().x <= pPlataforma->getPosicao().x && velocidade.x < 0)
                velocidade.x = VELOCIDADE;
            else if((this->getPosicao().x + this->getTamanho().x >= pPlataforma->getPosicao().x + pPlataforma->getTamanho().x) && velocidade.x > 0)
                velocidade.x = -1*VELOCIDADE;
        }

        velocidade.y += this->getAceleracao();
        coordIni.x += velocidade.x * dt;
        coordIni.y += velocidade.y * dt;

        this->setPosicao(coordIni);
    }

    void InimigoTerrestre::executar(const float dt) {
        alarmado(300);
        atacar();
        atualizaTexture(velocidade);  // Deve estar acima do movimentar(dt)
        movimentar(dt);
        estaVivo();
    }
}