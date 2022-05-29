#ifndef _JOGO_H_
#define _JOGO_H_

#include "Ente/Fase/Fase.h"

class Jogo {
    private:
        Fase fase1;
    public:
        Jogo();

        ~Jogo();

        void executar();
};


#endif