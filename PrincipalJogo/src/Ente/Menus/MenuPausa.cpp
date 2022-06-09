#include"../../../include/Ente/Menus/MenuPausa.h"
#include "../../../include/Estados/MaquinaEstados.h"

namespace Menus {
    MenuPausa::MenuPausa():
        Menu(),
        pControleTexto(this),
        pControleMenu(this),
        pathSalvar(""),
        faseID(Estados::IdEstado::indefinido),
        pListaEntidades(NULL)
    {
        setID(Estados::IdEstado::menuPausa);
        setTitulo("PAUSE");
        setTexture(TEX_FUNDO_PAUSA);

        getTitulo()->setPosicao(Coordenada(COMPRIMENTO/2.f - getTitulo()->getTexto()->getLocalBounds().width/2.f, 50.f));
        getTitulo()->setCor(sf::Color(0,0,0,230));
        getTitulo()->setContorno(sf::Color::Yellow, 5);

        executar(0);
    }

    MenuPausa::~MenuPausa() {
        pFase = NULL;
        pTextoArq = NULL;
    }

    void MenuPausa::criaBotoes() {
        botoesAtivos.clear();
        // Botão voltar para o jogo
        pBotaoVoltar = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO - 300.f, ALTURA/2.f - 50.f), Estados::IdEstado::indefinido, "VOLTAR");
        pBotaoVoltar->ativar();
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotaoVoltar, false));
        
        // Botão salvar
        pBotaoSalvar = new ElementosGraficos::Botao(Coordenada(200, 100), Coordenada(COMPRIMENTO - 300.f, ALTURA/2.f + 100.f), Estados::IdEstado::salvarJogo, "SALVAR");
        botoesAtivos.emplace_back(std::pair<ElementosGraficos::Botao*, bool>(pBotaoSalvar, false));
    }

    void MenuPausa::criaTextos() {
        lTextos.clear();
        pTextoArq = new ElementosGraficos::Texto(Coordenada(400, 150), Coordenada(COMPRIMENTO/8.f, ALTURA/2.f + 100.f), "", false);
        pTextoArq->setCor(sf::Color(0,0,0,230));
        pTextoArq->setContorno(sf::Color::Yellow, 1);
        lTextos.emplace_back(pTextoArq);
    }

    void MenuPausa::resumirJogo() {
        pMaq->setEstadoAtual(faseID, pListaEntidades);
    }

    void MenuPausa::ativarControle() {
        pControleMenu.ativar();
        pControleTexto.ativar();
    }
    
    void MenuPausa::desativarControle() {
        pControleMenu.desativar();
        pControleTexto.desativar();
    }

    void MenuPausa::salvaEstado() {
        if(pathSalvar != "" && pListaEntidades != NULL) {
            pathSalvar = SALVAR_JOGO_PATH + pathSalvar + ".txt";  // define o path padrão, o nome (dado pelo usuário) e a extensão do arquivo
            ofstream saida;
            saida.open(pathSalvar, ios::out);
            if(!saida)
                cout << "Erro ao abrir arquivo..." << endl;
            else {
                std::list<Entidades::Entidade*>::iterator it2;
                for(it2 = pListaEntidades->begin(); it2 != pListaEntidades->end(); it2++) {
                    Entidades::Entidade* ent = *it2;
                    // Ordem: ID, Posicao.x, Posicao.y
                    saida << ent->getID() << ";" << ent->getPosicao().x  << ";" << ent->getPosicao().y << ";" << endl;
                }
                saida.close();
            }
        }
    }

    void MenuPausa::atualizar(const float dt) {
        //atualiza os botoes e suas respectivas texturas
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            (it->first)->executar();
        }

        //atualiza os texto que podem ser modificados
        for(int i = 0; i < lTextos.size(); i++ ){
            if(!(lTextos[i]->getEstatico())) {
                lTextos[i]->setTexto(pControleTexto.getNome());
                pathSalvar = pControleTexto.getNomeString();
            }
        }
    }

    void MenuPausa::renderizar() {
        pGrafico->draw(&fundo, false);
        
        int i;
        //desenha Textos na tela
        for(i = 0; i < lTextos.size(); i++ ){
            pGrafico->draw(lTextos[i]->getTexto());
        }

        //desenha os botoes na tela
        for(it = botoesAtivos.begin(); it != botoesAtivos.end(); it++){
            pGrafico->draw((it->first)->getSprite(),false);
            pGrafico->draw((it->first)->getTexto());
        }
        pGrafico->draw(titulo.getTexto());    
    }

    void MenuPausa::executar(const float dt) {
        criaBotoes();
        criaTextos();

        pathSalvar = "";
        pControleTexto.apagaNome();

        pGrafico->setTamView(Coordenada(COMPRIMENTO, ALTURA));
        pGrafico->atualizaView(Coordenada(COMPRIMENTO/2.f, ALTURA/2.f));
    }
}