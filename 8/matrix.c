#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"

int main() {
    int simpleMatrix[3][3] = { {4, 7, -2}, {9, 1, 3}, {6, -3, 0} };
    int unitMatrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
    int diagonalMatrix[3][3] = { {2, 0, 0}, {0, 5, 0}, {0, 0, 9} };
    int symmetricMatrix[3][3] = { {4, -5, 8}, {-5, 5, 6}, {8, 6, 9} };
    
    printMatrix(simpleMatrix);
    isUnitMatrix(unitMatrix);
    isDiagonalMatrix(diagonalMatrix);
    isSymmetricMatrix(symmetricMatrix);

    return 0;
}

void printMatrix(int matrix[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void isUnitMatrix(int matrix[3][3])
{
    bool isUnit = true;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i==j)
            {
                if(matrix[i][j]!=1)
                    isUnit = false;
            }
            else
            {
                if(matrix[i][j]!=0)
                    isUnit = false;
            }
        }
    }
    
    if(isUnit)
        printf("This is a unit matrix\n");
    else
        printf("This isn't a unit matrix\n");
}

void isDiagonalMatrix(int matrix[3][3])
{
    bool isDiagonal = true;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i!=j && matrix[i][j]!=0)
                isDiagonal = false;
        }
    }
    
    if(isDiagonal)
        printf("This is a diagonal matrix\n");
    else
        printf("This isn't a diagonal matrix\n");
}

void isSymmetricMatrix(int matrix[3][3])
{
    bool isSymmetric = true;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix[i][j]!=matrix[j][i])
                isSymmetric = false;
        }
    }
    
    if(isSymmetric)
        printf("This is a symmetric matrix\n");
    else
        printf("This isn't a symmetric matrix\n");
}