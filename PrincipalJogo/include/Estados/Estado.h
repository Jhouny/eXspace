#ifndef _ESTADO_H_
#define _ESTADO_H_

#include "../Auxiliares/stdafx.h"
#include "../Ente/Menus/Menu.h"

namespace Estados {
    enum IdEstado {
        indefinido = -1,
        menuAberto,
        pontuacao
    };

    class Estado {
        private:
            Estado* anterior;  // Define o menu anterior para poder retornar
            IdEstado id;
            Menus::Menu* menu;
        public:
            Estado(IdEstado id = indefinido);

            ~Estado();

            IdEstado getID() const { return id; }

            Estado* getAnterior() { return anterior; }
            void setAnterior(Estado* est) { anterior = est; }

            virtual void atualizar(const float dt) = 0;

            virtual void renderizar() = 0;

            virtual void executar() = 0;
    };    
} // namespace Estados


#endif