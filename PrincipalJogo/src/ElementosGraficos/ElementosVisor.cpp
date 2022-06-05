#include "../../include/ElementosGraficos/ElementosVisor.h"

namespace ElementosGraficos {
    ElementosVisor::ElementosVisor(Jogador* jog1, Jogador* jog2):
        pGrafico(Gerenciadores::Grafico::getInstancia()),
        pJog1(jog1),
        pJog2(jog2)
    {
        executar();
    }

    ElementosVisor::~ElementosVisor() {

    }

    // Cria n pontos de um tipo PontoID
    void ElementosVisor::criaPontosEspacados(int n, PontoID pID) {
        int i;
        switch (pID) {
        case PontoID::coracao:
            for(i = 0; i < n; i++) {
                pCor = new Coracao(Coordenada(PADDING_BORDA + i*(TAMANHO_PADRAO_CORACAO.x + ESPACAMENTO_PONTOS), 40), pJog1);
                vidaJog1.emplace_back(pCor);
            }

            if(pJog2 != NULL) {
                for(i = 0; i < n; i++) {
                    pCor = new Coracao(Coordenada(COMPRIMENTO - PADDING_BORDA - i*(TAMANHO_PADRAO_CORACAO.x + ESPACAMENTO_PONTOS), 40), pJog1);
                    vidaJog2.emplace_back(pCor);
                }
            }
            break;
        
        case PontoID::inimigoAbatido:
            for(i = 0; i < n; i++) {
                pIni = new InimigoAbatido(Coordenada(PADDING_BORDA + i*(TAMANHO_PADRAO_INIMIGO_ABATIDO.x + ESPACAMENTO_PONTOS), 80), pJog1);
                inimigosAbatidos.emplace_back(pIni);
            }
            break;
        }
    }

    void ElementosVisor::renderizar() {
        std::vector<Coracao*>::iterator it;
        for(it = vidaJog1.begin(); it != vidaJog1.end(); it++) {
            pGrafico->draw((*it)->getSprite(), false);
        }
        for(it = vidaJog2.begin(); it != vidaJog2.end(); it++) {
            pGrafico->draw((*it)->getSprite(), false);
        }

        std::vector<InimigoAbatido*>::iterator it2;
        for(it2 = inimigosAbatidos.begin(); it2 != inimigosAbatidos.end(); it2++) {
            pGrafico->draw((*it2)->getSprite(),false);
        }
    }

    void ElementosVisor::atualizaPontuacao() {
        std::vector<Coracao*>::iterator it;
        for(it = vidaJog1.begin(); it != vidaJog1.end(); it++) {
            (*it)->executar(pJog1->getPosicao());
        }

        // 
        int v = pJog1->getVida();
        int tam = vidaJog1.size();
        for(int i = 0; i < tam; i++) {
            if(v < 100*i/(float)tam)
                vidaJog1[i]->limpar();
        }

        if(pJog2 != NULL) {
            for(it = vidaJog2.begin(); it != vidaJog2.end(); it++) {
                (*it)->executar(pJog2->getPosicao());
            }
        }

        std::vector<InimigoAbatido*>::iterator it2;
        for(it2 = inimigosAbatidos.begin(); it2 != inimigosAbatidos.end(); it2++) {
            (*it2)->executar(pJog1->getPosicao());
        }
    }

    void ElementosVisor::resetarVisor() {
        vidaJog1.clear();
        vidaJog2.clear();
        inimigosAbatidos.clear();

        executar();
    }

    void ElementosVisor::executar() {
        criaPontosEspacados(10, PontoID::coracao);

        criaPontosEspacados(6, PontoID::inimigoAbatido);
    }
} // namespace ElementosGraficos 

