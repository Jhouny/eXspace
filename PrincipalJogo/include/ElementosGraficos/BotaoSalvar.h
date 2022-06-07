#ifndef _BOTAO_SALVAR_H_
#define _BOTAO_SALVAR_H_
#include "Botao.h"

#include"../Ente/Menus/Fases/Fase.h"

#define PONTUACAO_PATH "PrincipalJogo/saves/pontuacao.txt"
namespace Menus{
    class MenuGameOver;
}

namespace ElementosGraficos{
    class BotaoSalvar:public Botao{
        private:
            Menus::MenuGameOver* pMenuGameOver;
        public:
            BotaoSalvar(Coordenada tam, Coordenada pos, std::string nome,Menus::MenuGameOver* pMenu = NULL);
            ~BotaoSalvar();
            void salvar();

    };
}

#endif