#include "../include/Jogo.h"


Jogo::Jogo():
    MaquinaEstados(),
    pEventos(Gerenciadores::Eventos::getInstancia()),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    jogador1(new Jogador())
{
    temporizador.restart();
    dt = 0;

    /*  ==========  Adiciona os Menus e Fases  ==========  */
    Estados::Estado* pTemp;
    
    // Menu principal de abertura do jogo 
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuAbertura());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    // Pontuação dos jogadores
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuPontuacao());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    //Menu de configurações de jogo
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuJogar());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    // Fase mercúrio
    pTemp = static_cast<Estados::Estado*>(new Menus::Mercurio(jogador1));
    pTemp->setMaquina(this);
    inserirEstado(pTemp);

    // Menu fim de jogo
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuGameOver());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    /*  =================================================  */

    // Define o menu de abertura
    setEstadoAtual(Estados::IdEstado::fase);

    executar();
}
 
 
Jogo::~Jogo() { }


void Jogo::executar() {
    while(pGrafico->isOpened()) {
        pEventos->checarEventos();
        pGrafico->clear();

        if (dt < TICK_RATE) {
            dt += temporizador.getElapsedTime().asSeconds();
            temporizador.restart();
        } //
        else {
            atualizarEstadoAtual(dt);
            dt -= TICK_RATE;
        }
        //cout << "Coord: " << endl;
        //pGrafico->getViewBounds().print();
        renderizarEstadoAtual();

        pGrafico->display();
    }
}