#include "HeuristicasConstrutivas.h"

random_device rd;
mt19937 mt(rd());

unordered_set<int> obterListaCandidatos(int n)
{
    unordered_set<int> C;

    for (int i = 0; i < n; i++)
    {
        C.insert(i);
    }

    return C;
}

unordered_set<int> obterListaCandidatosAleatoria(long unsigned int n)
{
    unordered_set<int> C;

    while (C.size() < n)
    {
        C.insert(mt() % n);
    }

    return C;
}

int melhorCandidato(Instancia &inst, unordered_set<int> &C, int idUltimo, long unsigned int k)
{
    multimap<float, int> melhoresCustos;

    for (auto it = C.begin(); it != C.end(); it++)
    {
        melhoresCustos.insert(pair<float, int>(inst.distancia[idUltimo][*it], *it));
        if (melhoresCustos.size() > (k + 1))
        {
            melhoresCustos.erase(melhoresCustos.end()->first);
        }
    }
    auto it = melhoresCustos.begin();
    if (k > 0 && k < melhoresCustos.size())
    {
        advance(it, mt() % k);
    }
    pair<float, int> melhorCusto = *it;
    return melhorCusto.second;
}

vector<int>::iterator melhorInsercao(Instancia &inst, Solucao &sol, int idInserido, long unsigned int k)
{
    int id1, id2;
    float custoAtual;
    multimap<float, vector<int>::iterator> melhoresCustos;
    vector<int>::iterator it = sol.begin();

    while (it != sol.end())
    {
        id1 = *(it);
        it++;
        id2 = (it == sol.end()) ? *(sol.begin()) : *(it);
        custoAtual = inst.distancia[id1][idInserido] + inst.distancia[idInserido][id2] - inst.distancia[id1][id2];
        melhoresCustos.insert(pair<float, vector<int>::iterator>(custoAtual, it));
        if (melhoresCustos.size() > (k + 1))
        {
            melhoresCustos.erase(melhoresCustos.end()->first);
        }
    }
    auto posMelhor = melhoresCustos.begin();
    if (k > 0 && k < melhoresCustos.size())
    {
        advance(posMelhor, mt() % k);
    }
    pair<float, vector<int>::iterator> melhorCusto = *posMelhor;
    return melhorCusto.second;
}

Solucao VizinhoMaisProximo(Instancia &inst, int k)
{
    Solucao sol;

    // criando e inicializando minha lista de candidatos
    unordered_set<int> C = obterListaCandidatos(inst.n);

    // adicionando a cidade origem do Caixeiro
    sol.push_back(*(C.begin()));
    C.erase(C.begin());

    // seleciona e insere o vizinho mais próximo até que a lista de candidatos termine
    while (!C.empty())
    {
        int id = melhorCandidato(inst, C, sol.at(sol.size() - 1), k);
        sol.push_back(id);
        C.erase(id);
    }

    return sol;
}

Solucao InsercaoMaisBarata(Instancia &inst, int k)
{
    Solucao sol;
    vector<int>::iterator itMelhorInsercao;
    int idInserir;

    // criando e inicializando minha lista de candidatos
    unordered_set<int> C = obterListaCandidatos(inst.n);

    // adicionando a cidade origem do Caixeiro
    sol.push_back(*(C.begin()));
    C.erase(C.begin());

    // criando rota inicial utilizando o método de inserção mais barata
    int id = melhorCandidato(inst, C, sol.at(sol.size() - 1), k);
    sol.push_back(id);
    C.erase(id);

    // verifica e realiza a inserção mais barata até que a lista de candidatos termine
    while (!C.empty())
    {
        idInserir = *(C.begin());
        itMelhorInsercao = melhorInsercao(inst, sol, idInserir, k);
        sol.insert(itMelhorInsercao, idInserir);
        C.erase(idInserir);
    }

    return sol;
}

Solucao Randomica(Instancia &inst)
{
    Solucao sol;

    for (int i = 0; i < inst.n; i++)
    {
        sol.push_back(i);
    }

    shuffle(sol.begin(), sol.end(), mt);

    return sol;
}