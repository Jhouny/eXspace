#include "../../../include/Ente/Menus/MenuPontuacao.h"
#include "../../../include/ElementosGraficos/Texto.h"

namespace Menus{
    MenuPontuacao::MenuPontuacao():
        Menu(),
        pControleMenu(this)
    {
        setID(Estados::IdEstado::pontuacao);
        /*
        setTitulo("PONTUAÇÃO");
        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 100.f));
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);*/
        
        executar(0);
    }

    MenuPontuacao::~MenuPontuacao() {}

    void MenuPontuacao::criaBotoes(){
        botoesAtivos.clear();
        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(1100.f, 650.f),Estados::IdEstado::menuAbertura,"VOLTAR"); //VOLTA PARA O MENU
        pBotao->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, true));        
    }

    void MenuPontuacao::incluir(ElementosGraficos::Texto *texto){
        if(texto)
            lTextos.push_back(texto);
        else
            cout << "Ponteiro para texto esta nulo" << endl;

    }

    void MenuPontuacao::criaTextos() {
        lTextos.clear();

        pTexto = new ElementosGraficos::Texto(Coordenada(400,250),Coordenada((float)COMPRIMENTO/2.f,50),"Pontuação: ");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,150),"1º");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,250),"2º");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,350),"3º");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,450),"4º");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);

        pTexto = new ElementosGraficos::Texto(Coordenada(400,150),Coordenada(COMPRIMENTO/7.f,550),"5º");
        pTexto->setCor(sf::Color::Yellow);
        getTitulo()->setContorno(sf::Color(200, 50, 50, 230), 5);
        incluir(pTexto);
    }

    void MenuPontuacao::atualizar(const float dt){
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }
    }

    void MenuPontuacao::ativarControle() {
        pControleMenu.ativar();
    }

    void MenuPontuacao::desativarControle() {
        pControleMenu.desativar();
    }

    void MenuPontuacao::renderizar(){
        pGrafico->draw(&fundo, false);
        int i;
        for(i = 0; i < lTextos.size(); i++ ){
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