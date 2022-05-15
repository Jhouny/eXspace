#include "Personagem.h"

Personagem::Personagem(Coordenada tam, Coordenada pos, int v , int d):
    Entidade(tam,pos),
    vida(v),
    dano(d)
{
}
Personagem::~Personagem(){
}


void Personagem::setDano(int d){
    dano = d;
}


void Personagem::receberDano(int d){
    if(vida > 0)
        vida -= d;
    else 
        cout << "\nPersonagem ja esta morto" << endl;
}