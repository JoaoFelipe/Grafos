#include <stdio.h>
#include <stdlib.h>

typedef struct graf {
    int nodes;
    int* matriz;
    int inicial;
} Grafo;

void alocar(Grafo *grafo) 
{
    int i,j;
    int n = grafo->nodes;
    grafo->matriz = (int*) calloc(n*n, sizeof(int));
    grafo->inicial = -1;
}    

void liberar(Grafo *grafo) 
{
    free(grafo->matriz);   
}

void edge(Grafo *grafo, int node1, int node2) 
{
    if (grafo->inicial == -1) {
        grafo->inicial = node1;
    }
    grafo->matriz[node1*grafo->nodes + node2] = 1;
    grafo->matriz[node2*grafo->nodes + node1] = 1;
}

int bicoloring(Grafo grafo)
{
    int* nodes;
    int atual;
    int retorno;
    nodes = (int*) calloc(grafo.nodes, sizeof(int));
    atual = grafo.inicial;
    atual = (atual == -1)? 0 : atual; 
    retorno = pintar(nodes, grafo, atual, 1);
    free(nodes);
    return retorno;
}

int pintar(int* nodes, Grafo grafo, int atual, int cor) 
{
    int i;
    if (nodes[atual] == 0) {
        nodes[atual] = cor;
        for (i = atual*grafo.nodes + 1; i < (atual+1)*grafo.nodes; i++) {
            if(grafo.matriz[i] && !pintar(nodes, grafo, i % grafo.nodes, (cor == 1)? 2 : 1)) {
                return 0;
            }
        }
    } else if (nodes[atual] != cor) {
        return 0;
    }
    return 1;    
}

#ifndef TESTE
main()
{
    int nodes, edges;
    int i, n1, n2;
    int s;
    Grafo grafo;
    while (1) {
        s = scanf("%d", &nodes);
        if (nodes == 0) {
            break;
        }
        s = scanf("\n%d", &edges);
        grafo.nodes = nodes;
        alocar(&grafo);
        for (i = 0; i < edges; i++) {
            s = scanf("\n%d %d", &n1, &n2);
            edge(&grafo, n1, n2);
        }    
        if (bicoloring(grafo)) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }
        liberar(&grafo);
    } 
    return 0;
}
#endif