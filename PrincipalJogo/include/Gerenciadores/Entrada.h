#ifndef _ENTRADA_H_
#define _ENTRADA_H_

#include "../Auxiliares/Lista.h"

namespace Controle{
    class Observador;
}

namespace Gerenciadores {
    class Entrada{
        private:
            Lista<Controle::Observador> lObservador;
            static Entrada* instancia;
            std::map <sf::Keyboard::Key, std::string> mapaTeclas;
            Entrada();
            
        public:
            ~Entrada();

            static Entrada* getInstancia();

            void adicionar(Controle::Observador* obs);

            void remover(Controle::Observador* obs);

            void teclaPressionada();

            void teclaLiberada(sf::Keyboard::Key tecla);

            std::string teclaString(sf::Keyboard::Key tecla);
    };
}



#endif