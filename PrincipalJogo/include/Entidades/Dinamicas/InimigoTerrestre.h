#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

class InimigoTerrestre: public Inimigo {
    private:
        float velocidade;
        bool jogTaPerto;
    public:
        InimigoTerrestre(Coordenada tam, Coordenada pos, int v = 100, int d = 20);
        
        ~InimigoTerrestre();

        void setVelocidade(float v);
        
        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void alarmado();

        void movimentar();
        
        void executar();
};



#endif