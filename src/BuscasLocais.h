#ifndef BUSCASLOCAIS_H
#define BUSCASLOCAIS_H

#include "Avaliador.h"
#include "Instancia.h"
#include "Solucao.h"

float custoMovimentoTroca(Instancia &inst, Solucao &sol, int posI, int posJ);
Solucao BITroca(Instancia &inst, Solucao &sol);
Solucao BITrocaO1(Instancia &inst, Solucao &sol);
Solucao DescidaTrocaBI(Instancia &inst, Solucao &sol);
Solucao DescidaTrocaBIO1(Instancia &inst, Solucao &sol);
void movimentoTroca(Solucao &sol, int posI, int posJ);

#endif