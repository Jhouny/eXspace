#include "../../include/Entidades/Inimigo.h"

Inimigo::Inimigo(Coordenada tam, Coordenada pos, int v, int d): 
    Personagem(tam, pos, v, d)
{
    pJogador = NULL;
}


Inimigo::~Inimigo(){
    pJogador = NULL;
}
void Inimigo::setJogador(Jogador*pJog)
{
    if(pJog)
        pJogador = pJog;
    else
        cout << "ponteiro nulo" << endl;
}
void Inimigo::executar()
{

}