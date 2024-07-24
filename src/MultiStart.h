#ifndef MULTISTART_H
#define MULTISTART_H

#include "Solucao.h"
#include "Instancia.h"
#include "HeuristicasConstrutivas.h"
#include "BuscasLocais.h"

Solucao MultiStart(Instancia& inst, int interMax);

#endif