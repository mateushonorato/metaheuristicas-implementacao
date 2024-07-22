/*
    Disciplina BCC466 - Técnicas Metaheurísticas para Otimização Combinatória
    Prof. Pablo Munhoz
    DECOM/UFOP
*/
#include "Menu.h"

int menuPrincipal()
{
    int op;
    printf("=====================================\n");
    printf("===   BCC466 - Metaheurísticas    ===\n");
    printf("=== Problema do Caixeiro Viajante ===\n");
    printf("=====================================\n");
    printf("Selecione uma opção: \n");
    printf("1 - Carregar instância. \n");
    printf("2 - Heurísticas Construtivas.\n");
    printf("0 - Sair\n");
    do
    {   
        printf("Digite a opção escolhida: ");
        cin >> op;
    }while( (op < 0) || (op > 2) );
    return op;
}

int menuHeuristicaConstrutiva()
{
    int hc;
    printf("---- Heurísticas Construtivas ---\n");
    printf("Selecione uma opção:\n");
    printf("1 - Vizinho Mais Próximo.\n");
    printf("2 - Inserção Mais Barata.\n");
    do
    {
        printf("Digite a opção escolhida: ");
        cin >> hc; 
    } while ( (hc < 1) || (hc > 2) );

    return hc;
    
    
}