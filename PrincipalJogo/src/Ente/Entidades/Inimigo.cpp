#include "../../../include/Ente/Entidades/Inimigo.h"


Inimigo::Inimigo(Coordenada tam, Coordenada pos, int v, int d, ID id): 
    Personagem(tam, pos, v, d, id)
{
    pJogador = NULL;
}


Inimigo::~Inimigo(){
    pJogador = NULL;
}

void Inimigo::setJogador(Jogador* pJog) {
    if(pJog)
        pJogador = pJog;
    else
        cout << "ponteiro nulo" << endl;
}