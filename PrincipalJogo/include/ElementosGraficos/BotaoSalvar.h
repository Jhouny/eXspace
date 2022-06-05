#ifndef _BOTAO_SALVAR_H_
#define _BOTAO_SALVAR_H_
#include "Botao.h"

#include"../Ente/Menus/Fase.h"
#define PONTUACAO_PATH ""
namespace Menus{
    class MenuGameOver;
}

namespace ElementosGraficos{
    class BotaoSalvar:public Botao{
        private:
            Menus::Fase* pFase;
            Menus::MenuGameOver* pMenuGameOver;
        public:
            BotaoSalvar(Coordenada tam, Coordenada pos);
            ~BotaoSalvar();
            void salvar();

    };
}

#endif