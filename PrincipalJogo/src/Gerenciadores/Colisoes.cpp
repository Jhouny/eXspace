#include "../../include/Gerenciadores/Colisoes.h"

namespace Gerenciadores {
    Colisor::Colisor() { 

    }

    Colisor::~Colisor() {
        
    }

    void Colisor::push(Entidade* ente){
        if(ente->getEstatico()){
            enteEstaticas.push_back(ente);
        }
        else{
            enteDinamicas.push_back(ente);
        }
    }

    void Colisor::ChecarColisoes() {
        Entidade *ent1, *ent2;
        Coordenada centroEnt1, centroEnt2, intersecao;

        // Colisões de elementos Dinamicos com Estáticos
        for(itDinamicas=enteDinamicas.begin(); itDinamicas != enteDinamicas.end(); itDinamicas++) {
            ent1 = *itDinamicas;
            for(itEstaticas = enteEstaticas.begin(); itEstaticas != enteEstaticas.end(); itEstaticas++) {
                ent2 = *itEstaticas;

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
        std::vector<Entidade*>::iterator itDinamicas2;
        itDinamicas2 = enteDinamicas.begin();
        itDinamicas2++;
        // Colisões de elementos Dinamicos com Dinamicos
        for(itDinamicas=enteDinamicas.begin(); itDinamicas != enteDinamicas.end(); itDinamicas++) {
            ent1 = *itDinamicas;
            for(; itDinamicas2 != enteDinamicas.end(); itDinamicas2++) {
                ent2 = *itDinamicas2;

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