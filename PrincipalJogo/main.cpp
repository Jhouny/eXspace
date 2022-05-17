/*#include "../../include/Auxiliares/Coordenada.h"
#include "../../include/Entidades/Ente.h"

Coordenada X(1,0);
Coordenada Y(0,1);
Coordenada UNIT(1,1);

int main() {
    X.print();
    return 0;
}*/
#include "include/Entidades/Dinamicas/Jogador.h"
#include "include/Entidades/Estaticas/Plataforma.h"

int main()
{
    Clock clock;
    float lastTime = 0;
    
    RenderWindow window(VideoMode(1280, 1080), "Space Game!");
    window.setFramerateLimit(60);
    
    Plataforma base(Coordenada(1000, 50), Coordenada(100, 800));
    base.setWindow(&window);

    Jogador jogador1(Coordenada(100.f, 100.f), Coordenada(100.f, 100.f));
    jogador1.setWindow(&window);
    jogador1.setVelocidade(10, 0.3);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        jogador1.executar();
        jogador1.colisao(static_cast<Entidade *>(&base));
        window.clear();

        jogador1.draw();
        base.draw();

        window.display();
    }

    return 0;
}