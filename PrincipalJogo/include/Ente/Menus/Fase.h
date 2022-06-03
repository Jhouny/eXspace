#ifndef _FASE_H_
#define _FASE_H_

#include "../../Gerenciadores/ListaEntidades.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Gerenciadores/Colisoes.h"

#include "Menu.h"
#include "../Entidades/Dinamicas/InimigoTerrestre.h"
#include "../Entidades/Dinamicas/Chefe.h"
#include "../Entidades/Dinamicas/Jogador.h"
#include "../Entidades/Dinamicas/Projetil.h"
#include "../Entidades/Estaticas/Plataforma.h"

#define TEX_BACKGROUND "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_1/game_background_1.png"

namespace Menus{
    class Fase: public Menu {
        protected:
            ListaEntidades lEntidades;

            Gerenciadores::Colisor colisor;

            Jogador *jogador1;
            Jogador *jogador2;

            Plataforma* pBase;
            InimigoTerrestre* pIni;
                    
        public:
            Fase(Jogador* jog1 = NULL, Jogador* jog2 = NULL);
            
            ~Fase();
            
            virtual void geraPlataformas() = 0;
            virtual void geraObstaculos() = 0;
            virtual void geraInimigos() = 0;

            void atualizaEntidades(const float dt);

            void renderizar();

            void criaBotoes() {}

            void setTexture(const char* path);
            
            void incluir(Entidade* l);

            void atualizarBackground();

            void atualizar(const float dt);

            void gameOver();

            void executar(const float dt);
    };
}


#endif