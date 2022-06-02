#include "../include/Jogo.h"

Jogo::Jogo():
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pEventos(Gerenciadores::Eventos::getInstancia()),
    jogador1(),
    fase1(1, &jogador1),
    menuAbertura(),
    menuPontuacao()
{
    temporizador.restart();
    dt = 0;

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
            //fase1.atualizar(dt);
            menuPontuacao.atualizar(dt);
            dt -= TICK_RATE;
        }
        
        menuPontuacao.renderizar();
        //cout << "pos: " << menuAbertura.fundo.getPosition().x << " " << menuAbertura.fundo.getPosition().y << endl;
        //fase1.renderizar();

        pGrafico->display();
    }
}