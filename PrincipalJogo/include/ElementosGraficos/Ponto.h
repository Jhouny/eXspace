#ifndef _PONTO_H_
#define _PONTO_H_

#define TEX_PONTO_PREENCHIDO ""
#define TEX_PONTO_VAZIO ""

namespace ElementosGraficos {
    class Ponto {
        private:
            bool preenchido;
        public:
            Ponto();

            ~Ponto();

            void preenchido();

            void vazio();

            void atualizarTextura();

            void executar();
        };    
} // namespace ElementosGraficos 

#endif