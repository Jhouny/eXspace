#include "../include/Jogo.h"


Jogo::Jogo():
    MaquinaEstados(),
    pEventos(Gerenciadores::Eventos::getInstancia()),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    jogador1(new Entidades::Personagens::Jogador()),
    jogador2(new Entidades::Personagens::Jogador())
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
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuAbertura]);
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    //Menu de configurações de jogo
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuJogar());
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuAbertura]);
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);
    
    // Menu de transição entre fases terminadas com êxito
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuTransicao());
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuJogar]);
    pTemp->setMaquina(this);
    inserirEstado(pTemp);

    // Menu fim de jogo
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuGameOver());
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuJogar]);
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    // Menu de pausa
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuPausa());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    // Fase mercúrio
    pTemp = static_cast<Estados::Estado*>(new Menus::Fases::Mercurio(jogador1, jogador2));
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuJogar]);
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    // Fase Netuno
    pTemp = static_cast<Estados::Estado*>(new Menus::Fases::Netuno(jogador1, jogador2));
    pTemp->setAnterior(mapaEstados[Estados::IdEstado::menuJogar]);
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