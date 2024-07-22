#ifndef HEURISTICASCONSTRUTIVAS_H
#define HEURISTICASCONSTRUTIVAS_H

#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#include "Instancia.h"
#include "Solucao.h"

using namespace std;

Solucao VizinhoMaisProximo(Instancia& inst, int k);
Solucao InsercaoMaisBarata(Instancia& inst, int k);
Solucao Randomica(Instancia& inst);

#endif /*HEURISTICASCONSTRUTIVAS_H*/