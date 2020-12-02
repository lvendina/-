#include <stdio.h>
#include <stdlib.h>

int degree_vertex(int** graph, int u, int vertex) {
    int degree = 0;
    for (int j = 0; j < u; j++) 
        if (graph[vertex][j] == 1)
            ++degree;
    return degree;
}

int* edges_degree_vertex(int** graph, int x, int u, int degree) {
    int* edges = (int*)malloc(u*sizeof(int));
    for (int i=0; i < u; ++i)
        edges[i] = 0;
    for (int i = 0; i < x; i++) {
        if (degree_vertex(graph, u, i) == degree) {
            for (int j = 0; j < u; j++) 
                if (graph[i][j] == 1)
                    edges[j] = 1;
        }
    }
    return edges;
}

int main()
{
    printf("Enter size x*u of the matrix:\n");
    int x, u;
    while (scanf("%d", &x) != 1 || x < 0)
        scanf("%*[^\n]");
    while (scanf("%d", &u) != 1 || u < 0)
        scanf("%*[^\n]");
    int** Graph = (int**)malloc(x*sizeof(int*));
    for (int i=0; i < x; ++i)
        Graph[i] = (int*)malloc(u*sizeof(int));

    printf("Enter matrix:\n");
    for (int i = 0; i < x; i++) 
        for (int j = 0; j < u; j++) 
            while (scanf("%d", &(Graph[i][j])) != 1 || (Graph[i][j] != 0 && Graph[i][j] != 1))
                scanf("%*[^\n]");

    int degree;
    printf("Enter degree:\n");
    scanf("%d", &degree);

    int* edges = edges_degree_vertex(Graph, x, u, degree);
    printf("Result edges:\n");
    for (int i=0; i < u; ++i)
        if (edges[i] == 1)
            printf("%d ", i);

    return 0;
} 