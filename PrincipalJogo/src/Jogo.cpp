#include "../include/Jogo.h"


Jogo::Jogo():
    MaquinaEstados(),
    pEventos(Gerenciadores::Eventos::getInstancia()),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    jogador1(new Jogador())
{
    temporizador.restart();
    dt = 0;
    estadoAtual = NULL;

    /*  ==========  Adiciona os Menus e Fases  ==========  */
    Estados::Estado* pTemp;
    
    // Menu principal de abertura do jogo 
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuAbertura());
    pTemp->setMaquina(this);
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
    cout << "1" << endl;
    // Fase mercúrio
    pTemp = static_cast<Estados::Estado*>(new Menus::Mercurio(jogador1));
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);
    cout << "1" << endl;
    // Fase Netuno
    pTemp = static_cast<Estados::Estado*>(new Menus::Netuno(jogador1));
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);
    cout << "1" << endl;
    // Menu fim de jogo
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuGameOver());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    /*  =================================================  */

    // Define o menu de abertura
    setEstadoAtual(Estados::IdEstado::menuAbertura);

    executar();
}
 
 
Jogo::~Jogo() {

 }


void Jogo::executar() {
    cout << "2" << endl;
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

        renderizarEstadoAtual();

        pGrafico->display();
    }
}