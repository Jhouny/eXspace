#include "../include/Jogo.h"

#include "../include/Entidades/Dinamicas/Jogador.h"
#include "../include/Entidades/Estaticas/Plataforma.h"
#include "../include/Gerenciadores/ListaEntidades.h"

Jogo::Jogo():
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pColisor(new Gerenciadores::Colisor())
{ 
    pColisor->setDinamicas(&lDinamicas);
    pColisor->setEstatica(&lEstaticas);
    exec();
}
 
 
Jogo::~Jogo() { }


void Jogo::exec(){
    // inicializa entidades que serão usadas
    Jogador jog(Coordenada(100, 100), Coordenada(300, 300));
    jog.setVelocidade(15, 0);
    Plataforma plat1(Coordenada(550, 50), Coordenada(  0, 600));
    Plataforma plat2(Coordenada(500, 50), Coordenada(600, 450));

    // insere na lista de Entidades Dinamicas
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

        // Verifica colisao entre Entidades Dinamicas e Estaticas
        pColisor->ChecarColisoes();

        // Draw shapes & executar
        int i;
        Entidade *ent;
        for(i = 0; i < lDinamicas.getTamanho(); i++) {
            ent = lDinamicas[i];
            ent->executar();
            pGrafico->draw(ent->getShape());
        }
        
        for(i = 0; i < lEstaticas.getTamanho(); i++) {
            ent = lEstaticas[i];
            ent->executar();
            pGrafico->draw(ent->getShape());
        }

        pGrafico->display();
    }
}


void Jogo::gameOver(){
    pGrafico->terminar();
}