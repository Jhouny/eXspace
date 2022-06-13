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
    chefe,
    menu
};  // Se for adicionar algum novo, adicionar no final, não no meio!!

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
        virtual void executar(const float dt) = 0;
};

#endif