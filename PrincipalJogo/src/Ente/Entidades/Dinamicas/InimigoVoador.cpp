#include "../../../../include/Ente/Entidades/Dinamicas/InimigoVoador.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Projetil.h"
#include "../../../../include/Ente/Menus/Fases/Fase.h"

#define DISTANCIA_ALARME 500

#define TEX_PROJETIL_INI_VOADOR "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil_2.png"

namespace Entidades::Personagens {
    InimigoVoador::InimigoVoador():
        Inimigo(Coordenada(50,50),Coordenada(0,0),ID::inimigoVoador,false,150,15)
    {   
        velocidade.x = 1;
        setTexture(TEX_INIMIGO_VOADOR);
        setAceleracao(GRAVIDADE);
    }

    InimigoVoador::~InimigoVoador() {

    }

    void InimigoVoador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
        if(outraEntidade->getID()==ID::projetil){
            Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
            InimigoVoador *tmp2 = dynamic_cast<InimigoVoador*>(tmp->getOrigem()); 
            if(tmp2 == NULL){ // se não for originario do mesmo 
                this->receberDano(tmp->getDano());
            }
        }

    }
    void InimigoVoador::atacar() {
        if(getSegundos() > 1 && jogTaPerto) {
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
                pProj = new Projetil(Coordenada(posicao.x + tamanho.x + 1, posicao.y + tamanho.y/2.f), TAM_PROJETIL_INI_VOADOR, veloc.x, veloc.y, dano, TEX_PROJETIL_INI_VOADOR);
            }      
            else { //jogador esta na esquerda
                pProj = new Projetil(Coordenada(posicao.x - 12.5, posicao.y + tamanho.y/2.f), TAM_PROJETIL_INI_VOADOR, veloc.x, veloc.y, dano, TEX_PROJETIL_INI_VOADOR);
            }
            pProj->setEntOrigem(static_cast<Entidade*>(this));
            pFase->incluir(static_cast<Entidade*>(pProj));
            this->reiniciarClock();
        }
    }

    void InimigoVoador::atualiza(const float dt) {
        if(pJogador->getPosicao().x > posicao.x) {
            velocidade.x = 1;
        } else {
            velocidade.x = -1;
        }
    }

    bool InimigoVoador::estaVivo(){
        if(vida <= 0) {
            setAtivo(false);
            return false;
        }
        return true;
    }

    void InimigoVoador::randomizarOscilacao() {
        pontoMedio = posicao.y + (rand()%40) + 50;
    }

    void InimigoVoador::movimentar(const float dt) {
        if(posicao.y < pontoMedio && getAceleracao() < 0)  // Acima do ponto mais alto
            setAceleracao(2 * GRAVIDADE);
        else if(posicao.y > pontoMedio && getAceleracao() > 0)  // Abaixo do ponto mais baixo
            setAceleracao(-2 * GRAVIDADE);
        
        velocidade.y += getAceleracao()*dt;
        Coordenada pos = getPosicao();
        pos.x += velocidade.x * dt;
        pos.y += velocidade.y * dt;
        setPosicao(pos);
    }

    void InimigoVoador::executar(const float dt){
        atualizaTexture(velocidade);
        movimentar(dt);

        atacar();

        alarmado(DISTANCIA_ALARME);
        
        atualiza(dt);

        estaVivo();
    }
}