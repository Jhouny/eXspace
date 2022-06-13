#ifndef _INIMIGO_TERRESTRE_
#define _INIMIGO_TERRESTRE_
#include "../Inimigo.h"

#define TEX_INIMIGO_TERRESTRE "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoTerrestre/Still.png"
#define TEX_INIMIGO_TERRESTRE_ALARMADO "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoTerrestre/Alarmado.png"
#define TEX_INIMIGO_TERRESTRE_DESCARREGADO "PrincipalJogo/assets/Texturas/Entidades/Inimigos/InimigoTerrestre/Descarregado.png"

namespace Entidades::Personagens {
    class InimigoTerrestre: public Inimigo {
        private:
            Entidade* pPlataforma;
            sf::Clock temporizador, tempoCarga;
            bool carga;
        public:
            InimigoTerrestre();
            ~InimigoTerrestre();

            void setCarga(bool est) { carga = est; }
            bool getCarga() const { return carga; }
            
            void reiniciarClock() { tempoCarga.restart(); }

            void colisao(Entidade* outraEntidade, Coordenada intersecao);

            bool estaVivo();

            void atacar();

            void atualizaCarga();

            void movimentar(const float dt);

            void executar(const float dt);
    };
}


#endif