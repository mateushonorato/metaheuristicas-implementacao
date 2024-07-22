#ifndef HEURISTICASCONSTRUTIVAS_H
#define HEURISTICASCONSTRUTIVAS_H

#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "Instancia.h"
#include "Solucao.h"

using namespace std;

//retorno o ID do candidato com melhor avaliacao
int melhorCandidato(Instancia& inst, set<int>& C, int idUltimo);
vector<int>::iterator melhorInsercao(Instancia& inst, Solucao& sol, int idInserido);
Solucao VizinhoMaisProximo(Instancia& inst);
Solucao InsercaoMaisBarata(Instancia& inst);

//construção randômica
Solucao Randomica(Instancia& inst);

#endif /*HEURISTICASCONSTRUTIVAS_H*/