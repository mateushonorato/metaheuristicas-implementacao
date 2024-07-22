#include "HeuristicasConstrutivas.h"

int melhorCandidato(Instancia& inst, set<int>& C, int idUltimo)
{
    int idMelhor;
    float custoMelhor = MAXFLOAT;
    set<int>::iterator it;
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
    //impSol(sol);
    it = sol.begin();
    while(it != sol.end())
    {
        id1 = *(it);
        it++;
        //cout << endl << "id1: " << id1 << endl;
        //cout << endl << "it == sol.end(): " << (it == sol.end()) << endl;
        id2 = (it == sol.end()) ? *(sol.begin()) : *(it);
        //cout << "id2: " << id2 << endl;
        custoAtual = inst.distancia[id1][idInserido] + inst.distancia[idInserido][id2] - inst.distancia[id1][id2];
        //cout << "custoAtual: " << custoAtual << endl;
        if( custoAtual < custoMelhor)
        {
            custoMelhor = custoAtual;
            posMelhor = it;
        }
    }
    //cout << "custoMelhor: " << custoMelhor << endl;
    return posMelhor;
}

Solucao VizinhoMaisProximo(Instancia& inst)
{
    Solucao sol;
    //criando minha lista de candidatos
    set<int> C;
    //inicializando minha lista de candidatos
    for(int i = 1; i < inst.n; i++)
    {
        C.insert(i);
    }
    sol.push_back(0); //adicionando a cidade origem do Caixeiro
 
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
    //criando minha lista de candidatos
    unordered_set<int> C;
    //inicializando minha lista de candidatos
    while(C.size() < inst.n){
        C.insert(rand() % inst.n);
    }
    /*for(int i = 1; i < inst.n; i++)
    {
        C.insert(i);
    }*/
    //adicionando a cidade origem do Caixeiro -- TODO mudar para selecionar uma cidade aleatória depois
    sol.push_back(*(C.begin()));
    C.erase(C.begin());
    for(int i = 0; i < 2; i++)
    {
        int id = melhorCandidato(inst, C, sol.at(sol.size()-1));
        sol.push_back(id);
        C.erase(id);
    }
    vector<int>::iterator itMelhorInsercao;
    int idInserir;
    while(!C.empty())
    {
        idInserir = *(C.begin());
        //cout << "idInserir: " << idInserir << endl;
        itMelhorInsercao = melhorInsercao(inst, sol, idInserir);
        //cout << "itMelhorInsercao: " << *itMelhorInsercao << endl;
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
    
    random_shuffle(sol.begin(), sol.end());

    return sol;

}