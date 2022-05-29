#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

#define TEX_INIMIGO_TERRESTRE "PrincipalJogo/assets/Texturas/Entidades/Jogador/1 Biker/Still.png"

class InimigoTerrestre: public Inimigo {
    private:
        Coordenada velocidade;
        Entidade* pPlataforma;
    public:
        InimigoTerrestre(Coordenada pos = Coordenada(100,100), Coordenada tam = Coordenada(50, 50), int v = 100, int d = 20, ID id = inimigoTerrestre);
        ~InimigoTerrestre();
        
        
        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaVivo();

        void movimentar();

        void executar();
};



#endif