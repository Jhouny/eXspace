#include "../../../../include/Ente/Entidades/Estaticas/Rocha.h"
#include "../../../../include/Ente/Entidades/Estaticas/Plataforma.h"

namespace Entidades::Obstaculos{
    Rocha::Rocha(std::list<Entidades::Entidade*> *l):
        Obstaculo(Coordenada(50,40),Coordenada(0,0),false,false,ID::rocha),
        lista(l),
        posDefinida(false)
    {
        // Define a textura a ser usada
        int randTex = (rand()%3) + 1;
        switch(randTex) {
            case 1:
                setTexture(TEX_ROCHA_1);
                break;
            case 2:
                setTexture(TEX_ROCHA_2);
                break;
            case 3:
                setTexture(TEX_ROCHA_3);
                break;
        }

        // Define a posicao da rocha de acordo com as plataformas
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

    Rocha::~Rocha() {}
}
