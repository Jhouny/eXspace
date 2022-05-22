#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

class Plataforma: public Obstaculo {
    private:
    public:
        Plataforma(Coordenada tam, Coordenada pos, ID id = platforma);
        ~Plataforma();
        void executar();
        
};

#endif