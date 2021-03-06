#ifndef _CONTROLE_TEXTO_H_
#define _CONTROLE_TEXTO_H_
#include "Observador.h"



namespace Menus{
    class Menu;
}


namespace Controle{
    class ControleTexto: public Observador{
        private:
            std::string nome;
            std::string espaco;
            std::string apagar;
            Menus::Menu* pMenu;
            const int tamMax;
            int contador;
        public:
            ControleTexto(Menus::Menu * menu);

            ~ControleTexto();

            void compartilharTeclaPressionada(std::string tecla);

            void compartilharTeclaLiberada(std::string tecla);

            const char* getNome(){ return nome.c_str() ;}

            std::string getNomeString() { return nome;}

            void apagaNome();
    };

}



#endif