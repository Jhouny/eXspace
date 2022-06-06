#include "../../../include/Ente/Entidades/Personagem.h"

namespace Entidades::Personagens {
    Personagem::Personagem(Coordenada tam, Coordenada pos, bool est, float v, float d, ID id):
        Entidade(id,tam,pos,est),
        vida(v),
        dano(d),
        pulando(true),
        vivo(true)
    {
    }

    Personagem::~Personagem(){
    }


    void Personagem::setDano(float d){
        dano = d;
    }

    void Personagem::receberDano(float d){
        if(vida > 0)
            vida -= d;
        else {
            cout << "\n Personagem (RG: " << getRG() << " ID: " << getID() << ") ja esta morto" << endl;
        }

    }
}