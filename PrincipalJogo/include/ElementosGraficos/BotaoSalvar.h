#ifndef _BOTAO_SALVAR_H_
#define _BOTAO_SALVAR_H_
#include "Botao.h"

#include"../Ente/Menus/Fases/Fase.h"

#define PONTUACAO_PATH "PrincipalJogo/saves/pontuacao.txt"
#define TEX_BOTAO_SALVAR_ATIVO "PrincipalJogo/assets/Texturas/Botoes/botaoSalvarAtivo.png"

namespace Menus{
    class MenuGameOver;
}

namespace ElementosGraficos {
    class BotaoSalvar:public Botao{
        private:
            Menus::MenuGameOver* pMenuGameOver;
            std::multimap<int, std::string> mapPontuacao;
            sf::Clock temporizador;
            bool inicio;
        public:
            BotaoSalvar(Coordenada tam, Coordenada pos, Menus::MenuGameOver* pMenu, std::string nome = "");
            
            ~BotaoSalvar();
            
            void salvar();

            void atualizarTextura();
    };
}

#endif