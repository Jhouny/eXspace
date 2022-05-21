#include "../../include/Gerenciadores/Colisoes.h"

namespace Gerenciadores {
    Colisor::Colisor() { }

    Colisor::~Colisor() {
        lDinamicas = NULL;
        lEstaticas = NULL;
    }

    void Colisor::ChecarColisoes() {
        Entidade *ent1, *ent2;
        Coordenada centroEnt1, centroEnt2, intersecao;
        int i, j;

        // Colisões de elementos Dinamicos com Estáticos
        for(i = 0; i < lDinamicas->getTamanho(); i++) {
            ent1 = (*lDinamicas)[i];
            for(j = 0; j < lEstaticas->getTamanho(); j++) {
                ent2 = (*lEstaticas)[j];

                // Calcula as coordenadas dos centros dos dois objetos
                centroEnt1.x = ent1->getPosicao().x + (ent1->getTamanho().x / 2.0f);
                centroEnt1.y = ent1->getPosicao().y + (ent1->getTamanho().y / 2.0f);

                centroEnt2.x = ent2->getPosicao().x + (ent2->getTamanho().x / 2.0f);
                centroEnt2.y = ent2->getPosicao().y + (ent2->getTamanho().y / 2.0f);
                
                // Calcula a distância entre os objetos e subtrai as suas dimensões
                intersecao.x = fabs(centroEnt1.x - centroEnt2.x) - (ent1->getTamanho().x + ent2->getTamanho().x) / 2.0f;
                intersecao.y = fabs(centroEnt1.y - centroEnt2.y) - (ent1->getTamanho().y + ent2->getTamanho().y) / 2.0f;

                // Se os elementos colidirem, chama a função apropriada
                if(intersecao.x < 0 && intersecao.y < 0) {
                    ent1->colisao(ent2, intersecao);
                }
            }
        }

        // Colisões de elementos Dinamicos com Dinamicos
        for(i = 0; i < lDinamicas->getTamanho(); i++) {
            ent1 = (*lDinamicas)[i];
            for(j = i + 1; j < lDinamicas->getTamanho(); j++) {  // Checa colisões apenas com os que não foram processados (i + 1)
                ent2 = (*lDinamicas)[j];

                // Calcula as coordenadas dos centros dos dois objetos
                centroEnt1.x = ent1->getPosicao().x + (ent1->getTamanho().x / 2.0f);
                centroEnt1.y = ent1->getPosicao().y + (ent1->getTamanho().y / 2.0f);
                centroEnt2.x = ent2->getPosicao().x + (ent2->getTamanho().x / 2.0f);
                centroEnt2.y = ent2->getPosicao().y + (ent2->getTamanho().y / 2.0f);
                
                // Calcula a distância entre os objetos e subtrai as suas dimensões
                intersecao.x = fabs(centroEnt1.x - centroEnt2.x) - (ent1->getTamanho().x + ent2->getTamanho().x) / 2.0f;
                intersecao.y = fabs(centroEnt1.y - centroEnt2.y) - (ent1->getTamanho().y + ent2->getTamanho().y) / 2.0f;

                // Se os elementos colidirem, chama a função apropriada
                if(intersecao.x < 0 && intersecao.y < 0) {
                    ent1->colisao(ent2, intersecao);
                    ent2->colisao(ent1, intersecao);
                }
            }
        }
    }
}