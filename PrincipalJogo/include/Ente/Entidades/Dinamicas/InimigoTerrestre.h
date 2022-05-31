#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

#define TEX_INIMIGO_TERRESTRE "PrincipalJogo/assets/Texturas/Entidades/Jogador/1 Biker/Still.png"

class InimigoTerrestre: public Inimigo {
    private:
        Coordenada velocidade;
        Entidade* pPlataforma;
    public:
        InimigoTerrestre();
        ~InimigoTerrestre();
        
        
        void colisao(Entidade* outraEntidade, Coordenada intersecao);

        void estaVivo();

        void movimentar();

        void executar();
};



#endif