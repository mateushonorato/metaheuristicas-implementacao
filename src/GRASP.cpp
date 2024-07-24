
#include "GRASP.h"

Solucao GRASP(Instancia &inst, int GraspMax, float alpha)
{
    float melhorFO = MAXFLOAT, fo;
    Solucao melhorSol;

    for(int inter = 0; inter < GraspMax; inter++)
    {
        // constroi solucao
        Solucao sol; // VMP_GRASP
        // aplica busca local
        sol = DescidaTrocaBIO1(inst, sol);
        fo = avalia(inst, sol);
    }

    return melhorSol;
}