#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

class InimigoTerrestre: public Inimigo {
    private:
        Coordenada velocidade;
        Entidade* pPlataforma;
        bool jogTaPerto;
    public:
        InimigoTerrestre(Coordenada pos = Coordenada(100,100), Coordenada tam = Coordenada(50, 50), int v = 100, int d = 20, ID id = inimigoTerrestre);
        ~InimigoTerrestre();
        
    
        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaVivo();

        void alarmado();

        void movimentar();
        
        void executar();
};



#endif