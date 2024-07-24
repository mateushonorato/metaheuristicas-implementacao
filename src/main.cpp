#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "Instancia.h"
#include "Solucao.h"
#include "Avaliador.h"
#include "Menu.h"
#include "HeuristicasConstrutivas.h"
#include "BuscasLocais.h"

using namespace std;

int main(int argc, char* argv[])
{
    Instancia inst;
    Solucao sol;
    float fo; 
    string nomeArq = argv[1];
    leInstancia(inst, nomeArq);

    int op, hc, bl, k;
    do
    {
        op = menuPrincipal();
        switch (op)
        {
            case 1:
            {
                hc = menuHeuristicaConstrutiva();
                switch (hc)
                {                 
                    case 1:
                        cout<< "  ---- VMP --- " <<endl;
                        sol = VizinhoMaisProximo(inst, 0);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 2:
                        cout << " ---- IMB ---- " <<endl;
                        sol = InsercaoMaisBarata(inst, 0);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 3:
                        cout << " ---- Randômico ---- " <<endl;
                        sol = Randomica(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 4:
                        cout << "  ---- VMP - Parcialmente Guloso --- " << endl;
                        cout << "Insira o fator k: ";
                        cin >> k;
                        sol = VizinhoMaisProximo(inst, k);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 5:
                        cout << " ---- IMB - Parcialmente Guloso ---- " << endl;
                        cout << "Insira o fator k: ";
                        cin >> k;
                        sol = InsercaoMaisBarata(inst, k);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;                
                    default:
                        cout << "Opção inválida" <<endl;
                    break;
                }
                break;
            }
            case 2:
            {
                bl = menuBuscaLocal();
                switch (bl)
                {
                    case 1:
                         cout<<" ### Busca Local Troca (BI) ### " <<endl;
                         sol = DescidaTrocaBI(inst, sol);
                         impSol(sol);
                         fo = avalia(inst, sol);
                         printf("\nFO: %.2f\n", fo);
                    break;
                    case 2:
                         cout<<" ### Busca Local Troca (BI - O(1)) ### " <<endl;
                         sol = DescidaTrocaBIO1(inst, sol);
                         impSol(sol);
                         fo = avalia(inst, sol);
                         printf("\nFO: %.2f\n", fo);
                    break;
                
                    default:
                        cout<< "Opção Inválida" << endl;
                    break;
                }    
                break;
            }
            case 0:
                cout << "Até a próxima!!!" << endl;
            break;
            default:
                printf("Algo deu errado!\n");
            break;
        }
    }while(op != 0);

    return 0; 
}
