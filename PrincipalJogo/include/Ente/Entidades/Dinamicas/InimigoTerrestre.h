#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

#define TEX_INIMIGO_TERRESTRE "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoTerrestre/Still.png"
#define TEX_INIMIGO_TERRESTRE_ALARMADO "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoTerrestre/Alarmado.png"

namespace Entidades::Personagens {
    class InimigoTerrestre: public Inimigo {
        private:
            Coordenada velocidade;
            Entidade* pPlataforma;
            sf::Clock temporizador;
        public:
            InimigoTerrestre();
            ~InimigoTerrestre();
            
            
            void colisao(Entidade* outraEntidade, Coordenada intersecao);

            bool estaVivo();

            void atacar();

            void movimentar(const float dt);

            void executar(const float dt);
    };
}


#endif