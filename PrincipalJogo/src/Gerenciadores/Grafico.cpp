#include"../../include/Gerenciadores/Grafico.h"
#include "../../include/Ente/Entidades/Dinamicas/Jogador.h"

namespace Gerenciadores {
    Grafico* Grafico::instancia = NULL;

    /* Returns a pointer to the Graphics. */
    Grafico* Grafico::getInstancia() {
        if (instancia == NULL) {
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



    void Grafico::draw(sf::RectangleShape* shape, bool map) {
        window->setView(view);
        window->draw(*shape);
        if(map) {
            window->setView(minimap);
            window->draw(*shape);
        }
    }

    void Grafico::draw(sf::Sprite* sp, bool map) {
        window->setView(view);
        window->draw(*sp);
        if(map){
            window->setView(minimap);
            window->draw(*sp);
        }
    }

    void Grafico::draw(sf::Text* texto){
        window->draw(*texto);
    }

    void Grafico::setRotate(){
        view.rotate(0.5);
    }

    void Grafico::atualizaView(Coordenada pos){
        view.setCenter(pos.x, ALTURA/2.f);  // Segue no X mas não no Y
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

    
    sf::Texture* Grafico::loadTexture(const char* path) {
        
        std::map<const char*, sf::Texture*>::iterator it = mapaTexturas.begin();
        while (it != mapaTexturas.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        
        sf::Texture* tex = new sf::Texture();

        if (!tex->loadFromFile(path)) {
            cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        mapaTexturas.insert(std::pair<const char*, sf::Texture*>(path, tex));

        return tex;
    }

    sf::Font* Grafico::carregaFonte(const char* path) {
        std::map<const char*, sf::Font*>::iterator it = mapaFontes.begin();
        while (it != mapaFontes.end()) {
            if (!strcmp(it->first, path))
                return it->second;
            it++;
        }

        
        sf::Font* fonte = new sf::Font();

        if (!fonte->loadFromFile(path)) {
            std::cout << "ERROR loading file " << path << std::endl;
            exit(1);
        }

        mapaFontes.insert(std::pair<const char*, sf::Font*>(path, fonte));

        return fonte;
    }

    // Define a posição da janela principal

    sf::Event* Grafico::getEvent() {
        return event;
    }

    sf::RenderWindow* Grafico::getWindow() const {
        return window;
    }
}