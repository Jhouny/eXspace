#ifndef _BOTAO_PATH_H_
#define _BOTAO_PATH_H_

#include "Botao.h"

#define TAMANHO_PADRAO_BOTAO_PATH Coordenada(250, 120)

namespace ElementosGraficos {
    class BotaoPath: public Botao {
        private:
            std::string path;
        public:
            BotaoPath(Coordenada pos);

            ~BotaoPath();

            void setTitulo(std::string cont);

            void setPath(std::string cont);
    };    
}

#endif