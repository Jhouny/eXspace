#ifndef _JOGO_H_
#define _JOGO_H_

#include "Ente/Fase/Fase.h"
#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/Eventos.h"

#include "Controle/ControleJogador.h"

class Jogo {
    private:
        Jogador jogador1;
        Jogador jogador2;
        
        Gerenciadores::Grafico* pGrafico;
        Gerenciadores::Eventos* pEventos;

        sf::Clock temporizador;
        float dt;

        Fase fase1;
        //Fase fase2;
    public:
        Jogo();

        ~Jogo();

        void executar();
};


#endif