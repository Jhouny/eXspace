#include "../include/Jogo.h"

Jogo::Jogo():
    jogador1(),
    fase1(1, &jogador1 , &jogador2)
{
    cout<<"aqui jogo"<<endl;
    executar();
}
 
 
Jogo::~Jogo() { }


void Jogo::executar(){
    fase1.executar();    
}