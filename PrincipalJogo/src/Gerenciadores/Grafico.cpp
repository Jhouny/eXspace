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
        event(new sf::Event),
        cameraPrincipal(new sf::View),
        cameraSecundaria(new sf::View)
    {
        // Limita a frequencia da janela
        window->setFramerateLimit(FPS);
        
        // Define a posição e tamanho iniciais da camera
        cameraPrincipal->setCenter(sf::Vector2f(COMPRIMENTO / 2.f , ALTURA / 2.f));        
        cameraPrincipal->setSize(sf::Vector2f(COMPRIMENTO, ALTURA));  
        cameraSecundaria->setCenter(sf::Vector2f(COMPRIMENTO / 2.f , ALTURA / 2.f));        
        cameraSecundaria->setSize(sf::Vector2f(COMPRIMENTO, ALTURA));        
        window->setView(*cameraPrincipal);
    }

    Grafico::~Grafico() {
        delete(window);
    }

    void Grafico::draw(sf::RectangleShape* shape) {
        window->setView(*cameraPrincipal);
        window->draw(*shape);
        window->setView(*cameraSecundaria);
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

    void Grafico::terminar() {
        window->close();
    }

    // Define a posição da janela principal
    void Grafico::setCenter(Coordenada c1) {
        cameraPrincipal->setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
        cameraPrincipal->setCenter(sf::Vector2f(c1.x, c1.y));
    }

    // Divide a tela e define a posição de cada janela
    void Grafico::setCenter(Coordenada c1, Coordenada c2) {
        cameraPrincipal->setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
        cameraPrincipal->setCenter(sf::Vector2f(c1.x, c1.y));
        
        cameraSecundaria->setViewport(sf::FloatRect(0.5f, 0.f, 1.f, 1.f));
        cameraSecundaria->setCenter(sf::Vector2f(c2.x, c2.y));
    }

    sf::Event* Grafico::getEvent() const {
        return event;
    }

    sf::RenderWindow* Grafico::getWindow() const {
        return window;
    }
}