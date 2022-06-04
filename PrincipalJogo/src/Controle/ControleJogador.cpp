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
        if(this->getAtivo()){
            if(pJogador == NULL) {
                cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaPressionada()" << endl;
                exit(1);
            }
            
            if(tecla == pular) {
                teclasPressionadas[pular] = true;
                pJogador->pular();
                pJogador->pulo(true);
            } 

            if(tecla == esquerda) {
                teclasPressionadas[esquerda] = true;
                pJogador->esquerda();
            }
            if(tecla == direita) {
                teclasPressionadas[direita] = true;
                pJogador->direita();
            } 

            if(tecla == atacar) {
                teclasPressionadas[atacar] = true;
                pJogador->atacar();
                pJogador->ataque(true);
            }
        }
    }

    void ControleJogador::compartilharTeclaLiberada(std::string tecla) {
        if(this->getAtivo()){
            if(pJogador == NULL) {
                cout << "ERRO: Ponteiro para jogador nao definido em ControleJogador::compartilharTeclaLiberada()" << endl;
                exit(1);
            }
            
            if(tecla == pular) {
                teclasPressionadas[pular] = false;
                pJogador->pulo(false);
            } 
            if(tecla == esquerda) {
                teclasPressionadas[esquerda] = false;
                if(teclasPressionadas[direita])
                    pJogador->direita();
                else
                    pJogador->parar();
            } 
            if(tecla == direita) {
                teclasPressionadas[direita] = false;
                if(teclasPressionadas[esquerda])
                    pJogador->esquerda();
                else
                    pJogador->parar();
            } 
            if(tecla == atacar) {
                teclasPressionadas[atacar] = false;
                pJogador->ataque(false);
            }
        }
    }
}