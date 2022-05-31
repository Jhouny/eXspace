#include "../../../../include/Ente/Entidades/Dinamicas/Jogador.h"
#include "../../../../include/Ente/Entidades/Inimigo.h"
#include "../../../../include/Ente/Fase/Fase.h"
#include "../../../../include/Ente/Entidades/Dinamicas/InimigoTerrestre.h"

#define PULO_Y -35
#define ATRITO 0.7

Jogador::Jogador():
    Personagem(Coordenada(46, 64), Coordenada(0,0), false, 100, 20, ID::jogador)
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
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->getSegundos() > 1) {
            if(this->getVelocidade().x >= 0)
                proj = new Projetil(Coordenada(this->getPosicao().x + 60, this->getPosicao().y + this->getTamanho().y/2.f));  // ADICIONAR VELOCIDADE            
            else if(this->getVelocidade().x<0){
                proj = new Projetil(Coordenada(this->getPosicao().x  - 20, this->getPosicao().y + this->getTamanho().y/2.f),-20);
            }
            
            pFase->incluir(static_cast<Entidade*>(proj));
            this->reiniciarClock();
        }  
}

void Jogador::movimentar() {
    Coordenada p = this->getPosicao();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(velocidade.x<0)
            velocidade.x*=-1;
        p += velocidade.x;  // Move com velocidade constante negativa no eixo X
        setVelocidade(velocidade);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(velocidade.x>0)
            velocidade.x*=-1;
        p += velocidade.x;  // Move com velocidade constante negativa no eixo X
        setVelocidade(velocidade);
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getPulo() == false) {
        // Adiciona um 'pulo' vertical - defini uma velocidade em Y negativa (para cima)
        Coordenada v = this->getVelocidade();
        v.y = PULO_Y;
        this->setVelocidade(v);
        
        p.y -= velocidade.y;
        this->setAceleracao(0);  // PRECISA disso
        this->setJump(true);
    }

    // Atualiza a posição do sprite e da instância
    this->setPosicao(p);
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

void Jogador::aplicaAcel() {
    Coordenada p = this->getPosicao();
    Coordenada v = this->getVelocidade();
    v.y += this->getAceleracao();
    p.y += v.y;
    this->setVelocidade(v);
    this->setPosicao(p);

    atualizaAcel();
}

void Jogador::atualizaAcel() {
    if(this->getPulo()) {
        this->setAceleracao(GRAVIDADE);
    }
}

void Jogador::executar() {
    //seta as sprites
    atualizaTexture(TEX_JOGADOR);

    // Checa as entradas do usuário e atualiza o movimento
    movimentar();
    
    // Aplica a aceleração na velocidade e a velocidade na posição 
    aplicaAcel();
    
    // Checa se o jogador esta vivo e o atualiza
    estaVivo();


    // Checa se atirou
    atacar();

    // Se o jogador morrer
    if(!vivo) {
        pGrafico->terminar();  // Fecha a janela, mas no fim deveria dar um 'Game Over'
    }
}

