#include "../../../../include/Ente/Entidades/Estaticas/Plataforma.h"
namespace Entidades::Obstaculos {
    Plataforma::Plataforma(Coordenada tam, Coordenada pos, ID id):
        Obstaculo(tam, pos, false, false, ID::plataforma) 
        {
        setTexture(TEX_PLATAFORMA, false);
    }

    Plataforma::~Plataforma() { }
}