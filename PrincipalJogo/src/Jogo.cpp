#include "../include/Jogo.h"

Jogo::Jogo():
    fase1(1,1)
{ 
    executar();
}
 
 
Jogo::~Jogo() { }


void Jogo::executar(){
    fase1.executar();    
}