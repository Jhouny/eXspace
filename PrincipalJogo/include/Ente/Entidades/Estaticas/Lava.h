#ifndef _LAVA_H_
#define _LAVA_H_

#include "Obstaculo.h"

#define TEX_LAVA "PrincipalJogo/assets/Texturas/Lava/Lava.png"
#define TEX_LAVA_GELADA "PrincipalJogo/assets/Texturas/Lava/lava de gelo.png"


class Lava: public Obstaculo {
    private:
        float dano;
        bool lavaNormal;
    public:
        Lava(Coordenada tam, Coordenada pos, bool lNormal);
        ~Lava();

        float getDano(){ return dano; }

        void executar();
};


#endif