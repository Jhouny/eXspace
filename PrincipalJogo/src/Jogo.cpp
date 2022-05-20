#include "../include/Jogo.h"
#include "../include/Entidades/Dinamicas/Jogador.h"
#include "../include/Entidades/Estaticas/Plataforma.h"

Jogo::Jogo():
    pGrafico(Gerenciadores::Grafico::getInstancia()) 
    { 
    exec();
}
 
 
Jogo::~Jogo() {

}


void Jogo::exec(){
    //inicializa entidades que serão usadas
    Jogador jog(Coordenada(200, 100), Coordenada(300, 500));
    jog.setVelocidade(15, 0);
    Plataforma plat1(Coordenada(550, 50), Coordenada(  0, 600));
    Plataforma plat2(Coordenada(500, 50), Coordenada(600, 450));
    
    //insere na lista de Entidades Dinamicas
    lDinamicas.push(static_cast<Entidade*>(&jog));

    //insere na lista de Entidades Estaticas
    lEstaticas.push(static_cast<Entidade*>(&plat1));
    lEstaticas.push(static_cast<Entidade*>(&plat2));
    
    
    while(pGrafico->isOpened()) {
        
        while (pGrafico->getWindow()->pollEvent(*pGrafico->getEvent())) {
            if (pGrafico->getEvent()->type == sf::Event::Closed)
                gameOver();
        }

        pGrafico->clear();
        /**verificar como conseguir o iterador*/
        auto *itrD = lDinamicas.getIterador();
        auto *itrE = lEstaticas.getIterador();
        
        //verifica colisao entre Entidades Dinamicas e Estaticas
        for(itrD = lDinamicas.le.getInicial(); itrD != NULL; itrD = itrD->getProx()) {
            pGrafico->draw(itrD->getElemento()->getShape());
            itrD->getElemento()->executar();
            for(itrE = lEstaticas.le.getInicial(); itrE != NULL; itrE = itrE->getProx()) {
                itrD->getElemento()->colisao(itrE->getElemento());
                pGrafico->draw(itrE->getElemento()->getShape());
            }
        }

        pGrafico->display();
    }
}


void Jogo::gameOver(){
    pGrafico->shutdown();
}