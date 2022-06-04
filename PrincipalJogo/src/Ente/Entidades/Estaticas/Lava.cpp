#include "../../../../include/Ente/Entidades/Estaticas/Lava.h"

Lava::Lava(Coordenada tam, Coordenada pos):
    Obstaculo(tam, pos, true, true, ID::lava)
{
    setTexture(TEX_LAVA, false);
    dano = 0.7f;
}
Lava::~Lava(){

}

void Lava::executar(){

}