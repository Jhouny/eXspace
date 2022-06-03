#include "../include/Jogo.h"

Jogo::Jogo():
    MaquinaEstados(),
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pEventos(Gerenciadores::Eventos::getInstancia())
    //jogador1()
{
    temporizador.restart();
    dt = 0;

    // Adiciona os Menus e Fases
    Estados::Estado* pTemp;
    
    pTemp = static_cast<Estados::Estado*>(new Menus::MenuAbertura());
    pTemp->setMaquina(this);
    inserirEstado(pTemp);

    pTemp = static_cast<Estados::Estado*>(new Menus::MenuPontuacao());
    pTemp->setMaquina(this);
    pTemp->cegar();
    inserirEstado(pTemp);

    setEstadoAtual(Estados::IdEstado::menuAbertura);

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
        renderizarEstadoAtual();

        pGrafico->display();
    }
}