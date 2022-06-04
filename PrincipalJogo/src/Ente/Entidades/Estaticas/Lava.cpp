#include "../../../../include/Ente/Entidades/Estaticas/Lava.h"

Lava::Lava(Coordenada tam, Coordenada pos, bool lNormal):
    Obstaculo(tam, pos, true, true, ID::lava)
{
    if(lavaNormal)
        setTexture(TEX_LAVA, false);
    else
        setTexture(TEX_LAVA_GELADA,false);
    dano = 0.7f;
}
Lava::~Lava(){

}

void Lava::executar(){

}