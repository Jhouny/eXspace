#ifndef _MENU_H_
#define _MENU_H_

#define TEX_FUNDO_UM "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo1.jpg"
#define TEX_FUNDO_DOIS "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo3.jpg"
#define TEX_FUNDO_TRES "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo4.jpg"
#define TEX_FUNDO_QUATRO "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo5.jpg"
#define TEX_FUNDO_CINCO "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo6.jpg"
#define TEX_FUNDO_SEIS "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo7.jpg"
#define TEX_FUNDO_SETE "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo8.jpg"
#define TEX_FUNDO_OITO "PrincipalJogo/assets/Texturas/Backgrounds/Menu/fundo9.jpg"

#include "../Ente.h"
#include "../../Auxiliares/Lista.h "
#include "../../ElementosGraficos/Botao.h"
#include "../../ElementosGraficos/BotaoAlternador.h"
#include "../../Gerenciadores/Grafico.h"
#include "../../Controle/ControleMenu.h"
#include "../../Estados/Estado.h"

namespace ElementosGraficos {
    class Texto;
}


namespace Menus{
    class Menu: public Ente, public Estados::Estado {
        protected:
            std::map<ElementosGraficos::Botao*, bool> botoesAtivos;
            std::map<ElementosGraficos::Botao*, bool>::iterator it;
            ElementosGraficos::Texto titulo;

            Estados::IdEstado idEst;

            sf::Sprite fundo;
            sf::Clock relogio;

            
            Controle::ControleMenu pControle;
            ElementosGraficos::Botao* pBotao;
        public:
            Gerenciadores::Grafico* pGrafico;
            Menu();

            ~Menu();

            void getAtivo();

            void subirSelecao();

            void descerSelecao();

            void reiniciarRelogio(){ relogio.restart(); }

            void entrar();

            void voltar();

            void setFundoAleatorio();

            void setTexture(const char* path);

            void setTitulo(const char* titu);
            ElementosGraficos::Texto* getTitulo() { return &titulo; }

            void ativarControle();

            void desativarControle();

            virtual void criaBotoes() = 0;

            virtual void renderizar() = 0;

            virtual void atualizar(const float dt) = 0;

            virtual void executar(const float dt) = 0;

    };
}

#endif