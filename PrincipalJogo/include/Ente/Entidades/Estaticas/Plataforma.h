#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

#define TEX_PLATAFORMA "PrincipalJogo/assets/Texturas/Plataforma/1 Tiles/Tile_02.png"


class Plataforma: public Obstaculo {
    private:
    public:
        Plataforma(Coordenada tam, Coordenada pos, ID id = plataforma);
        ~Plataforma();
        void executar();
        
};

#endif