#include "../include/Jogo.h"

Jogo::Jogo():
    pGrafico(Gerenciadores::Grafico::getInstancia()),
    pEventos(Gerenciadores::Eventos::getInstancia()),
    jogador1(),
    fase1(1, &jogador1)
{
    executar();
}
 
 
Jogo::~Jogo() { }


void Jogo::executar() {
    fase1.executar();
    while(pGrafico->isOpened()) {
        pEventos->checarEventos();
        cout << "SEM TECLAS" << endl;
        fase1.atualizar();
    }
}