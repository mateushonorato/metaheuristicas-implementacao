#include "MultiStart.h"

Solucao MultiStart(Instancia& inst, int interMax){
    // faça interMax interações sem melhora
    // construa uma solução
    // faça uma busca local
    // se é melhor que a melhor solução atual, atualiza. senão re...
    int inter = 0;
    Solucao melhorSol;
    float melhorFO = MAXFLOAT, fo;
    while(inter < interMax){
        // gera solução randomica
        Solucao sol = Randomica(inst);

        sol = DescidaTrocaBIO1(inst, sol);
        fo = avalia(inst, sol);
        if(fo < melhorFO){
            melhorSol = sol;
            melhorFO = fo;
            inter = 1;
        }
        else {
            inter++;
        }
    }
    return melhorSol;
}