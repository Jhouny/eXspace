#ifndef _GAS_TOXICO_H_
#define _GAS_TOXICO_H_

#include "Obstaculo.h"

#define TEX_GAS "PrincipalJogo/assets/Texturas/GasToxico/gasToxico.png"

namespace Entidades::Obstaculos{
    class GasToxico: public Obstaculo{
        private:
            std::list<Entidades::Entidade*> *lista;  // Ponteiro para lista de entidades -> deve ser implementada antes das rochas 
            float dano;
            bool posDefinida;  // Se ja tiver uma posição definida
        public:
            GasToxico(std::list<Entidades::Entidade*> *l);
            ~GasToxico();

            float getDano(){ return dano; }
    };
}


#endif