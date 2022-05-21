#ifndef _JOGO_H_
#define _JOGO_H_

#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/ListaEntidades.h"

class Jogo {
    private:
        Gerenciadores::Grafico* pGrafico;
        
    public:
        Jogo();

        ~Jogo();

        void exec();

        void gameOver();
};


#endif