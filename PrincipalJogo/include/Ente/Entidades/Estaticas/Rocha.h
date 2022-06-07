#ifndef _ROCHA_H_
#define _ROCHA_H_

#include "Obstaculo.h"
#define TEX_ROCHA "PrincipalJogo/assets/Texturas/Rocha/rocha2.png"

namespace Entidades::Obstaculos{
    class Rocha:public Obstaculo{
        private:
        public:
            Rocha(Coordenada pos);
            ~Rocha();
            void executar();
    };

}

#endif