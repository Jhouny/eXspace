#ifndef _ENTE_H_
#define _ENTE_H_

#include"../Auxiliares/stdafx.h"

class Ente {
    protected:
        int id;
    public:
        static int cont;
        Ente();
        ~Ente();

        virtual void executar() = 0;
        void imprimirID();
};

#endif