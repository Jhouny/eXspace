#include "../../../../include/Ente/Entidades/Estaticas/Obstaculo.h"

namespace Entidades::Obstaculos {
    Obstaculo::Obstaculo(Coordenada tam, Coordenada pos, bool dano, bool ultra, ID id):
        Entidade(id, tam, pos,true),
        daDano(dano),
        ultrapassavel(ultra) {

    }

    Obstaculo::~Obstaculo() { }
}