#include "../../../../include/Ente/Entidades/Estaticas/gasToxico.h"
#include "../../../../include/Ente/Entidades/Estaticas/Plataforma.h"
namespace Entidades::Obstaculos {
    GasToxico::GasToxico(std::list<Entidades::Entidade*> *l):
        Obstaculo(Coordenada(150,75), Coordenada(0,0), true, true, ID::gasToxico),
        posDefinida(false),
        lista(l),
        dano(0.1)
    {
        setTexture(TEX_GAS);
        
        // Define a posicao do gas de acordo com as plataformas
        std::vector<Entidades::Entidade*> temp(lista->begin(), lista->end());  // Copia os elementos da lista para um vetor temporário
        std::random_shuffle(temp.begin(), temp.end());  // Aleatoriza a posicao dos elementos do vetor
        for(int i = 0; i < temp.size() && !posDefinida; i++) {
            Entidades::Entidade* ent = temp[i];
            if(ent->getID() == ID::plataforma) {
                Entidades::Obstaculos::Plataforma* pPlat = dynamic_cast<Entidades::Obstaculos::Plataforma*>(ent);
                if(ent->getTamanho().x > this->getTamanho().x && pPlat->getNormal()) {
                    float px = ent->getPosicao().x + (rand() % (int)(ent->getTamanho().x - this->getTamanho().x));
                    float py = ent->getPosicao().y - this->getTamanho().y + 6;
                    setPosicao(Coordenada(px, py));
                    posDefinida = true;
                }
            }
        }
        temp.clear();
    }

    GasToxico::~GasToxico(){

    }
}