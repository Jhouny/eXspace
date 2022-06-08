#ifndef _BOTAO_SALVAR_H_
#define _BOTAO_SALVAR_H_
#include "Botao.h"

#include"../Ente/Menus/Fases/Fase.h"

#define PONTUACAO_PATH "PrincipalJogo/saves/pontuacao.txt"
namespace Menus{
    class MenuGameOver;
}

namespace ElementosGraficos {
    class BotaoSalvar:public Botao{
        private:
            Menus::MenuGameOver* pMenuGameOver;
            std::multimap<int, std::string> mapPontuacao;
        public:
            BotaoSalvar(Coordenada tam, Coordenada pos, Menus::MenuGameOver* pMenu, std::string nome = "");
            ~BotaoSalvar();
            void salvar();

    };
}

#endif