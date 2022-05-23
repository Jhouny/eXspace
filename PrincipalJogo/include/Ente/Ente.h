#ifndef _ENTE_H_
#define _ENTE_H_

#include"../Auxiliares/stdafx.h"

// Define a propriedade ID como uma referência à um indice 
enum ID {
    vazio = 0,
    jogador,
    projetil,
    platforma,
    inimigoTerrestre,
    fase
};

class Ente {
    protected:
        ID id;
    public:
        static int cont;
        Ente(ID id = vazio);
        ~Ente();

        ID getID() const { return id; }

        virtual void executar() = 0;
};

#endif