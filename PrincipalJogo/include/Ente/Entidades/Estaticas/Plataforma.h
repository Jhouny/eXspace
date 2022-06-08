#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

#define TEX_PLATAFORMA "PrincipalJogo/assets/Texturas/Plataforma/1 Tiles/Tile_02.png"

namespace Entidades::Obstaculos{
    class Plataforma: public Obstaculo {
        private:
            bool platafNormal;
        public:
            Plataforma(Coordenada tam, Coordenada pos, bool platNormal = true, ID id = plataforma);
            
            ~Plataforma();

            bool getNormal() const { return platafNormal; }       
    };
}

#endif