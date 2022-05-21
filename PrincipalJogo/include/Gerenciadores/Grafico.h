#ifndef _GRAFICO_H_
#define _GRAFICO_H_

#include"../Auxiliares/stdafx.h"

namespace Gerenciadores {
    class Grafico {
        private:
            sf::RenderWindow* window;
            sf::Event* event;
            sf::View *cameraPrincipal, *cameraSecundaria;

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

            void terminar();

            void setCenter(Coordenada c1);

            void setCenter(Coordenada c1, Coordenada c2);

            sf::Event* getEvent() const;

            sf::RenderWindow* getWindow() const;
    };
};

#endif