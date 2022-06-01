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

    void ControleJogador::compartilharTeclaPressionada(std::string tecla) {
        cout << "COMPARTILHAR" << endl;
        if(pJogador == NULL) {
            cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaPressionada()" << endl;
            exit(1);
        }
        
        if(tecla == pular) {
            teclasPressionadas[pular] = true;
            pJogador->pular();
        } 

        if(tecla == esquerda) {
            teclasPressionadas[esquerda] = true;
            pJogador->esquerda();
        } else if(tecla == direita) {
            teclasPressionadas[direita] = true;
            pJogador->direita();
        } 

        if(tecla == atacar) {
            teclasPressionadas[atacar] = true;
            pJogador->atacar();
        }
    }

    void ControleJogador::compartilharTeclaLiberada(std::string tecla) {
        if(pJogador == NULL) {
            cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaLiberada()" << endl;
            exit(1);
        }

        if(tecla == pular) {
            teclasPressionadas[pular] = false;
        } 
        if(tecla == esquerda) {
            teclasPressionadas[esquerda] = false;
        } 
        if(tecla == direita) {
            teclasPressionadas[direita] = false;
        } 
        if(tecla == atacar) {
            teclasPressionadas[atacar] = false;
        }
    }
}