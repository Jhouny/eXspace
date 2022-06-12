#ifndef _ESTADO_H_
#define _ESTADO_H_

#include "../Auxiliares/stdafx.h"

namespace Menus {
    class Menu;
}

namespace Estados {
    class MaquinaEstados;

    enum IdEstado {
        indefinido = -1,
        menuJogar,
        pontuacao,
        sair,
        menuAbertura,
        menuGameOver,
        menuPausa,
        menuTransicao,
        mercurio,
        netuno,
        selecionarFase,
        selecionarJogadores,
        salvarPontuacao,
        salvarJogo,
        alternar,
        carregar,
        menuCarregar
    };

    class Estado {
        protected:
            Estado* anterior;  // Define o menu anterior para poder retornar
            IdEstado id;
            Menus::Menu* pMenu;
            MaquinaEstados* pMaq;
        public:
            Estado(Menus::Menu* pMenu, IdEstado mid = indefinido);

            ~Estado();

            Menus::Menu* getMenu() { return pMenu; }

            void setMaquina(MaquinaEstados* pM) { pMaq = pM; }
            MaquinaEstados* getMaquina() const { return pMaq; }

            void setID(IdEstado mid) { id = mid; } 
            IdEstado getID() const { return id; }

            Estado* getAnterior() { return anterior; }
            void setAnterior(Estado* est) { anterior = est; }

            void observar();

            void cegar();

            virtual void atualizar(const float dt) = 0;

            virtual void renderizar() = 0;

            virtual void executar(const float dt) = 0;
    };    
} // namespace Estados


#endif