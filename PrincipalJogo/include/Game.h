#ifndef _GAME_H_
#define _GAME_H_

#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/ListaEntidades.h"

class Game {
    private:
        Gerenciadores::Grafico* pGrafico;
        ListaEntidades lDinamicas;
        ListaEntidades lEstaticas;
        
    public:
        Game();

        ~Game();

        void exec();

        void gameOver();
};


#endif