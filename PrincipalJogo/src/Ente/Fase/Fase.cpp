#include "../../../include/Ente/Fase/Fase.h"

Fase::Fase(int ni,Jogador* jog1, Jogador* jog2):
    Ente(ID::fase),
    nivel(ni),
    jogador1(jog1),
    jogador2(jog2),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    colisor(),
    pCtrlJog(new Controle::ControleJogador(jog1))
    {
        setTexture(TEX_BACKGROUND);
        if(nJog == 2) {
            jogador2->setVelocidade(Coordenada(15,0));
            incluir(static_cast<Entidade*>(jogador2));
        }

        jogador1->setVelocidade(Coordenada(10.5, 0));
        jogador1->setFase(this);
        incluir(static_cast<Entidade*>(jogador1));
}

Fase::~Fase() {}

void Fase::geraPlataformas() {
    pBase = new Plataforma(Coordenada(1000, 32), Coordenada(0, ALTURA - 100.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(1000, 32), Coordenada(1200, ALTURA - 100.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(1000, 32), Coordenada(1400, ALTURA - 100.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(2000, 32), Coordenada(2400, ALTURA - 100.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(400, ALTURA - 300.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(750, ALTURA - 300.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(1000, ALTURA - 400.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(1400, ALTURA - 500.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(1800, ALTURA - 450.f));
    incluir(static_cast<Entidade*>(pBase));
    
    pBase = new Plataforma(Coordenada(150, 32), Coordenada(2200, ALTURA -400.f));
    incluir(static_cast<Entidade*>(pBase));
}

void Fase::geraObstaculos() {

}

void Fase::geraInimigos() {    
    for(int i = 0; i < 4*nivel; i++) {
        pIni = new InimigoTerrestre();
        pIni->setPosicao(Coordenada(rand() % COMPRIMENTO, 100));
        pIni->setJogador(jogador1);
        incluir(static_cast<Entidade*>(pIni));
    }
}

void Fase::setTexture(const char* path) {
    sf::Texture *temp = pGrafico->loadTexture(path);
    fundo.setTexture(*temp);
    float sX = (float)COMPRIMENTO/temp->getSize().x;
    float sY = (float)ALTURA/temp->getSize().y;
    fundo.setScale(2*sX, sY);
}

void Fase::atualizarBackground() {
    // Simula o movimento relativo do background e jogador
    float pX = 0.85 * jogador1->getPosicao().x - COMPRIMENTO/2.f;
    fundo.setPosition(pX, 0);
}

void Fase::gameOver() {
    pGrafico->terminar();
}

void Fase::incluir(Entidade* l) {
    ID id = l->getID();
    lEntidades.push(l);
    colisor.push(l);
}

void Fase::atualizaEntidades(){
    int i;
    Entidade *ent;
    for(i = 0; i < lEntidades.getTamanho(); i++) {
        ent = lEntidades[i];
        pGrafico->draw(ent->getSprite());
        pGrafico->draw(ent->getShape());  // Fantasma shape para debuggar posicoes relativas e colisoes
        ent->executar();
        if(!ent->getAtivo()) {
            lEntidades.removeIndice(i);
        }
    }
}

void Fase::atualizar() {    
    pGrafico->clear();

    // Verifica colisao entre Entidades Dinamicas e Estaticas
    colisor.ChecarColisoes();
    
    // Draw shapes & executar
    pGrafico->draw(&fundo, false);
    
    atualizaEntidades();

    //Seta view
    pGrafico->atualizaView(jogador1);
    
    atualizarBackground();

    //colisor.remove(); 

    pGrafico->display();
}

void Fase::executar() {
    geraInimigos();
    geraPlataformas();

    // Seta tamanho da view
    pGrafico->setTamView(Coordenada(COMPRIMENTO,ALTURA));
    pGrafico->setMinimap(Coordenada (4000,ALTURA));
    pGrafico->setMinimapViewport();
    pGrafico->atualizaMinimap(Coordenada(2000,360));
}