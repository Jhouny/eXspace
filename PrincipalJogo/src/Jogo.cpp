#include "../include/Jogo.h"

Jogo::Jogo():
    fase1(1,1)
{ 
    exec();
}
 
 
Jogo::~Jogo() { }


void Jogo::exec(){
    fase1.executar();    
}