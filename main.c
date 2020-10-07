#include <stdio.h>
#include <stdlib.h>

void write_dot(const char * fname, int n, int m,  int g[n][m])
{
    FILE * fo;
    fo = fopen(fname,"wt");
    fprintf(fo, "graph Graph {\n");
    for (int j = 0; j < m; ++j)  {
        int x1 = -1;
        int x2 = -1;
        for (int i = 0; i < n; ++i) 
            if (g[i][j] == 1) {
                if  (x1 != -1)
                    x2 = i;
                else
                    x1 = i;
            }
        if (x1!=-1 && x2!=-1)
            fprintf( fo, "  %d -- %d;\n", x1+1, x2+1);
    }
    fprintf(fo, "}\n");
    fclose(fo);

    system("dot -Tpng g.dot -o g.png");
}

void check_connect(int x, int u) {
    if ((x-1)*(x-2)/2 < u)
        printf("Graph is connected");
    else
        printf("Graph is not connected");
    return; 
}

int main(void)
{
    printf("Enter size x*u of the matrix:\n");
    int x, u;
    while (scanf("%d", &x) != 1 || x < 0)
        scanf("%*[^\n]");
    while (scanf("%d", &u) != 1 || u < 0)
        scanf("%*[^\n]");
    int Graph[x][u];

    printf("Enter matrix:\n");
    for (int i = 0; i < x; i++) 
        for (int j = 0; j < u; j++) 
            while (scanf("%d", &(Graph[i][j])) != 1 || (Graph[i][j] != 0 && Graph[i][j] != 1))
                scanf("%*[^\n]");

    write_dot("g.dot", x, u, Graph);

    int conecting_x[x][x];
    for (int j = 0; j < u; ++j) {
        int x1 = -1;
        int x2 = -1;
        for (int i = 0; i < x; ++i)
            if (Graph[i][j] == 1) {
                if (x1 != -1) 
                    x2 = i;
                else
                    x1 = i;
            }
        conecting_x[x1][x2] = 1;
    }
    int real_count_u = 0;
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < x; ++j)
            if (conecting_x[i][j] == 1)
                ++real_count_u;

    printf("%d\n", real_count_u);
    check_connect(x, real_count_u);

    return 0;
} 
