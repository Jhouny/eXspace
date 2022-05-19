#include"../../include/Gerenciadores/Grafico.h"

#define COMPRIMENTO 1280
#define ALTURA 720
#define FPS 60

namespace Gerenciadores {
    Grafico* Grafico::instancia = nullptr;

    /* Returns a pointer to the Graphics. */
    Grafico* Grafico::getInstancia() {
        if (instancia == nullptr) {
            instancia = new Grafico();
        }
        return instancia;
    }

    Grafico::Grafico():
    window(new sf::RenderWindow(sf::VideoMode(COMPRIMENTO, ALTURA), "NULL")),
    event(new sf::Event)    
        {
            window->setFramerateLimit(FPS);
        
    }

    Grafico::~Grafico() {
        delete(window);
    }

    void Grafico::draw(sf::RectangleShape* shape) {
        window->draw(*shape);
    }

    void Grafico::clear() {
        window->clear();
    }

    void Grafico::display() {
        window->display();
    }

    bool Grafico::isOpened() const {
        return window->isOpen();
    }

    void Grafico::shutdown() {
        window->close();
    }

    sf::Event* Grafico::getEvent() const {
        return event;
    }

    sf::RenderWindow* Grafico::getWindow() const {
        return window;
    }
}