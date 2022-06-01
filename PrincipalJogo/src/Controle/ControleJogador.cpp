#include "../../include/Controle/ControleJogador.h"
#include "../../include/Ente/Entidades/Dinamicas/Jogador.h"

namespace Controle {
    ControleJogador::ControleJogador(Jogador* pJog):
        Observador(),
        pJogador(pJog),
        teclasPressionadas(),
        pular("W"),
        esquerda("A"),
        direita("D"),
        atacar("Space")
        {
            teclasPressionadas.insert(std::pair<std::string, bool>(pular, false));
            teclasPressionadas.insert(std::pair<std::string, bool>(esquerda, false));
            teclasPressionadas.insert(std::pair<std::string, bool>(direita, false));
            teclasPressionadas.insert(std::pair<std::string, bool>(atacar, false));
    }

    ControleJogador::~ControleJogador() {
        pJogador = NULL;
    }

    void ControleJogador::compartilharTeclaPressionada() {
        cout << "COMPARTILHAR" << endl;
        if(pJogador == NULL) {
            cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaPressionada()" << endl;
            exit(1);
        }
        /*
        if(tecla == pular) {
            //teclasPressionadas[pular] = true;
            pJogador->pular();
        } 
        if(tecla == esquerda) {
            //teclasPressionadas[esquerda] = true;
            pJogador->esquerda();
        } 
        if(tecla == direita) {
            //teclasPressionadas[direita] = true;
            pJogador->direita();
        } 
        if(tecla == atacar) {
            //teclasPressionadas[atacar] = true;
            pJogador->atacar();
        }*/
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            //teclasPressionadas[pular] = true;
            pJogador->pular();
        } 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //teclasPressionadas[esquerda] = true;
            pJogador->esquerda();
        } 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //teclasPressionadas[direita] = true;
            pJogador->direita();
        } 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            //teclasPressionadas[atacar] = true;
            pJogador->atacar();
        }
    }

    void ControleJogador::compartilharTeclaLiberada(std::string tecla) {
        if(pJogador == NULL) {
            cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaLiberada()" << endl;
            exit(1);
        }

        if(tecla == pular) {
            //teclasPressionadas[pular] = false;
        } else if(tecla == esquerda) {
            //teclasPressionadas[esquerda] = false;
        } else if(tecla == direita) {
            //teclasPressionadas[direita] = false;
        } else if(tecla == atacar) {
            //teclasPressionadas[atacar] = false;
        }
    }
}