#include "HeuristicasConstrutivas.h"

unordered_set<int> obterListaCandidatosAleatoria(int n){
    unordered_set<int> C;
    while(C.size() < n){
        C.insert(rand() % n);
    }
    return C;
}

int melhorCandidato(Instancia& inst, unordered_set<int>& C, int idUltimo)
{
    int idMelhor;
    float custoMelhor = MAXFLOAT;
    unordered_set<int>::iterator it;
    for(it = C.begin(); it != C.end(); it++)
    {
        if( inst.distancia[idUltimo][*(it)] < custoMelhor)
        {
            custoMelhor = inst.distancia[idUltimo][*(it)];
            idMelhor = *it;
        }
    }

    return idMelhor;
}

vector<int>::iterator melhorInsercao(Instancia& inst, Solucao& sol, int idInserido)
{
    int id1;
    int id2;
    float custoMelhor = MAXFLOAT;
    float custoAtual;
    vector<int>::iterator it;
    vector<int>::iterator posMelhor = sol.begin();
    it = sol.begin();
    while(it != sol.end())
    {
        id1 = *(it);
        it++;
        id2 = (it == sol.end()) ? *(sol.begin()) : *(it);
        custoAtual = inst.distancia[id1][idInserido] + inst.distancia[idInserido][id2] - inst.distancia[id1][id2];
        if( custoAtual < custoMelhor)
        {
            custoMelhor = custoAtual;
            posMelhor = it;
        }
    }
    return posMelhor;
}

Solucao VizinhoMaisProximo(Instancia& inst)
{
    Solucao sol;

    //criando e inicializando minha lista de candidatos
    unordered_set<int> C = obterListaCandidatosAleatoria(inst.n);

    //adicionando a cidade origem do Caixeiro
    sol.push_back(*(C.begin()));
    C.erase(C.begin());
 
    //seleciona e insere o vizinho mais próximo até que a lista de candidatos termine
    while(! C.empty())
    {
        int id = melhorCandidato(inst, C, sol.at(sol.size()-1));
        sol.push_back(id);
        C.erase(id);
    }
 
    return sol;
}

Solucao InsercaoMaisBarata(Instancia& inst)
{
    Solucao sol;
    vector<int>::iterator itMelhorInsercao;
    int idInserir;

    //criando e inicializando minha lista de candidatos
    unordered_set<int> C = obterListaCandidatosAleatoria(inst.n);
    //adicionando a cidade origem do Caixeiro
    sol.push_back(*(C.begin()));
    C.erase(C.begin());
    //criando rota inicial utilizando o método de inserção mais barata
    int id = melhorCandidato(inst, C, sol.at(sol.size()-1));
    sol.push_back(id);
    C.erase(id);
    
    //verifica e realiza a inserção mais barata até que a lista de candidatos termine
    while(!C.empty())
    {
        idInserir = *(C.begin());
        itMelhorInsercao = melhorInsercao(inst, sol, idInserir);
        sol.insert(itMelhorInsercao, idInserir);
        C.erase(idInserir);
    }

    return sol;
}

Solucao Randomica(Instancia& inst)
{
    Solucao sol;

    for(int i = 0; i < inst.n; i++)
    {
        sol.push_back(i);
    }
    
    random_device rd;
    mt19937 g(rd());
 
    shuffle(sol.begin(), sol.end(),g);

    return sol;

}