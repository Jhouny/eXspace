#include "../../../../include/Ente/Entidades/Estaticas/Lava.h"

Lava::Lava(Coordenada tam, Coordenada pos, bool lNormal):
    Obstaculo(tam, pos, true, true, ID::lava)
{
    if(lNormal == true)
        setTexture(TEX_LAVA, false);
    else if(lNormal == false)
        setTexture(TEX_LAVA_GELADA,false);
    
    dano = 0.4f;
}

Lava::~Lava(){

}

void Lava::executar(){

}