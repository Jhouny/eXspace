#include "../../../include/Entidades/Estaticas/Obstaculo.h"

Obstaculo::Obstaculo(Coordenada tam, Coordenada pos, bool dano, bool ultra, ID id):
    Entidade(id, tam, pos),
    daDano(dano),
    ultrapassavel(ultra) {

}

Obstaculo::~Obstaculo() { }