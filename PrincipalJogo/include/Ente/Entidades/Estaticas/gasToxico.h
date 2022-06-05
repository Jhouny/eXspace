#ifndef _GAS_TOXICO_H_
#define _GAS_TOXICO_H_
#include "Obstaculo.h"
#define TEX_GAS ""

class GasToxico: public Obstaculo{
    private:
        float dano;
    public:
        GasToxico(Coordenada tam, Coordenada pos);
        ~GasToxico();

        float getDano(){ return dano; }

        void executar();

};



#endif