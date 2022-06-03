#ifndef _CONTROLE_TEXTO_H_
#define _CONTROLE_TEXTO_H_
#include "Observador.h"

namespace Menus{
    class MenuGameOver;
}


namespace Controle{
    class ControleTexto: public Observador{
        private:
            std::string nome;
            std::string espaco;
            std::string apagar;
            Menus::MenuGameOver* pMenu;
            const int tamMax;
            int contador;
        public:
            ControleTexto(Menus::MenuGameOver * menu);

            ~ControleTexto();

            void compartilharTeclaPressionada(std::string tecla);

            void compartilharTeclaLiberada(std::string tecla);

            const char* getNome(){ return nome.c_str() ;}

            void apagaNome();
    };

}



#endif