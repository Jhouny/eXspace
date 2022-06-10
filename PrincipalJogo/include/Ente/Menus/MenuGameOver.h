#ifndef _MENU_GAME_OVER_H_
#define _MENU_GAME_OVER_H_

#include "Menu.h"
#include "../../Auxiliares/Lista.h"
#include "../../Controle/ControleTexto.h"
#include "../../Controle/ControleMenu.h"
#include "../Entidades/Dinamicas/Jogador.h"
#include "../../ElementosGraficos/BotaoSalvar.h"

namespace ElementosGraficos{
    class Texto;
}


namespace Menus{
    class MenuGameOver: public Menu {
        private:
            std::vector<ElementosGraficos::Texto*> lTextos;
            ElementosGraficos::Texto* pTexto;
            ElementosGraficos::Texto* pTextoNome;
            ElementosGraficos::Texto* pTextoPontuacao;
            ElementosGraficos::BotaoSalvar* pBotaoSalvar;

            Controle::ControleTexto pControleTexto;
            Controle::ControleMenu pControleMenu; 

            std::multimap<int,std::string> mapaPontuacao;
            std::multimap<int,std::string>::iterator itPont;

            std::string nome;
            int pontuacao;

            Entidades::Personagens::Jogador* jogador1;
            Entidades::Personagens::Jogador* jogador2;

        public:
            MenuGameOver();

            ~MenuGameOver();

            void criaBotoes();

            void criaTextos();

            void setPontuacao(int pont);

            int getPontuacao() const { return pontuacao; }

            std::string getNome(){ return nome; }

            std::multimap<int,std::string>* getMap(){ return &mapaPontuacao; }

            void renderizar();

            void atualizar(const float dt);

            void incluir(ElementosGraficos::Texto *texto);

            void leArquivoPontuacao();

            void ativarControle();
            void desativarControle();

            void executar(const float dt);
    };
}

#endif