#include "../../include/Gerenciadores/Eventos.h"

namespace Gerenciadores {
    Eventos* Eventos::instancia = NULL;

    Eventos* Eventos::getInstancia(){
        if(instancia == NULL){
            instancia = new Eventos();
        }
        return instancia;
    }

    Eventos::Eventos(): 
        pEntrada(Gerenciadores::Entrada::getInstancia()),
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        pWindow(pGrafico->getWindow()),
        evento(*pGrafico->getEvent())
    {
        
    }

    Eventos::~Eventos() {
        
    }

    void Eventos::checarEventos() {
        
        while(pWindow->pollEvent(evento)) {
            if(evento.type == sf::Event::Closed)
                pGrafico->terminar();

            if(evento.type == sf::Event::KeyPressed) {
                pEntrada->teclaPressionada(evento.key.code);
            }

            if(evento.type == sf::Event::KeyReleased)
                pEntrada->teclaLiberada(evento.key.code);
        }
    }
}