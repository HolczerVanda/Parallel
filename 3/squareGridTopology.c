#include <stdio.h>
#include<stdlib.h>

void countNodesAndEdges(int n);

int main() {

    int n = 50;
    for(int i=0; i<=n; i++)
    {
        countNodesAndEdges(i);
    }

    return 0;
}

void countNodesAndEdges(int n)
{
    int numOfNodes = n*n;
    int numOfEdges = 2*(n*(n-1));
    printf("Number of nodes: %d\n", numOfNodes);
    printf("Number of edges: %d\n", numOfEdges);
    printf("\n");
}