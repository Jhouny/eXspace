#ifndef _LAVA_H_
#define _LAVA_H_
#include "Obstaculo.h"


class Lava:public Obstaculo{
    private:
    public:
        Lava();
        ~Lava();
        void executar();
};


#endif