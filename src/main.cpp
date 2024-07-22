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

    int op, hc, bl;
    do
    {
        op = menuPrincipal();
        switch (op)
        {
            case 1:
            { 
                leInstancia(inst, nomeArq);
                printf("\n\n Arquivo carregado com sucesso!\n\n");
                /*
                sol.push_back(0);
                sol.push_back(2);
                sol.push_back(1);
                sol.push_back(3);

                float fo = avalia(inst, sol);

                cout<< "Valor da FO: " << fo << endl;
                */
            }    
            break;
            case 2: 
                hc = menuHeuristicaConstrutiva();
                switch (hc)
                {                 
                    case 1:
                        cout<< "  ---- VMP --- " <<endl;
                        sol = VizinhoMaisProximo(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 2:
                        cout << " ---- IMB ---- " <<endl;
                        sol = InsercaoMaisBarata(inst);
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
                        cout<< "  ---- VMP - Parcialmente Guloso --- " <<endl;
                        sol = VizinhoMaisProximoParcialmenteGuloso(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;
                    case 5:
                        cout << " ---- IMB - Parcialmente Guloso ---- " <<endl;
                        sol = InsercaoMaisBarataParcialmenteGuloso(inst);
                        impSol(sol);
                        fo = avalia(inst, sol);
                        printf("\nFO: %.2f\n", fo);
                    break;                
                    default:
                        cout << "Opção inválida" <<endl;
                    break;
                }
            break;
            case 3:
                bl = menuBuscaLocal();
                switch (bl)
                {
                    case 1:
                         cout<<" Busca Local Troca (BI)" <<endl;
                    break;
                
                    default:
                        cout<< "Opção Inválida" << endl;
                    break;
                }    
            break;
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
