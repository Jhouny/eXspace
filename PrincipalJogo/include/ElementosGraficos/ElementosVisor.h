#ifndef _ELEMENTOS_VISOR_H_
#define _ELEMENTOS_VISOR_H_

#include "../Ente/Entidades/Dinamicas/Jogador.h"
#include "Coracao.h"
#include "InimigoAbatido.h"

#define PADDING_BORDA 30
#define ESPACAMENTO_PONTOS 5

namespace ElementosGraficos {
    class ElementosVisor {
        private:
            Gerenciadores::Grafico* pGrafico;

            Jogador* pJog1;
            Jogador* pJog2;

            std::vector<Coracao*> vidaJog1;
            std::vector<Coracao*> vidaJog2;
            std::vector<InimigoAbatido*> inimigosAbatidos;
            
        public:
            ElementosVisor(Jogador* jog1, Jogador* jog2 = NULL);
            
            ~ElementosVisor();

            void criaPontosEspacados(int n, PontoID pID); // Cria n pontos de um tipo

            void atualizaPontuacao();

            void resetarVisor();

            void renderizar();

            void executar();


    };    
} // namespace ElementosGraficos 

#endif