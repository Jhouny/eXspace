#include "../../include/ElementosGraficos/BotaoAlternador.h"
#include "../../include/Estados/MaquinaEstados.h"
#include "../../include/Ente/Menus/Fases/Fase.h"


namespace ElementosGraficos {
    BotaoAlternador::BotaoAlternador(Coordenada tam, Coordenada pos):
        Botao(tam, pos, Estados::IdEstado::alternar),
        escolha(),
        indice(0)
    {
        atualizarTextura();
    }

    BotaoAlternador::~BotaoAlternador() {
        escolha.clear();
    }

    void BotaoAlternador::setAtivo(int ind) {
        texto = escolha[ind].first;
        indice = ind;
    }

    void BotaoAlternador::inserirEscolha(std::string conteudo, int num) {
        Texto* temp = new Texto(getTamanho(), Coordenada(getPosicao().x + getTamanho().x/2.f, getPosicao().y + getTamanho().y/2.f), conteudo);
        escolha.emplace_back(std::pair<Texto*, int>(temp, num));
    }

    void BotaoAlternador::proximo() {
        indice++;
        if(indice >= escolha.size())
            indice = 0;
        texto = escolha[indice].first;

        if(alvo != NULL && operacao == 0) {
            Estados::IdEstado n = static_cast<Estados::IdEstado>(escolha[indice].second);
            alvo->setFuncao(n);
        } else if(alvo != NULL && pMaq != NULL && operacao == 1) {
            std::map<Estados::IdEstado, Estados::Estado*> *temp = pMaq->getMapaEstados();
            std::map<Estados::IdEstado, Estados::Estado*>::iterator it3;
            for(it3 = temp->begin(); it3 != temp->end() && (it3->second)->getID() != alvo->getFuncao(); it3++);
            Menus::Fases::Fase* fase = dynamic_cast<Menus::Fases::Fase*>((it3->second));
            if(fase != NULL) {
                fase->setMultiplayer(escolha[indice].second);
            }
        }
    }

    void BotaoAlternador::anterior() {
        indice--;
        if(indice < 0)
            indice = escolha.size();
        texto = escolha[indice].first;
        
        if(alvo != NULL && operacao == 0) {
            Estados::IdEstado n = static_cast<Estados::IdEstado>(escolha[indice].second);
            alvo->setFuncao(n);
        } else if(alvo != NULL && pMaq != NULL && operacao == 1) {
            std::map<Estados::IdEstado, Estados::Estado*> *temp = pMaq->getMapaEstados();
            std::map<Estados::IdEstado, Estados::Estado*>::iterator it3;
        }
    }

    void BotaoAlternador::atualizarTextura() {
        if(ativo)
            setTexture(TEX_BOTAO_ALTERNADOR_ATIVO);
        else
            setTexture(TEX_BOTAO_ALTERNADOR_NEUTRO);
    }

} // namespace ElementosGraficos 