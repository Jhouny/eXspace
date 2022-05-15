#include "Inimigo.h"

Inimigo::Inimigo(Coordenada tam, Coordenada pos, int v = 100, int d = 20):
    Personagem(tam,pos,v,d)
{
    pJogador=NULL;
}


Inimigo::~Inimigo(){
    pJogador=NULL;
}
void Inimigo::setJogador(Jogador*pJog)
{
    if(pJog)
        pJogador=pJog;
    else
        cout<<"ponteiro nulo"<< endl;
}
void Inimigo::executar()
{

}

