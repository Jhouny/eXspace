#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include"../Entidade.h"

class Plataforma: public Entidade {
    private:
    public:
        Plataforma(Coordenada tam,Coordenada pos);
        ~Plataforma();
        void executar();
        
};

#endif