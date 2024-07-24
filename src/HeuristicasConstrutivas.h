#ifndef HEURISTICASCONSTRUTIVAS_H
#define HEURISTICASCONSTRUTIVAS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <unordered_set>
#include <vector>
#include "Instancia.h"
#include "Solucao.h"

using namespace std;

Solucao InsercaoMaisBarata(Instancia &inst, int k);
Solucao Randomica(Instancia &inst);
Solucao VizinhoMaisProximo(Instancia &inst, int k);
Solucao VMP_GRASP(Instancia &inst, float alpha);

#endif