#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Inimigo.h"
#include "../../../../include/Ente/Menus/Fase.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../../../include/Ente/Entidades/Estaticas/Lava.h"


#define PULO_Y -256000 * TICK_RATE
#define ATRITO 0.7
#define VELOCIDADE_JOGADOR 76800 * TICK_RATE 

Jogador::Jogador():
    Personagem(Coordenada(46, 64), Coordenada(0,0), false, 100, 20, ID::jogador),
    pControleJogador(this),
    pontuacao(0)
    {
        setJump(false);
        estaPulando = false;
        estaAtirando = false;
        viradoFrente = true;
        
        velocidade.x = 0.f;
        velocidade.y = 0.f;
        aceleracaoY = 10;

        // Define a textura
        setTexture(TEX_JOGADOR);
}

Jogador::~Jogador() {}

bool Jogador::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300 || vida<=0) {
        vivo = false;
    }

    return vivo;
}

void Jogador::atacar() {
    if(this->getSegundos() > 0.15) {
        if(viradoFrente)
            proj = new Projetil(Coordenada(this->getPosicao().x + this->getTamanho().x + 1, this->getPosicao().y + this->getTamanho().y/2.f - 3), VELOCIDADE_JOGADOR*3);  // ADICIONAR VELOCIDADE            
        else
            proj = new Projetil(Coordenada(this->getPosicao().x  - 12.5, this->getPosicao().y + this->getTamanho().y/2.f - 3), -VELOCIDADE_JOGADOR*3);
        
        
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
    cout << "pulo1" << endl;
    if(pulando == false) {
        cout << "pulo2" << endl;
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
    //velocidade.x *= 0.3;
}


// Checa com que tipo de objeto colidiu
void Jogador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    //colisao com a lava
    if(outraEntidade->getID() == ID::lava) {
        Lava *tmp = dynamic_cast<Lava*>(outraEntidade);
        this->receberDano(tmp->getDano());
    }


    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma) {  //Se intersectou antes no x que no Y (i.e. colidiu verticalmente com a plataforma)
        Coordenada p = this->getPosicao();
        Coordenada v = this->getVelocidade();
        
        if(this->getPosicao().y <= outraEntidade->getPosicao().y) {  // Se colidir em cima
            v.y = 0;  // Define a velocidade vertical para 0
            p.y = outraEntidade->getPosicao().y - this->getTamanho().y;  // Define a posição em cima da plataforma
            cout << "jump false colisao plat" << endl;
            this->setJump(false);

        } else {  // Se colidir embaixo
            v.y = -1 * v.y * ATRITO;
            p.y = outraEntidade->getPosicao().y + outraEntidade->getTamanho().y;  // Define a posição em cima da plataforma
        }

        this->setVelocidade(v);
        this->setPosicao(p);

    } else if(intersecao.y <= intersecao.x) {

        if(outraEntidade->getID() == ID::plataforma){ // Se está do lado, não deixa atravessar o objeto
            if (this->getPosicao().x < outraEntidade->getPosicao().x) {
                this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
            } else {
                this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
            }
        } else if(outraEntidade->getID() == ID::inimigoTerrestre) {
            Inimigo *tmp = dynamic_cast<Inimigo*>(outraEntidade);
            // Reduz a vida do jogador 
            this->receberDano(tmp->getDano());
            //cout << "vida: " << vida << endl;
            if (this->getPosicao().x < outraEntidade->getPosicao().x){
                this->setPosicao(this->getPosicao().x, this->getPosicao().y);

            } else {
                this->setPosicao(this->getPosicao().x, this->getPosicao().y);
            }                
        }
        cout << "RGs: " << this->getRG() << "\t " << outraEntidade->getRG() << endl;
        cout <<"ID: " << outraEntidade->getID() << intersecao.x << intersecao.y << endl;
        this->setJump(true); // Para não poder pular se encostar lateralmente
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
    atualizaTexture();
    
    // Aplica a aceleração na velocidade e a velocidade na posição 
    atualiza(dt);
}

