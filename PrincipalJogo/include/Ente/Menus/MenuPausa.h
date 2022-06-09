#ifndef _MENU_PAUSA_H_
#define _MENU_PAUSA_H_

#include "Menu.h"
#include "Fases/Fase.h"
#include "../../Controle/ControleMenu.h"
#include "../../Controle/ControleTexto.h"

#define TEX_FUNDO_PAUSA "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundoPausa.jpg"
#define SALVAR_JOGO_PATH "PrincipalJogo/saves/jogos/"  // Salva os jogos no diretorio

namespace Menus {
    class MenuPausa: public Menu {
        private:
            Controle::ControleTexto pControleTexto;
            Controle::ControleMenu pControleMenu; 

            std::string pathSalvar;  // Nome e diretório para onde salvar o jogo
            std::list<Entidades::Entidade*> *pListaEntidades;

            std::vector<ElementosGraficos::Texto*> lTextos;
            ElementosGraficos::Texto* pTextoArq;  // Texto para definir o nome do arquivo
            ElementosGraficos::Botao* pBotaoVoltar;
            ElementosGraficos::Botao* pBotaoSalvar;

            Estados::IdEstado faseID;

            Menus::Fases::Fase* pFase;
        public:
            MenuPausa();

            ~MenuPausa();
            // AQUI!!! -/-
            void setFaseID(Estados::IdEstado id) { faseID = id; }

            void setLista(std::list<Entidades::Entidade*> *pLista) { pListaEntidades = pLista; }

            void criaBotoes();

            void criaTextos();

            void resumirJogo();

            void ativarControle();
            void desativarControle();

            void salvaEstado();

            void atualizar(const float dt);

            void renderizar();

            void executar(const float dt);
    };
}

#endif