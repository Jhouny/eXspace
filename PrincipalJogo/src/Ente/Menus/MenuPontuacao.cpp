#include "../../../include/Ente/Menus/MenuPontuacao.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{
    MenuPontuacao::MenuPontuacao():
        Menu()
    {
        /*setTitulo("PONTUAÇÃO");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        */
        executar(0);
    }

    MenuPontuacao::~MenuPontuacao() {}

    void MenuPontuacao::criaBotoes(){
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(1030.f,570.f),"VOLTAR"); //VOLTA PARA O MENU
        pBotao->ativar();
        botoesAtivos.insert(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));        
    }

    void MenuPontuacao::incluir(ElementosGraficos::Texto *texto){
        if(texto)
            lTextos.push(texto);
        else
            cout << "Ponteiro para texto esta nulo" << endl;

    }

    void MenuPontuacao::criaTextos(){
        pTexto = new ElementosGraficos::Texto(Coordenada(400,100),Coordenada(100,50),"Posicao:");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,100),Coordenada((float)COMPRIMENTO/2.f,50),"Nome:");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,100),Coordenada(900,50),"Pontuação:");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);
    }

    void MenuPontuacao::atualizar(const float dt){
         for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }

    void MenuPontuacao::renderizar(){
        int i;
        for(i = 0; i < lTextos.getTamanho(); i++ ){
            pGrafico->draw(lTextos[i]->getTexto());
        }
         for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
    }

    void MenuPontuacao::executar(const float dt){
        criaBotoes();
        criaTextos();
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }
}