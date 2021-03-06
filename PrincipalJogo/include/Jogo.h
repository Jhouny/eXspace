#ifndef _JOGO_H_
#define _JOGO_H_

#include "Gerenciadores/Grafico.h"
#include "Gerenciadores/Eventos.h"
#include "Ente/Menus/MenuAbertura.h"
#include "Ente/Menus/MenuPontuacao.h"
#include "Ente/Menus/Fases/Mercurio.h"
#include "Ente/Menus/Fases/Netuno.h"
#include "Ente/Menus/MenuJogar.h"
#include "Ente/Menus/MenuGameOver.h"
#include "Ente/Menus/MenuTransicao.h"
#include "Ente/Menus/MenuCarregar.h"
#include "Ente/Menus/MenuPausa.h"
#include "Controle/ControleJogador.h"
#include "Estados/MaquinaEstados.h"


class Jogo: public Estados::MaquinaEstados {
    private:
        Entidades::Personagens::Jogador* jogador1;
        Entidades::Personagens::Jogador* jogador2;
        
        Gerenciadores::Grafico* pGrafico;
        Gerenciadores::Eventos* pEventos;

        sf::Clock temporizador;
        float dt;

    public:
        Jogo();

        ~Jogo();

        void executar();
};


#endif