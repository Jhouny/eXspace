#ifndef _JOGO_H_
#define _JOGO_H_

#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/Colisoes.h"
#include "../include/Gerenciadores/ListaEntidades.h"

class Jogo {
    private:
        Gerenciadores::Grafico* pGrafico;
        Gerenciadores::Colisor* pColisor;
        ListaEntidades lDinamicas;
        ListaEntidades lEstaticas;
    public:
        Jogo();

        ~Jogo();

        void exec();

        void gameOver();
};


#endif