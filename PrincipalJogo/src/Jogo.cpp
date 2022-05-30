#include "../include/Jogo.h"

Jogo::Jogo():
    jogador1(),
    fase1(1, &jogador1 , &jogador2)
{
    executar();
}
 
 
Jogo::~Jogo() { }


void Jogo::executar(){
    fase1.executar();    
}