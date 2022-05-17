#ifndef _COORDENADA_H_
#define _COORDENADA_H_

class Coordenada {
    private:
        float x;
        float y;
    public:
        Coordenada(float xs = 0, float ys = 0);
        ~Coordenada();

        void setCoordenada(float xs, float ys);
        const float getX() const {return x;}
        const float getY() const {return y;}

        void operator += (Coordenada op);
        void operator -= (Coordenada op);
        void operator = (Coordenada op);
        
        Coordenada operator * (float n);
        void print();
};

/*    
        INCLUDE colocado depois da definição da classe 
    pois será usado na implementação e evita dependência
    circular.
*/
#include"stdafx.h"

#endif