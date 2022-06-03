#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

#define TEX_INIMIGO_TERRESTRE "PrincipalJogo/assets/Texturas/Inimigos/InimigoTerrestre/5/Still.png"

class InimigoTerrestre: public Inimigo {
    private:
        Coordenada velocidade;
        Entidade* pPlataforma;
    public:
        InimigoTerrestre();
        ~InimigoTerrestre();
        
        
        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaVivo();

        void movimentar(const float dt);

        void executar(const float dt);
};



#endif