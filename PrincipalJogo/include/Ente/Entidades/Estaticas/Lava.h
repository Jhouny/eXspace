#ifndef _LAVA_H_
#define _LAVA_H_

#include "Obstaculo.h"

#define TEX_LAVA "PrincipalJogo/assets/Texturas/Lava/Lava.png"


class Lava: public Obstaculo {
    private:
        float dano;
    public:
        Lava(Coordenada tam, Coordenada pos);
        float getDano(){ return dano; }

        ~Lava();
        
        void executar();
};


#endif