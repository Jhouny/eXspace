#include "../../../../include/Ente/Entidades/Estaticas/Rocha.h"
namespace Entidades::Obstaculos{
    Rocha::Rocha(Coordenada pos):
        Obstaculo(Coordenada(50,50),pos,false,false,ID::rocha)
    {
        this->setTexture(TEX_ROCHA);
    }
    Rocha::~Rocha(){}

    Rocha::void executar(){}

}
