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

Solucao VizinhoMaisProximo(Instancia& inst);
Solucao InsercaoMaisBarata(Instancia& inst);
Solucao Randomica(Instancia& inst);

#endif /*HEURISTICASCONSTRUTIVAS_H*/