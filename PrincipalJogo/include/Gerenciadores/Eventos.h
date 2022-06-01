#ifndef _EVENTOS_H_
#define _EVENTOS_H_

#include "Entrada.h"
#include "Grafico.h"

namespace Gerenciadores {
    class Eventos {
        private:
            static Eventos* instancia;
            
            Gerenciadores::Entrada* pEntrada;

            Gerenciadores::Grafico* pGrafico;

            sf::RenderWindow* pWindow;
            sf::Event evento;

            Eventos();
        public:
            ~Eventos();

            static Eventos* getInstancia();

            void checarEventos();
    };

}



#endif