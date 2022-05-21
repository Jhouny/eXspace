#include"../../../include/Entidades/Dinamicas/Jogador.h"

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

void Jogador::movimentar() {
    Coordenada p = this->getPosicao();
    Coordenada X(1,0);
    Coordenada Y(0,1);    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        p += X*velocidade[0];  // Move com velocidade constante no eixo X
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        p -= X*velocidade[0];  // Move com velocidade constante negativa no eixo X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->getJump() == false) {
        // Adiciona um 'pulo' vertical - defini uma velocidade em Y negativa (para cima)
        float* v;
        v = this->getVelocidade();
        v[1] = PULO_Y;
        this->setVelocidade(v[0], v[1]);
        
        // PRECISA DISSO?
        p -= Y*(velocidade[1]);
        this->setJump(true);    
    }

    // Atualiza a posição do sprite e da instância
    this->setPosicao(p);

}


void Jogador::colisao(Entidade* outraEntidade, Coordenada intersecao) {
    /* Checar o tipo da entidade com que colidiu 
       (plataforma, inimigo, obstaculo, ...) 
    */
    //Coordenada thisCenter, outroCenter, intersect;

    // Calcula as coordenadas dos centros dos dois objetos
    //thisCenter.x = this->getPosicao().x + (this->getTamanho().x / 2.0f);
    //thisCenter.y = this->getPosicao().y + (this->getTamanho().y / 2.0f);
    //outroCenter.x = outraEntidade->getPosicao().x + (outraEntidade->getTamanho().x / 2.0f);
    //outroCenter.y = outraEntidade->getPosicao().y + (outraEntidade->getTamanho().y / 2.0f);
    
    // Calcula a distância entre os objetos e subtrai as suas dimensões
    //intersect.x = fabs(thisCenter.x - outroCenter.x) - (this->getTamanho().x + outraEntidade->getTamanho().x) / 2.0f;
    //intersect.y = fabs(thisCenter.y - outroCenter.y) - (this->getTamanho().y + outraEntidade->getTamanho().y) / 2.0f;

    // Se houver interseção em ambos os eixos, ocorre colisao
    //if (intersect.x < 0 && intersect.y < 0) {
        // Colisao com Plataforma
    if(intersecao.x <= intersecao.y) {  //Se intersectou antes no x que no Y
        Coordenada p;
        float* v = this->getVelocidade();
        v[1] = 0;
        this->setVelocidade(v[0], v[1]);

        p.x = this->getPosicao().x;
        p.y = outraEntidade->getPosicao().y - (this->getTamanho().y);
        this->setAceleracao(0);
        this->setPosicao(p);
        this->setJump(false);
    } else {
        if (this->getPosicao().x < outraEntidade->getPosicao().x)
            this->setPosicao(this->getPosicao().x + intersecao.x, this->getPosicao().y);
        else
            this->setPosicao(this->getPosicao().x - intersecao.x, this->getPosicao().y);
        this->setJump(true);
    }
   // }

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
}

