#include "../../../../include/Ente/Entidades/Estaticas/Plataforma.h"

Plataforma::Plataforma(Coordenada tam, Coordenada pos, ID id):
    Obstaculo(tam, pos, false, false, ID::plataforma) 
    {
    setTexture(TEX_PLATAFORMA, false);
}

Plataforma::~Plataforma() { }

void Plataforma::executar() { }