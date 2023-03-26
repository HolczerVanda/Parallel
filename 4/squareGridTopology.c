#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "squareGridTopology.h"

int main() {

    int n = 50;
    countNodesAndEdges(n);

    n = 12;
    distanceDistributionPlanar(n);

    n = 24;
    spatialGrid(n);

    numberOfEdges(n);

    n = 5;
    distanceDistributionSpatial(n);

    return 0;
}

void countNodesAndEdges(int n)
{
    printf("\nPlanar grid:\n");
    printf(" N          Nodes        Edges\n");
    for(int i = 1; i <= n; i++)
    {
        int numOfNodes = i*i;
        int numOfEdges = 2*(i*(i-1));
        printf("%2d %12d %12d\n", i, numOfNodes, numOfEdges);
    }
}

void distanceDistributionPlanar(int size)
{
    int x1, y1, x2, y2, distance;
    int distances[12 * 12 * 12] = {0};
    for(x1 = 0; x1 < size; x1++) {
        for(y1 = 0; y1 < size; y1++) {
            for(x2 = x1; x2 < size; x2++) {
                for(y2 = y1; y2 < size; y2++) {
                    distance = (int)round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
                    distances[distance]++;
                }
            }
        }
    }

    printf("\nDistance distribution in %d x %d grid:\n", size, size);
    for(int i = 0; i <= 16; i++) {
        printf("%2d: ", i);
        for(int j = 0; j < distances[i]; j += 10) {
            printf("-");
        }
        printf("\n");
    }
}

void spatialGrid(int n)
{
    printf("\nSpatial grid:\n");
    printf(" N          Nodes        Edges\n");
    for(int i = 1; i <= n; i++) {
        int numOfNodes = i * i * i;
        int numOfEdges = (i - 1) * i * i * 3;
        printf("%2d %12d %12d\n", i, numOfNodes, numOfEdges);
    }
}

void numberOfEdges(int n)
{
    printf("\nDifference between number of edges:\n");
    printf(" N         Planar       Spatial\n");
    for(int i = 1; i <= n; i++) {
        int planarEdges = (i - 1) * i * 2;
        int spatialEdges = (i - 1) * i * i * 3;
        printf("%2d %12d %12d\n", i, planarEdges, spatialEdges);
    }
}

void distanceDistributionSpatial(int size)
{
    int x3, y3, z3, x4, y4, z4, distance;
    int distances[5 * 5 * 5] = {0};
    for(x3 = 0; x3 < size; x3++) {
        for(y3 = 0; y3 < size; y3++) {
            for(z3 = 0; z3 < size; z3++) {
                for(x4 = x3; x4 < size; x4++) {
                    for(y4 = y3; y4 < size; y4++) {
                        for(z4 = z3; z4 < size; z4++) {
                            distance = (int)round(sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2) + pow(z4 - z3, 2)));
                            distances[distance]++;
                        }
                    }
                }
            }
        }
    }
}