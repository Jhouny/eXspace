#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Inimigo.h"
#include "../../../../include/Ente/Menus/Fases/Fase.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../../../include/Ente/Entidades/Dinamicas/Chefe.h"
#include "../../../../include/Ente/Entidades/Estaticas/Lava.h"


#define PULO_Y -256000 * TICK_RATE
#define ATRITO 0.7
#define VELOCIDADE_JOGADOR 76800 * TICK_RATE 
#define POS_INICIAL Coordenada(100, 0)


namespace Entidades::Personagens {
    Jogador::Jogador():
        Personagem(Coordenada(54, 68), POS_INICIAL, false, VIDA_MAX, 20, ID::jogador),
        pControleJogador(this),
        pontuacao(0)
        {
            setJump(false);
            estaPulando = false;
            estaAtirando = false;
            viradoFrente = true;

            if(getRG() == 0) {  // Jogadores DEVEM ser as primeiras entidades!!
                // Define a textura
                this->getSprite()->setOrigin(sf::Vector2f(tamanho.x/3.f, 0));
                setTexture(TEX_JOGADOR);
            } else {
                // Define a textura
                this->getSprite()->setOrigin(sf::Vector2f(tamanho.x/3.f, 0));
                setTexture(TEX_JOGADOR_2);
            }
            
            velocidade.x = 0.f;
            velocidade.y = 0.f;
            aceleracaoY = 10;
    }

    Jogador::~Jogador() {}

    bool Jogador::estaVivo() {
        Coordenada p = this->getPosicao();
        if(p.y > ALTURA + 300 || vida <= 0) {
            vida = 0;
            vivo = false;
            setAtivo(false);
        } else {
            vivo = true;
        }

        return vivo;
    }

     void Jogador::aumentaPontuacao(ID identificacao){
        switch(identificacao){
            case ID::inimigoTerrestre:
                pontuacao+=100;
                break;
            case ID::inimigoVoador:
                pontuacao+=150;
                break;
            case ID::chefe:
                pontuacao+=1000;
                break;
        }
     }

    void Jogador::atacar() {
        if(this->getSegundos() > 0.05) {
            if(viradoFrente)
                proj = new Projetil(Coordenada(this->getPosicao().x + this->getTamanho().x + 1, this->getPosicao().y + this->getTamanho().y/2.f - 3), TAM_PROJETIL_JOGADOR, VELOCIDADE_JOGADOR*3);
            else
                proj = new Projetil(Coordenada(this->getPosicao().x  - 12.5, this->getPosicao().y + this->getTamanho().y/2.f - 3), TAM_PROJETIL_JOGADOR, -VELOCIDADE_JOGADOR*3);
            proj->setEntOrigem(static_cast<Entidade*>(this));
            pFase->incluir(static_cast<Entidade*>(proj)); 
            this->reiniciarClock();
        }
    }

    void Jogador::ataque(bool estado) {
        estaAtirando = estado;
    }

    void Jogador::direita() {
        viradoFrente = true;
        velocidade.x = VELOCIDADE_JOGADOR;
    }

    void Jogador::esquerda() { 
        viradoFrente = false;
        velocidade.x = -1 * VELOCIDADE_JOGADOR;
    }

    void Jogador::pular() {
        if(pulando == false) {
            //impede de dar double jump
            posicao.y -= 1;
            velocidade.y = PULO_Y;
            pulando = true;
        }
    }

    void Jogador::pulo(bool estado) {
        estaPulando = estado;
    }

    void Jogador::parar() {
        velocidade.x = 0; // Para instantaneamente
    }

    void Jogador::resetar(int p) {
        setPontuacao(p);
        setPosicao(POS_INICIAL);
        setVida(VIDA_MAX);
        setAtivo(true);
        setJump(false);
        estaPulando = false;
        estaAtirando = false;
        viradoFrente = true;
        velocidade.x = 0.f;
        velocidade.y = 0.f;
        aceleracaoY = 10;

        pControleJogador.resetarTeclas();

        // Define a textura
        if(getRG() == 0)
            setTexture(TEX_JOGADOR);
        else
            setTexture(TEX_JOGADOR_2);
    }

    // Checa com que tipo de objeto colidiu
    void Jogador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
        //colisao com a lava
        if(outraEntidade->getID() == ID::lava) {
            Entidades::Obstaculos::Lava *tmp = dynamic_cast<Entidades::Obstaculos::Lava*>(outraEntidade);
            this->receberDano(tmp->getDano());
        }
        else if(outraEntidade->getID() == ID::gasToxico) {
            Entidades::Obstaculos::GasToxico *tmp = dynamic_cast<Entidades::Obstaculos::GasToxico*>(outraEntidade);
            this->receberDano(tmp->getDano());
        }
        else if(outraEntidade->getID() == ID::projetil) {
            Entidades::Projetil *tmp = dynamic_cast<Projetil*>(outraEntidade);
            // Se o projetil não for nulo, se sua origem não for nula e se não vier do mesmo tipo de Entidade
            if(tmp != NULL && tmp->getOrigem() != NULL && tmp->getOrigem()->getID() != ID::jogador)
                this->receberDano(tmp->getDano());
        }
        else if(intersecao.x <= intersecao.y && (outraEntidade->getID() == ID::plataforma ||outraEntidade->getID() == ID::rocha)) {  //Se intersectou antes no x que no Y (i.e. colidiu verticalmente com a plataforma)
            Coordenada p = this->getPosicao();
            Coordenada v = this->getVelocidade();
            
            if(this->getPosicao().y <= outraEntidade->getPosicao().y) {  // Se colidir em cima
                v.y = 0;  // Define a velocidade vertical para 0
                p.y = outraEntidade->getPosicao().y - this->getTamanho().y;  // Define a posição em cima da plataforma
                this->setJump(false);
            } else {  // Se colidir embaixo
                v.y = -1 * v.y * ATRITO;
                p.y = outraEntidade->getPosicao().y + outraEntidade->getTamanho().y;  // Define a posição em cima da plataforma
            }

            this->setVelocidade(v);
            this->setPosicao(p);

        } else if(intersecao.y <= intersecao.x) {
            if(outraEntidade->getID() == ID::plataforma || outraEntidade->getID() == ID::rocha){ // Se está do lado, não deixa atravessar o objeto
                if (this->getPosicao().x < outraEntidade->getPosicao().x) {
                    this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
                } else {
                    this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
                }
            } else if(outraEntidade->getID() == ID::inimigoTerrestre) {
                InimigoTerrestre *tmp = dynamic_cast<InimigoTerrestre*>(outraEntidade);
                // Reduz a vida do jogador 
                if(tmp->getCarga()) {  // Se puder dar dano
                    this->receberDano(tmp->getDano());
                    tmp->setCarga(false);
                    tmp->reiniciarClock();
                }
                if (this->getPosicao().x < outraEntidade->getPosicao().x){
                    this->setPosicao(this->getPosicao().x, this->getPosicao().y);

                } else {
                    this->setPosicao(this->getPosicao().x, this->getPosicao().y);
                }                
            } else if(outraEntidade->getID() == ID::chefe) {
                Chefe *tmp = dynamic_cast<Chefe*>(outraEntidade);
                // Reduz a vida do jogador 
                this->receberDano(tmp->getDanoColisao());
                
                if (this->getPosicao().x < outraEntidade->getPosicao().x){
                    this->setPosicao(this->getPosicao().x, this->getPosicao().y);

                } else {
                    this->setPosicao(this->getPosicao().x, this->getPosicao().y);
                }                
            }
        }
    }

    void Jogador::atualiza(const float dt) {
        Coordenada p = this->getPosicao();
        Coordenada v = this->getVelocidade();

        p.x += v.x * dt;
        v.y += this->getAceleracao();
        p.y += v.y * dt; 

        this->setVelocidade(v);
        this->setPosicao(p);

        if(estaPulando)
            pular();
        if(estaAtirando)
            atacar();

        atualizaAcel();
    }

    void Jogador::atualizaAcel() {
        if(estaPulando) {
            this->setAceleracao(GRAVIDADE);
        }
    }

    void Jogador::executar(const float dt) {
        //seta as sprites
        atualizaTexture(velocidade);

        // Checa se o jogador esta vivo
        estaVivo();
        
        // Aplica a aceleração na velocidade e a velocidade na posição 
        atualiza(dt);
    }
}