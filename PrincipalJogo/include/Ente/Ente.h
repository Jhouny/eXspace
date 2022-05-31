#ifndef _ENTE_H_
#define _ENTE_H_

#include"../Auxiliares/stdafx.h"

// Define a propriedade ID como uma referência à um indice 
enum ID {
    vazio = 0,
    jogador,
    projetil,
    plataforma,
    inimigoTerrestre,
    fase,
    inimigoVoador,
    gasToxico,
    lava,
    rocha,
    chefe
};

class Ente {
    protected:
        ID id;
        int rg;
    public:
        static int cont;
        Ente(ID id = vazio);
        ~Ente();

        ID getID() const { return id; }
        const int getRG() const { return rg; }
        virtual void executar() = 0;
};

#endif