#ifndef _JOGO_H_
#define _JOGO_H_

#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/Eventos.h"
#include "Ente/Menus/MenuAbertura.h"
#include "Ente/Menus/MenuPontuacao.h"
#include "Ente/Menus/Fase.h"
#include "Ente/Menus/MenuJogar.h"
#include "Ente/Menus/MenuGameOver.h"
#include "Controle/ControleJogador.h"
#include "Estados/MaquinaEstados.h"


class Jogo: public Estados::MaquinaEstados {
    private:
        Jogador* jogador1;
        Jogador* jogador2;
        
        Gerenciadores::Grafico* pGrafico;
        Gerenciadores::Eventos* pEventos;

        sf::Clock temporizador;
        float dt;

        /*Fase fase1;

        Menus::MenuAbertura menuAbertura;
        Menus::MenuPontuacao menuPontuacao;*/
        //Fase fase2;
    public:
        Jogo();

        ~Jogo();

        void executar();
};


#endif