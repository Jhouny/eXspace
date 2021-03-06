#ifndef _ELEMENTOS_VISOR_H_
#define _ELEMENTOS_VISOR_H_

#include "../Ente/Entidades/Dinamicas/Jogador.h"
#include "Coracao.h"
#include "InimigoAbatido.h"

#define PADDING_BORDA 25
#define ESPACAMENTO_PONTOS 6

namespace ElementosGraficos {
    class ElementosVisor {
        private:
            Gerenciadores::Grafico* pGrafico;

            Entidades::Personagens::Jogador* pJog1;
            Entidades::Personagens::Jogador* pJog2;

            Coracao* pCor;
            InimigoAbatido* pIni;

            bool multiplayer;

            std::vector<Coracao*> vidaJog1;
            std::vector<Coracao*> vidaJog2;
            std::vector<InimigoAbatido*> inimigosAbatidos;
            
        public:
            ElementosVisor(Entidades::Personagens::Jogador* jog1, Entidades::Personagens::Jogador* jog2 = NULL);
            
            ~ElementosVisor();

            void setMultiplayer(bool multi) { multiplayer = multi; }

            void criaPontosEspacados(int n, PontoID pID); // Cria n pontos de um tipo

            void atualizaPontuacao(int numIni);

            void resetarVisor();

            void renderizar();

            void executar();


    };    
} // namespace ElementosGraficos 

#endif