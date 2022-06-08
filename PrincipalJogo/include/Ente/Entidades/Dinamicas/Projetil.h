#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include"../Entidade.h"
#include"../../../Auxiliares/stdafx.h"

#define TEX_PROJETIL "PrincipalJogo/assets/Texturas/Entidades/Projetil/Projetil.png"

namespace Entidades {
    class Projetil: public Entidade {
        private:
            Coordenada velocidade;  
            int dano;
            Entidade* entOrigem; //para saber de onde/quem foi originado o projetil!!
            std::string textura;

        public:
            Projetil(Coordenada pos, Coordenada tam, float vx = 30, float vy = 0, int d = 5, const char* path = TEX_PROJETIL, ID id = projetil);
            ~Projetil();

            void setVelocidade(float vx, float vy);
            const Coordenada getVelocidade() const { return velocidade; } 
            void setDirecao(){ velocidade.x *= -1;}
            void setEntOrigem(Entidade* ent){ if(ent) entOrigem=ent; }
            Entidade* getOrigem(){ return entOrigem; }

            void setDano(int d);
            const int getDano() const { return dano; }

            void colisao(Entidade* outraEntidade, Coordenada intersecao);

            void estaAtivo();

            void movimentar(const float dt);

            void executar(const float dt);
    };
}
#endif
