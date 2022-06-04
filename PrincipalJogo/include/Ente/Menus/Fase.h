#ifndef _FASE_H_
#define _FASE_H_

#include "../../Gerenciadores/ListaEntidades.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Gerenciadores/Colisoes.h"

#include "../../ElementosGraficos/ElementosVisor.h"
#include "../../Controle/ControleMenu.h"

#include "Menu.h"
#include "../Entidades/Dinamicas/InimigoTerrestre.h"
#include "../Entidades/Dinamicas/Chefe.h"
#include "../Entidades/Dinamicas/Jogador.h"
#include "../Entidades/Dinamicas/Projetil.h"
#include "../Entidades/Estaticas/Plataforma.h"
#include "../Entidades/Estaticas/Lava.h"

#define TEX_BACKGROUND "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_1/game_background_1.png"

namespace Menus{
    class Fase: public Menu {
        protected:
            std::vector<Entidade*> lEntidades;
            ElementosGraficos::ElementosVisor visor;

            Gerenciadores::Colisor colisor;

            Lava* pLava;

            Jogador *jogador1;
            Jogador *jogador2;

            Plataforma* pBase;
            InimigoTerrestre* pIni;

            Controle::ControleMenu pControleFase;
                    
        public:
            Fase(Jogador* jog1 = NULL, Jogador* jog2 = NULL);
            
            ~Fase();
            
            virtual void geraPlataformas() = 0;
            virtual void geraObstaculos() = 0;
            virtual void geraInimigos() = 0;

            void atualizaEntidades(const float dt);

            void renderizar();

            void criaBotoes() {}

            void resetarEstadoOriginal();

            void setTexture(const char* path);
            
            void incluir(Entidade* l);

            void atualizarBackground();

            void atualizar(const float dt);

            void gameOver();

            void ativarControle();

            void desativarControle();

            virtual void executar(const float dt) = 0;
    };
}


#endif