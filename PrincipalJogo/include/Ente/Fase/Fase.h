#ifndef _FASE_H_
#define _FASE_H_

#include "../../Gerenciadores/ListaEntidades.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Gerenciadores/Colisoes.h"
#include "../../Controle/ControleJogador.h"

#include "../Ente.h"
#include "../Entidades/Dinamicas/InimigoTerrestre.h"
#include "../Entidades/Dinamicas/Chefe.h"
#include "../Entidades/Dinamicas/Jogador.h"
#include "../Entidades/Dinamicas/Projetil.h"
#include "../Entidades/Estaticas/Plataforma.h"

#define TEX_BACKGROUND "PrincipalJogo/assets/Texturas/Backgrounds/Fundo/PNG/game_background_1/game_background_1.png"

class Fase: public Ente{
    private:
        ListaEntidades lEntidades;

        Gerenciadores::Grafico* pGrafico;  //pGrafico(Gerenciadores::Grafico::getInstancia())
        Gerenciadores::Colisor colisor;
        Controle::ControleJogador* pCtrlJog;

        int nivel;
        int nJog;

        Jogador *jogador1;
        Jogador *jogador2;

        Plataforma* pBase;
        InimigoTerrestre* pIni;
        
        sf::Sprite fundo;
        
    public:
        Fase(int ni = 1, Jogador* jog1 = NULL, Jogador* jog2 = NULL);
        
        ~Fase();
        
        void geraPlataformas(); //nao conseguimos implementar 
        void geraObstaculos(); //nao conseguimos implementar 
        void geraInimigos(); //nao conseguimos implementar 
        
        void setJogador1(Jogador *jog) { jogador1 = jog; }
        void setJogador2(Jogador *jog) { jogador2 = jog; }

        void atualizaEntidades();
        void setTexture(const char* path);
        
        void incluir(Entidade* l);

        void atualizarBackground();

        void atualizar();

        void gameOver();

        void executar();
};


#endif