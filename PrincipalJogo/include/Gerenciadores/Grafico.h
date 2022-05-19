#ifndef _GRAFICO_H_
#define _GRAFICO_H_

#include"../Auxiliares/stdafx.h"

namespace Gerenciadores {
    class Grafico {
        private:
            sf::RenderWindow* window; // window.setFrameLimit(60);
            sf::Event* event;
            
            /* Seguindo a sugestão do monitor Matheus Burda, usa-se o padrão Singleton */
            static Gerenciadores::Grafico* instancia;
            Grafico();
            
        public:
            ~Grafico();

            static Grafico* getInstancia();

            void draw(sf::RectangleShape* shape);

            void clear();

            void display();

            bool isOpened() const;

            void shutdown();

            sf::Event* getEvent() const; 

            sf::RenderWindow* getWindow() const;
    };
};

#endif