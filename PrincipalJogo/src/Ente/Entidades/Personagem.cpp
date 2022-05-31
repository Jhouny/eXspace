#include "../../../include/Ente/Entidades/Personagem.h"

Personagem::Personagem(Coordenada tam, Coordenada pos, bool est, int v, int d, ID id):
    Entidade(id,tam,pos,est),
    vida(v),
    dano(d),
    pulando(true),
    vivo(true)
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
    else {
        cout << "\nPersonagem ja esta morto" << endl;
    }

}