#ifndef MULTISTART_H
#define MULTISTART_H

#include <float.h>
#include "BuscasLocais.h"
#include "HeuristicasConstrutivas.h"
#include "Instancia.h"
#include "Solucao.h"

Solucao MultiStart(Instancia &inst, int iterMax);

#endif