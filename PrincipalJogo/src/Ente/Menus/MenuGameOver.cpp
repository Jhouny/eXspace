#include"../../../include/Ente/Menus/MenuGameOver.h"

#include"../../../include/Controle/ControleTexto.h"

#include"../../../include/Estados/MaquinaEstados.h"


namespace Menus{
    MenuGameOver::MenuGameOver():
        Menu(),
        pControleTexto(static_cast<Menu*>(this)),
        pControleMenu(this),
        nome(""),
        pontuacao(0)
    {
        setID(Estados::IdEstado::menuGameOver);
        setTitulo("GAME OVER");

        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 50.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow ,5);

        executar(0);
    }

    MenuGameOver::~MenuGameOver() {}

    void MenuGameOver::criaBotoes(){
        botoesAtivos.clear();
        pBotaoSalvar = new ElementosGraficos::BotaoSalvar(Coordenada(200, 100), Coordenada(COMPRIMENTO - 300.f, ALTURA/2.f - 0.f), this, "SALVAR");
        pBotaoSalvar->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotaoSalvar, true));

        pBotao = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO - 300.f, ALTURA/2.f + 200.f), Estados::IdEstado::menuAbertura, "VOLTAR");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotao, false));
    }

    void MenuGameOver::criaTextos() {
        vTextos.clear();
        pTexto = new ElementosGraficos::Texto(Coordenada(400, 150),Coordenada(COMPRIMENTO/8.f, ALTURA/2.f + 200),"Digite seu nome:");
        pTexto->setCor(sf::Color(0,0,0,230));
        pTexto->setContorno(sf::Color::Yellow, 5);
        incluir(pTexto);

        pTextoNome = new ElementosGraficos::Texto(Coordenada(400, 150), Coordenada(COMPRIMENTO/8.f + 200.f, ALTURA/2.f + 180),"", false);
        pTextoNome->setCor(sf::Color(0,0,0,230));
        pTextoNome->setContorno(sf::Color::Yellow, 2);
        incluir(pTextoNome);

        pTexto = new ElementosGraficos::Texto(Coordenada(400, 150),Coordenada(COMPRIMENTO/8.f, ALTURA/2.f),"Pontos: ");
        pTexto->setCor(sf::Color(0,0,0,230));
        pTexto->setContorno(sf::Color::Yellow, 5);
        incluir(pTexto);
        
        pTextoPontuacao = new ElementosGraficos::Texto(Coordenada(400,150), Coordenada(COMPRIMENTO/8.f + 100, ALTURA/2.f - 20),"");
        pTextoPontuacao->setCor(sf::Color(0,0,0,230));
        pTextoPontuacao->setContorno(sf::Color::Yellow, 5);
        incluir(pTextoPontuacao);

    }

    void MenuGameOver::setPontuacao(int pont){
        pontuacao = pont;
        pTextoPontuacao->setConteudo(std::to_string(pontuacao));  
    }

    void MenuGameOver::incluir(ElementosGraficos::Texto *texto){
        if(texto)
            vTextos.emplace_back(texto);
        else
            cout << "Ponteiro para texto nulo"<< endl;
    }

    void MenuGameOver::renderizar(){
        pGrafico->draw(&fundo, false);
        int i;
        //desenha Textos na tela
        for(i = 0; i < vTextos.size(); i++ ){
            pGrafico->draw(vTextos[i]->getTexto());
        }
        //desenha os botoes na tela
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());     

    }

    void MenuGameOver::atualizar(const float dt){
        //atualiza os botoes e suas respectivas texturas
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }

        //atualiza os texto que podem ser modificados
        for(int i = 0; i < vTextos.size(); i++ ){
            if(!(vTextos[i]->getEstatico())) {
                vTextos[i]->setTexto(pControleTexto.getNome());
                nome = pControleTexto.getNomeString();
            }
        }

    }
    void MenuGameOver::ativarControle(){
        pControleMenu.ativar();
        pControleTexto.ativar();

    }

    void MenuGameOver::desativarControle(){
        pControleMenu.desativar();
        pControleTexto.desativar();
    }

    void MenuGameOver::leArquivoPontuacao(){
        mapaPontuacao.clear();
        std::ifstream recuperaPontuacao(PONTUACAO_PATH,ios::in);
        if(!recuperaPontuacao){
            cerr << "Arquivo não pode ser aberto"<< endl;
            return;
        }
        while(!recuperaPontuacao.eof()){
            std::string pontu;
            std::string name;
            for(int i = 0; i < 10; i++){
                std::getline(recuperaPontuacao,pontu);
                std::getline(recuperaPontuacao,name);
                if(pontu.length()>0){
                    mapaPontuacao.insert(std::pair<int ,std::string >(std::stoi(pontu),name));        
                }
            }
        }
    }

    void MenuGameOver::executar(const float dt){
        criaBotoes();
        criaTextos();
        leArquivoPontuacao();
        
        // Reseta o conteúdo dos textos
        pTextoPontuacao->setConteudo(std::to_string(pontuacao));  
        pTextoNome->setConteudo("");
        nome = "";
        pControleTexto.apagaNome();
        
        setFundoAleatorio();
        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }


}