#include "../include/Game.h"
#include "../include/Entidades/Dinamicas/Jogador.h"
#include "../include/Entidades/Estaticas/Plataforma.h"

Game::Game():
pGrafico(Gerenciadores::Grafico::getInstancia())
 { 
    exec();
 }
 
 
Game::~Game() { }


void Game::exec(){
    Jogador jog(Coordenada(100, 100), Coordenada(300, 500));
    jog.setVelocidade(15, 0);
    Plataforma plat1(Coordenada(550, 100), Coordenada(0, 600));
    Plataforma plat2(Coordenada(500, 50), Coordenada(600, 450));
    
    lDinamicas.push(static_cast<Entidade*>(&jog));

    lEstaticas.push(static_cast<Entidade*>(&plat1));
    lEstaticas.push(static_cast<Entidade*>(&plat2));
    
    while(pGrafico->isOpened()) {
        
        while (pGrafico->getWindow()->pollEvent(*pGrafico->getEvent())) {
            if (pGrafico->getEvent()->type == sf::Event::Closed)
                gameOver();
        }

        pGrafico->clear();
        
        Copia<Entidade> *itrD, *itrE;

        for(itrD = lDinamicas.le.getItr(); itrD != NULL; itrD = itrD->getProx()) {
            pGrafico->draw(itrD->getCopia()->getShape());
            itrD->getCopia()->executar();
            for(itrE = lEstaticas.le.getItr(); itrE != NULL; itrE = itrE->getProx()) {
                itrD->getCopia()->colisao(itrE->getCopia());
                pGrafico->draw(itrE->getCopia()->getShape());
            }
        }

        pGrafico->display();
    }
}


void Game::gameOver(){
    pGrafico->shutdown();
}