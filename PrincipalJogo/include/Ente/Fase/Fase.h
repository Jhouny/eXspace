#ifndef _FASE_H_
#define _FASE_H_

#include "../../Gerenciadores/ListaEntidades.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Gerenciadores/Colisoes.h"

#include "../Ente.h"
#include "../Entidades/Dinamicas/InimigoTerrestre.h"
#include "../Entidades/Dinamicas/Chefe.h"
#include "../Entidades/Dinamicas/Jogador.h"
#include "../Entidades/Dinamicas/Projetil.h"
#include "../Entidades/Estaticas/Plataforma.h"


class Fase: public Ente{
    private:
        ListaEntidades lEstaticas;
        ListaEntidades lDinamicas;
        Gerenciadores::Grafico* pGrafico;  //pGrafico(Gerenciadores::Grafico::getInstancia())
        Gerenciadores::Colisor* pColisor;
        int nivel, nJog;
        Jogador jogador1;
        Jogador jogador2;
        
    public:
        Fase(int ni = 1, int num_jog = 1);
        ~Fase();
        
        void geraPlataformas();
        void geraObstaculos();
        Inimigo* geraInimigos();
        
        void incluir(ListaEntidades* lista, Entidade* l);

        void gameOver();

        void executar();
};


#endif