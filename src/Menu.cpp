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
    printf("3 - Buscas Locais.\n");
    printf("0 - Sair\n");
    do
    {   
        printf("Digite a opção escolhida: ");
        cin >> op;
    }while( (op < 0) || (op > 3) );
    return op;
}

int menuHeuristicaConstrutiva()
{
    int hc;
    printf("---- Heurísticas Construtivas ---\n");
    printf("Selecione uma opção:\n");
    printf("1 - Vizinho Mais Próximo.\n");
    printf("2 - Inserção Mais Barata.\n");
    printf("3 - Randômico.\n");
    printf("4 - Vizinho Mais Próximo Parcialmente Guloso.\n");
    printf("5 - Inserção Mais Barata Parcialmente Guloso.\n");
    do
    {
        printf("Digite a opção escolhida: ");
        cin >> hc; 
    } while ( (hc < 1) || (hc > 5) );

    return hc;
    
    
}

int menuBuscaLocal()
{
    int bl;
    printf("---- Buscas Locais ---\n");
    printf("Selecione uma opção:\n");
    printf("1 - Descida Troca (BI).\n");
    printf("2 - Descida Troca (FI).\n");
    printf("3 - Descida Realocação (BI).\n");
    printf("4 - Descida Realocação (FI).\n"); 
    printf("5 - Descida Randômica");   
    do
    {
        printf("Digite a opção escolhida: ");
        cin >> bl; 
    } while ( (bl < 1) || (bl > 5) );

    return bl;
    
    
}
