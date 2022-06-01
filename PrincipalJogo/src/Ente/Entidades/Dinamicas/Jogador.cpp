#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Inimigo.h"
#include "../../../../include/Ente/Fase/Fase.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"

#define PULO_Y -35
#define ATRITO 0.7
#define VELOCIDADE_JOGADOR 30

Jogador::Jogador():
    Personagem(Coordenada(46, 64), Coordenada(0,0), false, 100, 20, ID::jogador),
    pControle(this),
    andando(false)
    {
        setJump(true);
        velocidade.x = 0.f;
        velocidade.y = 0.f;
        aceleracaoY = 10;

        // Define a textura
        setTexture(TEX_JOGADOR);
}

Jogador::~Jogador() {}

void Jogador::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300 || vida<=0) {
        vivo = false;
    }
}

void Jogador::atacar() {
    if(this->getSegundos() > 0.3) {
        if(this->getVelocidade().x >= 0)
            proj = new Projetil(Coordenada(this->getPosicao().x + this->getTamanho().x + 1, this->getPosicao().y + this->getTamanho().y/2.f - 9));  // ADICIONAR VELOCIDADE            
        else if(this->getVelocidade().x < 0)
            proj = new Projetil(Coordenada(this->getPosicao().x  - 1, this->getPosicao().y + this->getTamanho().y/2.f - 9), -20);
        
        
        pFase->incluir(static_cast<Entidade*>(proj));
        this->reiniciarClock();
    }
}

void Jogador::direita() {
    andando = true;
    velocidade.x = VELOCIDADE_JOGADOR;
}

void Jogador::esquerda() { 
    andando = true;
    velocidade.x = -1 * VELOCIDADE_JOGADOR;
}

void Jogador::pular() { 
    if(pulando == false) {
        //impede de dar double jump
        this->setAceleracao(0);  // PRECISA disso
        pulando = true;
    }

}


// Checa com que tipo de objeto colidiu
void Jogador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::plataforma) {  //Se intersectou antes no x que no Y (i.e. colidiu verticalmente com a plataforma)
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

        if(outraEntidade->getID() == ID::plataforma){ // Se está do lado, não deixa atravessar o objeto
            if (this->getPosicao().x < outraEntidade->getPosicao().x) {
                this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
            } else {
                this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
            }
        } else if(outraEntidade->getID() == ID::inimigoTerrestre) {
            //Inimigo *tmp = dynamic_cast<Inimigo*>(outraEntidade);
            // Reduz a vida do jogador 
            //this->receberDano(tmp->getDano());
            //cout << "vida: " << vida << endl;
            if (this->getPosicao().x < outraEntidade->getPosicao().x){
                this->setPosicao(this->getPosicao().x, this->getPosicao().y);    
            } else {
                this->setPosicao(this->getPosicao().x, this->getPosicao().y);
            }                
        }
        this->setJump(true); // Para não poder pular se encostar lateralmente
    }
}

void Jogador::atualiza(const float dt) {
    Coordenada p = this->getPosicao();
    Coordenada v = this->getVelocidade();

    if(andando) {
        p.x += v.x * dt;
    }
    if(pulando) {
        v.y += this->getAceleracao();
        p.y += v.y * dt;
    }

    this->setVelocidade(v);
    this->setPosicao(p);

    atualizaAcel();
}

void Jogador::atualizaAcel() {
    if(this->getPulo()) {
        this->setAceleracao(GRAVIDADE);
    }
}

void Jogador::executar(const float dt) {
    //seta as sprites
    atualizaTexture();
    
    // Aplica a aceleração na velocidade e a velocidade na posição 
    atualiza(dt);
    
    // Checa se o jogador esta vivo e o atualiza
    estaVivo();

    

    // Se o jogador morrer
    if(!vivo) {
        pGrafico->terminar();  // Fecha a janela, mas no fim deveria dar um 'Game Over'
    }
}

