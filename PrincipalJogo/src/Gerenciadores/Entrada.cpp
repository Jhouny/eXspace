#include "../../include/Gerenciadores/Entrada.h"
#include "../../include/Controle/Observador.h"

namespace Gerenciadores{
    Entrada* Entrada::instancia = NULL;

    Entrada::Entrada() {
        mapaTeclas[sf::Keyboard::A] = "A";
        mapaTeclas[sf::Keyboard::B] = "B";
        mapaTeclas[sf::Keyboard::C] = "C";
        mapaTeclas[sf::Keyboard::D] = "D";
        mapaTeclas[sf::Keyboard::E] = "E";
        mapaTeclas[sf::Keyboard::F] = "F";
        mapaTeclas[sf::Keyboard::G] = "G";
        mapaTeclas[sf::Keyboard::H] = "H";
        mapaTeclas[sf::Keyboard::I] = "I";
        mapaTeclas[sf::Keyboard::J] = "J";
        mapaTeclas[sf::Keyboard::K] = "K";
        mapaTeclas[sf::Keyboard::L] = "L";
        mapaTeclas[sf::Keyboard::M] = "M";
        mapaTeclas[sf::Keyboard::N] = "N";
        mapaTeclas[sf::Keyboard::O] = "O";
        mapaTeclas[sf::Keyboard::P] = "P";
        mapaTeclas[sf::Keyboard::Q] = "Q";
        mapaTeclas[sf::Keyboard::R] = "R";
        mapaTeclas[sf::Keyboard::S] = "S";
        mapaTeclas[sf::Keyboard::T] = "T";
        mapaTeclas[sf::Keyboard::U] = "U";
        mapaTeclas[sf::Keyboard::V] = "V";
        mapaTeclas[sf::Keyboard::W] = "W";
        mapaTeclas[sf::Keyboard::X] = "X";
        mapaTeclas[sf::Keyboard::Y] = "Y";
        mapaTeclas[sf::Keyboard::Z] = "Z";
        mapaTeclas[sf::Keyboard::Num1] = "1";
        mapaTeclas[sf::Keyboard::Num2] = "2";
        mapaTeclas[sf::Keyboard::Num3] = "3";
        mapaTeclas[sf::Keyboard::Num4] = "4";
        mapaTeclas[sf::Keyboard::Num5] = "5";
        mapaTeclas[sf::Keyboard::Num6] = "6";
        mapaTeclas[sf::Keyboard::Num7] = "7";
        mapaTeclas[sf::Keyboard::Num8] = "8";
        mapaTeclas[sf::Keyboard::Num9] = "9";
        mapaTeclas[sf::Keyboard::Num0] = "0";
        mapaTeclas[sf::Keyboard::Numpad0] = "0";
        mapaTeclas[sf::Keyboard::Numpad1] = "1";
        mapaTeclas[sf::Keyboard::Numpad2] = "2";
        mapaTeclas[sf::Keyboard::Numpad3] = "3";
        mapaTeclas[sf::Keyboard::Numpad4] = "4";
        mapaTeclas[sf::Keyboard::Numpad5] = "5";
        mapaTeclas[sf::Keyboard::Numpad6] = "6";
        mapaTeclas[sf::Keyboard::Numpad7] = "7";
        mapaTeclas[sf::Keyboard::Numpad8] = "8";
        mapaTeclas[sf::Keyboard::Numpad9] = "9";
        mapaTeclas[sf::Keyboard::Space] = "Space";
        mapaTeclas[sf::Keyboard::Enter] = "Enter";
        mapaTeclas[sf::Keyboard::Escape] = "Escape";
        mapaTeclas[sf::Keyboard::BackSpace] = "BackSpace";
        mapaTeclas[sf::Keyboard::Right] = "Right";
        mapaTeclas[sf::Keyboard::Left] = "Left";
        mapaTeclas[sf::Keyboard::Up] = "Up";
        mapaTeclas[sf::Keyboard::Down] = "Down";
        mapaTeclas[sf::Keyboard::LControl] = "Control";
        mapaTeclas[sf::Keyboard::LShift] = "Shift";
        mapaTeclas[sf::Keyboard::RControl] = "RControl";
        mapaTeclas[sf::Keyboard::RShift] = "RShift";
        mapaTeclas[sf::Keyboard::Hyphen] = "-";
        mapaTeclas[sf::Keyboard::Tab] = "Tab";
    }

    Entrada::~Entrada(){
        lObservador.clear();
        mapaTeclas.clear();
    }
    Entrada* Entrada::getInstancia() {
        if(instancia == NULL){
            instancia = new Entrada();
        }
        return instancia;
    }   

    void Entrada::adicionar(Controle::Observador* obs){
        lObservador.push(obs);
    }
    
    void Entrada::remover(Controle::Observador* obs){
        int i;
        for(i = 0; i < lObservador.getTamanho() && lObservador[i]->getID() != obs->getID(); i++ );

        lObservador.removeIndice(i);
    }
    void Entrada::teclaPressionada(sf::Keyboard::Key tecla){
        for(int i = 0; i < lObservador.getTamanho(); i++) {
            lObservador[i]->compartilharTeclaPressionada(teclaString(tecla)); 
        }
    }

    void Entrada::teclaLiberada(sf::Keyboard::Key tecla){
        for(int i = 0; i < lObservador.getTamanho(); i++){
            lObservador[i]->compartilharTeclaLiberada(teclaString(tecla));
        }
    }

    std::string Entrada::teclaString(sf::Keyboard::Key tecla){
        if(mapaTeclas[tecla] == "")
            return "Não foi possível acessar a tecla "" ";
        return mapaTeclas[tecla];
    }
}