#include"../../include/Gerenciadores/Grafico.h"
#include "../../include/Ente/Entidades/Dinamicas/Jogador.h"
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
        event(new sf::Event)//,
       // cameraPrincipal(new sf::View),
        //cameraSecundaria(new sf::View)
    {
        // Limita a frequencia da janela
        window->setFramerateLimit(FPS);
        
        // Define a posição e tamanho iniciais da camera
        /*cameraPrincipal->setCenter(sf::Vector2f(COMPRIMENTO / 2.f , ALTURA / 2.f));        
        cameraPrincipal->setSize(sf::Vector2f(COMPRIMENTO, ALTURA));  
        cameraSecundaria->setCenter(sf::Vector2f(COMPRIMENTO / 2.f , ALTURA / 2.f));        
        cameraSecundaria->setSize(sf::Vector2f(COMPRIMENTO, ALTURA));        
        window->setView(*cameraPrincipal);*/
    }

    Grafico::~Grafico() {
        delete(window);
    }



    void Grafico::draw(sf::RectangleShape* shape) {
        window->setView(view);
        window->draw(*shape);
        window->setView(minimap);
        window->draw(*shape);
    }

    void Grafico::setRotate(){
        view.rotate(0.5);
    }

    void Grafico::atualizaView(Jogador* player){
        Coordenada vetor;
        vetor = player->getPosicao();
        view.setCenter(vetor.x, ALTURA/2.f);  // Segue no X mas não no Y
    }

    void Grafico::atualizaMinimap(Coordenada p){
        minimap.setCenter(p.x,p.y);
    }

    
    void Grafico::setMinimapViewport(){
        minimap.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));
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

    sf::Event* Grafico::getEvent() const {
        return event;
    }

    sf::RenderWindow* Grafico::getWindow() const {
        return window;
    }
}