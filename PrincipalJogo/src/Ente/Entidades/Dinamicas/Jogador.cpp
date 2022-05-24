#include"../../../../include/Ente/Entidades/Dinamicas/Jogador.h"

#define PULO_Y -35
#define ATRITO 0.7

Jogador::Jogador(Coordenada tam, Coordenada pos, int v, int d, ID id):
    Personagem(tam, pos, v, d, id) {
        shape.setFillColor(sf::Color::Green);
        setJump(true);
        velocidade.x = 0.f;
        velocidade.y = 0.f;
        aceleracaoY = 10;
}

Jogador::~Jogador() {
}

void Jogador::estaVivo() {
    Coordenada p = this->getPosicao();
    if(p.y > ALTURA + 300) {
        vivo = false;
    }
}


void Jogador::movimentar() {
    Coordenada p = this->getPosicao();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        p += velocidade.x;  // Move com velocidade constante no eixo X
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        p -= velocidade.x;  // Move com velocidade constante negativa no eixo X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getJump() == false) {
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
    if(intersecao.x <= intersecao.y && outraEntidade->getID() == ID::platforma) {  //Se intersectou antes no x que no Y (i.e. colidiu verticalmente com a plataforma)
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

    } else if(intersecao.y <= intersecao.x) {  // Se está do lado, não deixa atravessar o objeto
        if (this->getPosicao().x < outraEntidade->getPosicao().x)
            this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
        else
            this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
        this->setJump(true);  // Para não poder pular se encostar lateralmente
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

    // Se o jogador morrer
    if(!vivo) 
        pGrafico->terminar();  // Fecha a janela, mas no fim deveria dar um 'Game Over'
}

