#include "../../../../include/Ente/Entidades/Estaticas/gasToxico.h"
namespace Entidades::Obstaculos {
    GasToxico::GasToxico(Coordenada tam, Coordenada pos):
        Obstaculo(tam, pos, true, true, ID::gasToxico)
    {
        setTexture(TEX_GAS, false);

    }

    GasToxico::~GasToxico(){

    }


    void GasToxico::executar(){

    }
}