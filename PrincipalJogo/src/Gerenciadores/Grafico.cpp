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
        event(new sf::Event)
       
    {
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
        minimap.setCenter(p.x,ALTURA/2.f);
    }

    void Grafico::setMinimapViewport() {
        float comp = 0.3f;
        float alt = comp * 1.5 * ((float)ALTURA / COMPRIMENTO);
        minimap.setViewport(sf::FloatRect(1.f - comp, 0.f, comp, alt));
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