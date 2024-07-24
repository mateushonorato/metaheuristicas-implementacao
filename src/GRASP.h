#ifndef GRASP_H
#define GRASP_H

#include "Instancia.h"
#include "HeuristicasConstrutivas.h"
#include "Solucao.h"
#include "BuscasLocais.h"

Solucao GRASP(Instancia &inst, int GraspMax, float alpha);

#endif