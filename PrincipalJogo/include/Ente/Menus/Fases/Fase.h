#ifndef _FASE_H_
#define _FASE_H_

#include "../../../Gerenciadores/ListaEntidades.h"
#include "../../../Gerenciadores/Grafico.h"
#include "../../../Gerenciadores/Colisoes.h"

#include "../../../ElementosGraficos/ElementosVisor.h"
#include "../../../Controle/ControleMenu.h"

#include "../Menu.h"
#include "../../Entidades/Dinamicas/InimigoTerrestre.h"
#include "../../Entidades/Dinamicas/InimigoVoador.h"
#include "../../Entidades/Dinamicas/Chefe.h"
#include "../../Entidades/Dinamicas/Jogador.h"
#include "../../Entidades/Dinamicas/Projetil.h"
#include "../../Entidades/Estaticas/Plataforma.h"
#include "../../Entidades/Estaticas/Lava.h"

#define TEX_BACKGROUND "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_1/game_background_1.png"

namespace Menus::Fases {
    class Fase: public Menu {
        protected:
            std::list<Entidades::Entidade*> lEntidades;
            std::list<Entidades::Entidade*>::iterator it;
            ElementosGraficos::ElementosVisor visor;

            int pontuacao;
            int numInimigos;

            Gerenciadores::Colisor colisor;


            Entidades::Personagens::Jogador *jogador1;
            Entidades::Personagens::Jogador *jogador2;

            Entidades::Obstaculos::Lava* pLava;
            Entidades::Obstaculos::Plataforma* pBase;
             Entidades::Obstaculos::Plataforma* pChegada;
            Entidades::Personagens::InimigoTerrestre* pIniTerrestre;
            Entidades::Personagens::InimigoVoador* pIniVoador;

            Controle::ControleMenu pControleFase;
                    
        public:
            Fase(Entidades::Personagens::Jogador* jog1 = NULL, Entidades::Personagens::Jogador* jog2 = NULL);
            
            ~Fase();
            
            void setPontuacao(int acres) { pontuacao+= acres; }
            int getPontuacao(){ return pontuacao; }
            
            virtual void geraPlataformas() = 0;
            virtual void geraObstaculos() = 0;
            virtual void geraInimigos() = 0;

            void atualizaEntidades(const float dt);

            void renderizar();

            void criaBotoes() {}

            void resetarEstadoOriginal();

            void setTexture(const char* path);
            
            void incluir(Entidades::Entidade* l);

            void atualizarBackground();

            void atualizar(const float dt);

            void gameOver();

            void proximaFase();

            void ativarControle();

            void desativarControle();

            virtual void executar(const float dt) = 0;
    };
}


#endif