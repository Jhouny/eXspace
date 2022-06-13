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
            std::vector<ElementosGraficos::Texto*> vTextos;
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

        public:
            MenuGameOver();

            ~MenuGameOver();

            void criaBotoes();

            void criaTextos();

            void setPontuacao(int pont);

            int getPontuacao() const { return pontuacao; }

            std::string getNome(){ return nome; }

            std::multimap<int,std::string>* getMap(){ return &mapaPontuacao; }

            void incluir(ElementosGraficos::Texto *texto);

            void leArquivoPontuacao();

            void ativarControle();
            void desativarControle();

            void renderizar();

            void atualizar(const float dt);

            void executar(const float dt);
    };
}

#endif