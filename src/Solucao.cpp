#include "Solucao.h"

void impSol(Solucao &sol)
{
    cout << "[ ";
    for (long unsigned int i = 0; i < sol.size(); i++)
    {
        cout << sol.at(i) << " , ";
    }
    cout << sol.at(0) << " ]";
}