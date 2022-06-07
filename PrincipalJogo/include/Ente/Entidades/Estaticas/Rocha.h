#ifndef _ROCHA_H_
#define _ROCHA_H_

#include "Obstaculo.h"

#define TEX_ROCHA_1 "PrincipalJogo/assets/Texturas/Rocha/rocha2.png"
#define TEX_ROCHA_2 "PrincipalJogo/assets/Texturas/Rocha/rocha2.png"
#define TEX_ROCHA_3 "PrincipalJogo/assets/Texturas/Rocha/rocha2.png"

namespace Entidades::Obstaculos{
    class Rocha: public Obstaculo {
        private:
            std::list<Entidades::Entidade*> *lista;  // Ponteiro para lista de entidades -> deve ser implementada antes das rochas
            bool posDefinida;  // Se ja tiver uma posição definida
        public:
            Rocha(std::list<Entidades::Entidade*> *l);

            ~Rocha();
    };
}

#endif