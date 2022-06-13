#include "../../../../include/Ente/Entidades/Estaticas/Plataforma.h"
namespace Entidades::Obstaculos {
    Plataforma::Plataforma(Coordenada tam, Coordenada pos,bool platNormal, ID id):
        Obstaculo(tam, pos, false, false, ID::plataforma),
        platafNormal(platNormal)
    {
        setTexture(TEX_PLATAFORMA, false);
    }

    Plataforma::~Plataforma() { }
}