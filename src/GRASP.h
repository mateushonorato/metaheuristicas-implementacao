#ifndef GRASP_H
#define GRASP_H

#include <float.h>
#include "BuscasLocais.h"
#include "HeuristicasConstrutivas.h"
#include "Instancia.h"
#include "Solucao.h"

Solucao GRASP(Instancia &inst, int GRASPMax, float alpha);

#endif