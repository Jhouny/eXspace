#ifndef _JOGO_H_
#define _JOGO_H_

#include "Ente/Fase/Fase.h"

class Jogo {
    private:
        Jogador jogador1;
        Jogador jogador2;
        Fase fase1;
        Fase fase2;
    public:
        Jogo();

        ~Jogo();

        void executar();
};


#endif