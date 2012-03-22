#define TESTE

#include "simplectest/tests.h"
#include "bicoloring.c"

START_TESTS()

START_TEST("Testar Bicoloring")
    Grafo grafo;
    TEST("bicoloring de grafo completo com 1 node deve retornar 1");
    {
        // 0
        grafo.nodes = 1;
        alocar(&grafo);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de grafo completo com 2 nodes deve retornar 1");
    {
        // 0 - 1
        grafo.nodes = 2;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de circuito com 3 nodes deve retornar 0");
    {
        //  0
        // / \
        //2 - 1
        int linha;
        grafo.nodes = 3;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 0);
        ASSERT(bicoloring(grafo) == 0);
        liberar(&grafo);
    }
    
    TEST("bicoloring de lista com 3 nodes deve retornar 1");
    {
        // 0 - 1 - 2
        grafo.nodes = 3;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de circuito com 4 nodes deve retornar 1");
    {
        // 0 - 1
        // |   |
        // 3 - 2
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 3);
        edge(&grafo, 3, 0);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de grafo completo com 4 nodes deve retornar 0");
    {
        // 0 - 1
        // | x |
        // 3 - 2
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        edge(&grafo, 1, 2);
        edge(&grafo, 1, 3);
        edge(&grafo, 2, 3);
        ASSERT(bicoloring(grafo) == 0);
        liberar(&grafo);
    }
    
    TEST("bicoloring de lista com 4 nodes deve retornar 1");
    {
        // 0 - 1 - 2 - 3
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 3);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de arvore com 4 nodes deve retornar 1");
    {
        //     0
        //   / | \
        //  1  2  3 
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de grafo com 4 nodes composto por circuito3 deve retornar 0");
    {
        //     4
        //     |
        //     0
        //   /   \
        //  1  -  3 
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        edge(&grafo, 0, 4);
        edge(&grafo, 1, 3);
        ASSERT(bicoloring(grafo) == 0);
        liberar(&grafo);
    }

    TEST("bicoloring de circuito com 5 nodes deve retornar 0");
    {
        // 1 - 2 - 3 
        // |       |
        // O - - - 4
        grafo.nodes = 5;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 3);
        edge(&grafo, 3, 4);
        edge(&grafo, 4, 0);
        ASSERT(bicoloring(grafo) == 0);
        liberar(&grafo);
    }

    TEST("bicoloring de grafo completo com 5 nodes deve retornar 0");
    {
        // 1 - 2 - 3 
        // | x x x |
        // O - - - 4
        grafo.nodes = 5;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        edge(&grafo, 0, 4);
        edge(&grafo, 1, 2);
        edge(&grafo, 1, 3);
        edge(&grafo, 1, 4);
        edge(&grafo, 2, 3);
        edge(&grafo, 2, 4);
        edge(&grafo, 3, 4);
        ASSERT(bicoloring(grafo) == 0);
        liberar(&grafo);
    }
    
    TEST("bicoloring de lista com 5 nodes deve retornar 1");
    {
        // 0 - 1 - 2 - 3 - 4
        grafo.nodes = 5;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 3);
        edge(&grafo, 3, 4);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de arvore com 5 nodes deve retornar 1");
    {
        //     1
        //     |
        // 2 - 0 - 3
        //     | 
        //     4
        grafo.nodes = 5;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        edge(&grafo, 0, 4);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de arvore de 2 niveis com 5 nodes deve retornar 1");
    {
        //     1
        //     |
        // 2 - 0 - 3
        //         | 
        //         4
        grafo.nodes = 5;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 0, 2);
        edge(&grafo, 0, 3);
        edge(&grafo, 3, 4);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    TEST("bicoloring de grafo com 5 nodes composto por circuito4 deve retornar 1");
    {
        // 4
        // |
        // 0 - 1
        // |   |
        // 3 - 2
        grafo.nodes = 4;
        alocar(&grafo);
        edge(&grafo, 0, 1);
        edge(&grafo, 1, 2);
        edge(&grafo, 2, 3);
        edge(&grafo, 3, 0);
        edge(&grafo, 4, 0);
        ASSERT(bicoloring(grafo) == 1);
        liberar(&grafo);
    }
    
    //    ASSERT_EQUALS_FLOAT(1, 1);

END_TEST()


END_TESTS()
