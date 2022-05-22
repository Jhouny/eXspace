#include"../../../include/Entidades/Dinamicas/Jogador.h"


#define GRAVIDADE 3
#define PULO_Y -40
#define ATRITO 0.7

Jogador::Jogador(Coordenada tam, Coordenada pos, int v, int d, ID id):
    Personagem(tam, pos, v, d, id) {
        shape.setFillColor(sf::Color::Green);
        setJump(true);
        velocidade[0] = 0;
        velocidade[1] = 0;
        aceleracaoY = 10;
}

Jogador::~Jogador() {
    free(velocidade);
}

void Jogador::setVelocidade(float vx, float vy) {
    velocidade[0] = vx;
    velocidade[1] = vy;
}

void Jogador::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300) {
        vivo = false;
    }
}


void Jogador::movimentar() {
    Coordenada p = this->getPosicao();
    Coordenada X(1,0);
    Coordenada Y(0,1);

    if(p.y > ALTURA + 300) {
        vivo = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        p += X*velocidade[0];  // Move com velocidade constante no eixo X
        this->setAceleracao(GRAVIDADE);  // Redefine a gravidade se o jogador sair de cima da plataforma
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        p -= X*velocidade[0];  // Move com velocidade constante negativa no eixo X
        this->setAceleracao(GRAVIDADE);  // Redefine a gravidade se o jogador sair de cima da plataforma
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getJump() == false) {
        // Adiciona um 'pulo' vertical - defini uma velocidade em Y negativa (para cima)
        float* v;
        v = this->getVelocidade();
        v[1] = PULO_Y;
        this->setVelocidade(v[0], v[1]);
        
        // PRECISA DISSO?
        p -= Y*(velocidade[1]);
        this->setAceleracao(0);  // Precisa disso
        this->setJump(true);
    }

    // Atualiza a posição do sprite e da instância
    this->setPosicao(p);

}


void Jogador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    /* Checar o tipo da entidade com que colidiu 
       (plataforma, inimigo, obstaculo, ...) 
    */
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::platforma) {  //Se intersectou antes no x que no Y (i.e. colidiu verticalmente com a plataforma)
        Coordenada p = this->getPosicao();
        float* v = this->getVelocidade();
        
        if(this->getPosicao().y <= outraEntidade->getPosicao().y) {  // Se colidir em cima
            v[1] = 0;  // Define a velocidade vertical para 0
            p.y = outraEntidade->getPosicao().y - this->getTamanho().y;  // Define a posição em cima da plataforma
            this->setAceleracao(0);
            this->setJump(false);

        } else {  // Se colidir embaixo
            v[1] = -1 * v[1] * ATRITO;
            p.y = outraEntidade->getPosicao().y + outraEntidade->getTamanho().y;  // Define a posição em cima da plataforma
            this->setJump(true);
        }

        this->setVelocidade(v[0], v[1]);
        this->setPosicao(p);

    } else if(intersecao.y <= intersecao.x) {  // Se está do lado, não deixa atravessar o objeto
        if (this->getPosicao().x < outraEntidade->getPosicao().x)
            this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
        else
            this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
        //this->setJump(true);
    }
}

void Jogador::aplicaAcel() {
    Coordenada p = this->getPosicao();
    float* v;
    v = this->getVelocidade();
    v[1] += this->getAceleracao();
    p.y += v[1];
    this->setVelocidade(v[0], v[1]);
    this->setPosicao(p);

    atualizaAcel();
}

void Jogador::atualizaAcel() {
    if(this->getJump()) {
        this->setAceleracao(GRAVIDADE);
    }
}

void Jogador::executar() {
    // Checa as entradas do usuário e atualiza o movimento
    movimentar();
    
    // Aplica a aceleração na velocidade e a velocidade na posição 
    aplicaAcel();

    // Checa se o jogador esta vivo e o atualiza
    estaVivo();

    //this->setAceleracao(GRAVIDADE);
    // Se o jogador morrer
    if(!vivo) 
        pGrafico->terminar();  // Fecha a janela, mas no fim deveria dar um 'Game Over'
}

